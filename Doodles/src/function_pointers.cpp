
#include <iostream>
#include <string>
#include <vector>


void SayHello(int number)
{
	std::cout << "The number is " << number << std::endl;
}

void Map(const std::vector<int>* vec, void(* const f)(int))
{
	for (const int element : *vec)
	{
		f(element);
	}
}

template <typename TIn, typename TOut>
std::vector<TOut> Select(const std::vector<TIn>& vec, TOut(* selector)(const TIn))
{
	std::vector<TOut> result;
	result.reserve(vec.size());
	for (const auto& element : vec)
	{
		auto response = selector(element);
		result.push_back(response);
	}

	return result;
}



int Func(const int n)
{
	return n * 2;
}

std::size_t Func2(const std::string n)
{
	return n.length();
}

void FunWithFunctionPointers()
{
	const auto function = SayHello;

	function(3);
	function(4);
	function(5);

	const std::vector some_vec = { 3,5,7,9 };
	const std::vector<std::string> words = { "ALPHA","BETA","GAMMA","RHO" };

	Map(&some_vec, SayHello);

	

	auto mapped = Select(some_vec, Func);
	for (auto iterator = mapped.begin(); iterator != mapped.end(); ++iterator)
		std::cout << *iterator << std::endl;

	const auto mapped2 = Select(words, Func2);
	for (const auto element : mapped2)
		std::cout << element << std::endl;
}
