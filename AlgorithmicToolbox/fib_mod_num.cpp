#include <vector>
#include <algorithm>
#include <string>
#include <iostream>
#include "AlgorithmicToolbox.h"

int pisano_period(int m) {
	int a = 0, b = 1, c = 0;

	for (int i = 0; i <= pow(m, 2); i++)
	{
		c = (a + b) % m;
		a = b;
		b = c;

		if (a == 0 && b == 1) return i + 1;
	}
}

int fib_modulu(int n, int m) {
	if (n <= 1) return n;

	int a = 0, b = 1, c = 0;

	for (int i = 0; i < n - 1; i++)
	{
		c = (a + b) % m;
		a = b;
		b = c;
	}
	return c;
}

int fib_mod_num(long long n, int m) {
	return fib_modulu(n % pisano_period(m), m);
}
