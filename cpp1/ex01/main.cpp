#include "Zombie.hpp"

int	main(void)
{
	Zombie	*_allocatedHorde;
	Zombie	*_allocatedHorde2;

	_allocatedHorde = zombieHorde(6, "bob");
	std::cout<<"Number of zombies created in the 1st horde: "<<"6"<<std::endl;
	std::cout<<"Name of the zombies created int the 1st horde: "<<"bob"<<std::endl;
	_allocatedHorde2 = zombieHorde(8, "harl");
	std::cout<<"Number of zombies created in the 2nd horde: "<<"8"<<std::endl;
	std::cout<<"Name of the zombies created int the 2nd horde: "<<"harl"<<std::endl;
	for (int i = 0; i < 6; i++)
	{
		_allocatedHorde[i].announce();
	}
	for (int i = 0; i < 8; i++)
	{
		_allocatedHorde2[i].announce();
	}
	delete []_allocatedHorde;
	delete []_allocatedHorde2;
	return (0);
}