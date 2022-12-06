#include <iostream>
#include <string>
#include <tuple>

std::tuple<std::string, int> MakeThing()
{
	return {"Alex", 32};
}

void FunWithStructuredBindings()
{
	// tuple deconstruction
	auto [name, age] = MakeThing();

	std::cout << "My name is " << name << "and I am " << age << "years old.\n";
}
