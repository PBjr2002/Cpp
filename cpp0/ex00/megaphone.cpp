#include <iostream>

int	main(int ac, char **av)
{
	if (ac == 1)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
		return (0);
	}
	for (int n = 1; n < ac; n++)
	{
		for (int i = 0; av[n][i]; i++)
		{
			std::cout << (char)toupper(av[n][i]);
		}
	}
	std::cout << std::endl;
	return (0);
}