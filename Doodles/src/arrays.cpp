#include <array>
#include <iostream>

void fun_with_arrays()
{
	int example[5]{};
	example[0] = 7;
	example[4] = 1;

	auto ptr = example;

	*(ptr += 2) = 42; // ptr <- ptr + 2*sizeof(int) = ptr + 2*4 = ptr + 8

	std::cout << std::endl << "Allocating old style arrays on the stack ===" << std::endl;
	for (const int& element : example)
		std::cout << "Value is " << element << std::endl;

	std::cout << std::endl << "Allocating old style arrays on the heap ===" << std::endl;
	const int* heap_array = new int[5]{}; // notice the size of the array is lost
	for (int i = 0; i < 5; ++i)
		std::cout << "Value is " << heap_array[i] << std::endl;
	delete[] heap_array;

	std::cout << std::endl << "Allocating new style arrays on the stack ===" << std::endl;
	std::array<int, 5> new_style{};
	new_style[2] = 4;
	for (const int element : new_style)
	{
		std::cout << "Value is " << element << std::endl;
	}


	// C++ 11 new style arrays that support range based iteration over pointers
	// because size is known
	std::cout << std::endl << "Allocating new style arrays on the heap ===" << std::endl;
	const auto heapy = new std::array<int, 5>();

	std::cout << "Count is " << heapy->size() << std::endl;
	for (const int element : *heapy)
	{
		std::cout << "Value is " << element << std::endl;
	}

}
