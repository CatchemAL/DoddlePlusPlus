#include <iostream>

static void increment(int x)
{
	std::cout << "Increment: The value of x is: " << x << std::endl;
	x++;
	std::cout << "Increment: The value of x is: " << x << std::endl;
}

static void increment_reference(int& x)
{
	std::cout << "Increment: The value of x is: " << x << std::endl;
	x++;
	std::cout << "Increment: The value of x is: " << x << std::endl;
}

void fun_with_references()
{
	// References are basically SYMBOLIC LINKS
	// If you can get away with a reference versus a pointer, use a reference
	// as it will be a lot cleaner and simpler to read
	int a = 5;
	int& reference = a;

	std::cout << "The value of a is: " << a << std::endl;
	std::cout << "The value of reference is: " << reference << std::endl;

	reference++;

	std::cout << "The value of a is: " << a << std::endl;
	std::cout << "The value of reference is: " << reference << std::endl;

	a++;

	std::cout << "The value of a is: " << a << std::endl;
	std::cout << "The value of reference is: " << reference << std::endl;

	increment(a);

	std::cout << "The value of a is: " << a << std::endl;
	std::cout << "The value of reference is: " << reference << std::endl;

	increment_reference(a); // a itself doesn't need to be a reference - just the parameter

	std::cout << "The value of a is: " << a << std::endl;
	std::cout << "The value of reference is: " << reference << std::endl;

	increment_reference(reference);

	std::cout << "The value of a is: " << a << std::endl;
	std::cout << "The value of reference is: " << reference << std::endl;
}
