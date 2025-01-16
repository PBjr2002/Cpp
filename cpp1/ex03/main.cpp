#include "HumanA.hpp"
#include "HumanB.hpp"

int	main(void)
{
	std::string	_weapon = "crude spiked club";
	std::string _otherWeapon = "some other type of club";
	{
		Weapon	club = Weapon(_weapon);
		HumanA	bob("Bob", club);
		bob.attack();
		club.setType(_otherWeapon);
		bob.attack();
	}
	{
		Weapon club = Weapon(_weapon);
		HumanB jim("Jim");
		jim.setWeapon(club);
		jim.attack();
		club.setType(_otherWeapon);
		jim.attack();
	}
	return (0);
}