#include <iostream>
#include "AlgorithmicToolbox.h"

int last_fib_sum_num(int n) {
	int items[60] = {};
	for (int i = 0; i < 60; i++) {
		long long sum = 0;
		for (int j = 0; j <= i; j++) {
			sum += fibonacci_fast(j);
		}
		items[i] = sum % 10;
	}
	return items[n % 60];
}