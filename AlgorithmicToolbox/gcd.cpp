#include "AlgorithmicToolbox.h";

int gcd(int a, int b) {
	if (b == 0) return a;
	int remainder = a % b;
	return gcd(b, remainder);
}