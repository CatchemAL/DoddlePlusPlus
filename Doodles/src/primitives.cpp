#include <iostream>

using namespace std;

void display_primitive_sizes()
{
	// Primitive data types
	std::cout << std::endl << "Primitive data types ===================" << std::endl;
	std::cout << "The size of a bool    is " << sizeof(bool) << " bytes." << std::endl;
	std::cout << "The size of an int    is " << sizeof(int) << " bytes." << std::endl;
	std::cout << "The size of a float   is " << sizeof(float) << " bytes." << std::endl;
	std::cout << "The size of a double  is " << sizeof(double) << " bytes." << std::endl;
	std::cout << "The size of a char    is " << sizeof(char) << " bytes." << std::endl;

	// Pointers to primitive data types (depends on x64 vs x86...)
	std::cout << std::endl << "Pointers to primitives =================" << std::endl;
	std::cout << "The size of a bool*   is " << sizeof(bool*) << " bytes." << std::endl;
	std::cout << "The size of an int*   is " << sizeof(int*) << " bytes." << std::endl;
	std::cout << "The size of a float*  is " << sizeof(float*) << " bytes." << std::endl;
	std::cout << "The size of a double* is " << sizeof(double*) << " bytes." << std::endl;
	std::cout << "The size of a char*   is " << sizeof(char*) << " bytes." << std::endl;

	// References to primitive data types
	std::cout << std::endl << "References to primitives ===============" << std::endl;
	std::cout << "The size of a bool&   is " << sizeof(bool&) << " bytes." << std::endl;
	std::cout << "The size of an int&   is " << sizeof(int&) << " bytes." << std::endl;
	std::cout << "The size of a float&  is " << sizeof(float&) << " bytes." << std::endl;
	std::cout << "The size of a double& is " << sizeof(double&) << " bytes." << std::endl;
	std::cout << "The size of a char&   is " << sizeof(char&) << " bytes." << std::endl << std::endl;
}
