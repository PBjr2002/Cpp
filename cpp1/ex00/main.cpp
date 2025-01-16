#include "Zombie.hpp"

int	main(void)
{
	Zombie	*_allocated;

	_allocated = newZombie("ze");
	_allocated->announce();
	randomChump("zezinho");
	delete _allocated;
	return (0);
}