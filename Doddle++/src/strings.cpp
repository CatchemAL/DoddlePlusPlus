#include <iostream>

void slow_copy(const std::string name)
{
	std::cout << "Name is: " << name << std::endl;
}

void no_copy(const std::string& name)
{
	std::cout << "Name is: " << name << std::endl;
}

void fun_with_strings()
{
	// THIS IS THE C-STYLE STRING (DON'T USE IT)
	std::cout << "Working with C-style strings ===============" << std::endl;
	const char* c_style_name = "Alex";
	std::cout << c_style_name << std::endl;
	// delete[] c_style_name;  // Rule: if you don't use the new keyword, don't use the delete keyword!

	for (int i = 0; i < 5; ++i)
	{
		const auto value = static_cast<int>(c_style_name[i]);
		std::cout << value << ", ";
	}

	std::cout << std::endl << std::endl << "Working with C++ strings ===============" << std::endl;
	const std::string cpp_name = "Alex";
	for (const char& character : cpp_name)
	{
		std::cout << character << std::endl;
	}

	// Passing the wrong way
	slow_copy(cpp_name);

	// Passing the right way
	no_copy(cpp_name);
}
