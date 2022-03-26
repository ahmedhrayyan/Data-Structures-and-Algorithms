#include <iostream>
#include <vector>
#include <limits>
#include "AlgorithmicToolbox.h";

int max_pairwise_product()
{
	int n;
	std::cin >> n;
	const int size = n;
	int max = std::numeric_limits<int>::min();
	int secondMax = std::numeric_limits<int>::min();
	for (int i = 0; i < n; i++)
	{
		int num;
		std::cin >> num;
		if (num > max)
		{
			secondMax = max;
			max = num;
		}
		else if (num > secondMax) secondMax = num;
	}

	return max * secondMax;
}