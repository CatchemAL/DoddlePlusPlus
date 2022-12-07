

#include <iostream>

class Weapon
{
protected:
	int ammo_capacity_;
	int ammo_count_;

public:
	explicit Weapon(const int ammo_capacity)
	{
		ammo_capacity_ = ammo_capacity;
		ammo_count_ = ammo_capacity;
	}

	virtual void fire() = 0;

	virtual void reload() // this goes badly wrong without virtual!
	{
		ammo_count_ = ammo_capacity_;
	}
};

class RayGun final : public Weapon
{
	static constexpr int capacity_ = 5;

public:
	explicit RayGun()
		: Weapon(capacity_)
	{
	}

	void fire() override
	{
		if (ammo_count_ > 0)
		{
			std::cout << "Ray Gun goes pew pew" << std::endl;
			ammo_count_--;
		}
		else
		{
			std::cout << "Click. Need to reload..." << std::endl;
		}
	}

	void reload() override
	{
		std::cout << "Recharging Kill-O-Watt ammo..." << std::endl;
		Weapon::reload();
	}
};

void fun_with_virtual()
{
	Weapon* w = new RayGun();
	for (int i = 0; i < 7; ++i)
	{
		w->fire();
	}

	w->reload();
}