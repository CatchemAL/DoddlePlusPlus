#include <iostream>

class Entity
{
private:
	int x_, y_;

public:

	Entity(const int x = 0, const int y = 0)
		: x_(x), y_(y)
	{
	}


	Entity(const Entity& e) = default;


	int GetX() const
	{
		// inside a const function, this is a `const Entity*`
		const Entity* const e = this;
		return e->x_;
	}


	int GetY() const
	{
		return this->y_;
	}
};

void FunWithCopyConstructors()
{
	
	Entity entities[5]; // Will call the default constructor 5 times
	for (const auto& entity : entities)
	{
		std::cout << "Default constructor initializes to x=" << entity.GetX() << ", y=" << entity.GetY() << std::endl;
	}


	// Converting constructor (we CANNOT use the explicit keyword)
	const Entity standard(8, 2);
	std::cout << "Standard constructor give x=" << standard.GetX() << ", y=" << standard.GetY() << std::endl;


	// Converting constructor (we CANNOT use the explicit keyword)
	const Entity converting = { 1,2 };
	std::cout << "Converting constructor give x=" << converting.GetX() << ", y=" << converting.GetY() << std::endl;


	// Not sure what this is (we CAN use the explicit keyword)
	const Entity unknown{ 3,1 };
	std::cout << "Converting constructor give x=" << unknown.GetX() << ", y=" << unknown.GetY() << std::endl;


	// A copy constructor
	const Entity copied(converting);
	std::cout << "Converting constructor give x=" << copied.GetX() << ", y=" << copied.GetY() << std::endl;
}