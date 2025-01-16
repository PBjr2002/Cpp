#include "Zombie.hpp"

Zombie* newZombie(std::string name)
{
	Zombie	*_newZombie;

	_newZombie = new Zombie;
	_newZombie->set_name(name);
	return (_newZombie);
}
