﻿/*Sum of Fibonacci Numbers
The goal in this problem is to find the last digit of a sum of the first 𝑛 Fibonacci numbers.
Task. Given an integer 𝑛, find the last digit of the sum 𝐹0 + 𝐹1 + · · · + 𝐹𝑛.
Input Format. The input consists of a single integer 𝑛.
Constraints. 0 ≤ 𝑛 ≤ 1018
Output Format. Output the last digit of 𝐹0 + 𝐹1 + · · · + 𝐹𝑛.
Time limit: 1 sec
Memory limit: 512 MB
Results: max time used: 0.00/1.00, max memory used: 8577024/536870912
*/

#include <iostream>
long long fib_mod(long long num, long long m);
long long get_fibonaccihuge(long long n, long long m);
int fibonacci_sum(long long n);

int main() {
	long long n = 0;
	std::cin >> n;
	std::cout << fibonacci_sum(n) << std::endl;
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

int fibonacci_sum(long long n) {
	long long num = n + 2;
	long long rest = get_fibonaccihuge(num, 10);
	if (rest == 0) return 9;
	else return rest - 1;
}
