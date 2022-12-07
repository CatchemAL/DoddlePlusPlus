#include <vector>
#include <functional>


std::vector<int> Select(const std::vector<int>& vec, const std::function<int(int)>& func)
{
	std::vector<int> result;
	result.reserve(vec.size());

	for (const int value : vec)
	{
		auto output = func(value);
		result.push_back(output);
	}

	return result;
}

void FunWithLambdas()
{
	const std::vector values = { 2,5,4,6,45,2,5,245 };

	auto my_lambda = [](const int value) { return value * value; };

	auto mapped = Select(values, my_lambda);
}