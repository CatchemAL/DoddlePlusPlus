#include <iostream>
#include <vector>

using namespace std;

struct Vertex
{
	float x, y, z;


	Vertex(const float x, const float y, const float z)
		:x(x), y(y), z(z)
	{
	}

	Vertex(const Vertex& vertex)
		:x(vertex.x), y(vertex.y), z(vertex.z)
	{
		std::cout << "Copied " << vertex << std::endl;
	}

	friend std::ostream& operator<<(std::ostream& stream, const Vertex& vertex);
};

std::ostream& operator<<(std::ostream& stream, const Vertex& vertex)
{
	stream << "Vertex(x_=" << vertex.x << ", y=" << vertex.y << ", z=" << vertex.z << ")";
	return stream;
}

template <typename T>

void PrintVector(vector<T>& vec)
{
	for (auto i : vec)
		cout << i << ' ';
	cout << endl;
}

void MutateVector(vector<int> vec) // THIS IS NOT GOOD - MUST BE BY REFERENCE
{
	vec[2] = -7;

	PrintVector(vec);
}

void FunWithVectors()
{
	vector vec1 = { 1,2,3,4,5 };
	vector vec2 = { 3,2,3,2,3 };

	PrintVector(vec1);
	MutateVector(vec1); // This executes the vectors copy constructor
	PrintVector(vec1);

	std::vector<Vertex> vertices;
	vertices.push_back({ 1, 2, 3 });
	vertices.push_back({ 4, 5, 6 });
	vertices.push_back({ 1, 1, 1 });

	for (const Vertex vertex : vertices) // YOU DO NOT WANT TO COPY - PUT THE AMPERSAND IN!!!
		std::cout << vertex << std::endl;

	std::vector<Vertex> vertices2;
	vertices2.reserve(3);
	vertices2.emplace_back(1, 2, 3);
	vertices2.emplace_back(4, 5, 6);
	vertices2.emplace_back(1, 1, 1);

	for (const Vertex& vertex : vertices2)
		std::cout << vertex << std::endl;

}