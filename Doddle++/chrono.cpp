#include <algorithm>
#include <iostream>
#include <vector>

void PrintVec(const std::vector<int>& vec)
{
	for (const int element : vec)
		std::cout << element << std::endl;
}

void FunWithSorting()
{
	std::vector<int> some_vec = {1,4,3,6,7,43,2,4,345,26,234,4};

	std::ranges::sort(some_vec, [](const int a, const int b)
	{
		if (a == 1 || b == 1)
			return b == 1;
		return a < b;
	});

	PrintVec(some_vec);
}