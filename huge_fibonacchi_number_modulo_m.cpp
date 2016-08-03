/*Huge Fibonacci Number modulo m
In this problem, your goal is to compute 𝐹𝑛 modulo 𝑚, where 𝑛 may be really huge: up to 10^18. 
Task. Given two integers 𝑛 and 𝑚, output 𝐹𝑛 mod 𝑚 (that is, the remainder of 𝐹𝑛 when divided by 𝑚).
Input Format. The input consists of two integers 𝑛 and 𝑚 given on the same line (separated by a space).
Constraints. 1 ≤ 𝑛 ≤ 10^18, 2 ≤ 𝑚 ≤ 10^5
Output Format. Output 𝐹𝑛 mod 𝑚.
Time limit: 1 sec
Memory limit: 512 MB
Results: max time used: 0.00/1.00, max memory used: 30261248/536870912
*/

#include <iostream>
long long fib_mod(long long num, long long m);
long long get_fibonaccihuge(long long n, long long m);

int main() {
	long long n, m;
	std::cin >> n >> m;
	std::cout << get_fibonaccihuge(n, m) << '\n';
}

long long get_fibonaccihuge(long long n, long long m) {
	long long first = 0 % m, second = 1 % m, temp;
	long long period, rest;
	for (long long k = 1; k <= m*m - 1; k++) {
		temp = first;
		first = second;
		second = (temp + first) % m;
		period = k;
		if (first == 0 && second == 1) break;
	}
	rest = n;
	while (rest >= period) {
		rest %= period;
	}
	long long res = fib_mod(rest, m);
	return res;
}

long long fib_mod(long long num, long long m)
{
	long long a = 1, b = 1, c = 1, d = 0, 
		ta, tb, 
		rc = 0 % m, tc,rd = 1 % m;

	while (num)
	{
		if (num & 1)
		{
			tc = rc;
			rc = (rc*a + rd*c) % m;
			rd = (tc*b + rd*d) % m;
		}

		ta = a; tb = b; tc = c;
		a = (a*a + b*c) % m;
		b = (ta*b + b*d) % m;
		c = (c*ta + d*c) % m;
		d = (tc*tb + d*d) % m;

		num >>= 1;

	}

	return rc;
}

