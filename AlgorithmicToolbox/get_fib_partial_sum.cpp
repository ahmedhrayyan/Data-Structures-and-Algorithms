#include "AlgorithmicToolbox.h"

int get_fib_partial_sum(int from, int to) {
	int items[60] = {};
	for (int i = 0; i < 60; i++) {
		long long sum = 0;
		for (int j = from; j <= i; j++) {
			sum += fibonacci_fast(j);
		}
		items[i] = sum % 10;
	}
	return items[to % 60];
}