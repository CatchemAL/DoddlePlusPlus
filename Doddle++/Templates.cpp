#include <iostream>

template  <typename T>
struct Vertex
{
	T x;
	T y;
	T z;
};

template  <int N>
class StackArray
{
private:
	int array_[N];

public:
	StackArray(int a[N])
	{
		memcpy(array_, a, N * sizeof(int));
	}

	int GetSize() const
	{
		return N;
	}
};


void FunWithTemplates()
{
	const Vertex<int> int_vertex(1, 2, 3);
	const Vertex<double> float_vertex(1., 2., 3.);

	if (int_vertex.x < 2)
	{
		std::cout << "x component was " << int_vertex.x << std::endl;
	}


	if (float_vertex.x < 2)
	{
		std::cout << "x component was " << int_vertex.x << std::endl;
	}

	int open_genus_array[] = { 6,4,5,2 };
	// int array[] = { 6,4,5,2 };
	StackArray<4> stack_array(open_genus_array);
	auto size = stack_array.GetSize();
	std::cout << "Size is " << size << std::endl;
};