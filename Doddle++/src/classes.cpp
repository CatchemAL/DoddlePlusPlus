
#include <iostream>
#include <ostream>

class player
{
public:
	int m_x, m_y;
	int m_speed;

	void accelerate() {
		m_speed++;
	}
};

std::ostream& operator << (std::ostream& outs, const player& p)
{
	return outs << "Player(m_x=" << p.m_x << ", m_y=" << p.m_y << ", m_speed=" << p.m_speed << ")";
}

static void pass_by_copy(player player)
{
	player.m_x++;
	std::cout << player << std::endl;
}

static void pass_by_reference(player& player)
{
	player.m_x++;
	std::cout << player << std::endl;
}

static void pass_by_pointer(player* player)
{
	(*player).m_x++;
	std::cout << *player << std::endl;
}


void fun_with_classes()
{
	player player1;
	player1.m_x = 5;
	player1.m_y = 8;
	player1.m_speed = 12;
	
	player player2(2, 7, 5);

	player* player3 = new player(2, 3, 15);

	player player4 = { 1, 3, 6 }; // Initializer

	std::cout << player1 << std::endl;
	std::cout << player2 << std::endl;
	std::cout << player3 << std::endl;


	std::cout << "Pass by copy" << std::endl;
	pass_by_copy(player1);
	std::cout << player1 << std::endl;

	std::cout << "Pass by reference" << std::endl;
	pass_by_reference(player1);
	std::cout << player1 << std::endl;

	std::cout << "Pass by pointer" << std::endl;
	pass_by_pointer(&player1);
	pass_by_pointer(player3);
	std::cout << player1 << std::endl;
	std::cout << *player3 << std::endl;

	std::cout << "Calling a class method" << std::endl;
	std::cout << player2 << std::endl;
	player2.accelerate();
	std::cout << player2 << std::endl;

	delete player3;
}

