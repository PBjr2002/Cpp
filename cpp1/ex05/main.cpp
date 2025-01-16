#include "Harl.hpp"

int	main(int ac, char **av)
{
	Harl	_harl;

	if (ac == 2)
		_harl.complain(av[1]);
	else if (ac == 1)
	{
		std::cout<<"Harl needs something to complain about"<<std::endl;
	}
	else if (ac > 2)
	{
		std::cout<<"Harl can only complain about one thing at a time"<<std::endl;
	}
	return (0);
}