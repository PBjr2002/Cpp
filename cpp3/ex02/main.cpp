/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pauberna <pauberna@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-01-16 11:41:00 by pauberna          #+#    #+#             */
/*   Updated: 2025-01-16 11:41:00 by pauberna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

int	main(void)
{
	ClapTrap	clap("Bob");
	ScavTrap	scav("Boby");
	FragTrap	frag1("Harl");
	FragTrap	frag2("Karen");

	frag2.highFiveGuys();
	for (int i = 0; i < Frag_ENERGY; i++)
	{
		frag1.attack(frag2.getName());
	}
	for (int i = 0; i < Scav_ENERGY; i++)
	{
		scav.attack(frag2.getName());
	}
	for (int i = 0; i < Clap_ENERGY; i++)
	{
		clap.attack(frag2.getName());
	}
	frag1.attack(frag2.getName());
	scav.attack(frag2.getName());
	clap.attack(frag2.getName());
	frag2.attack(frag1.getName());
	frag2.attack(scav.getName());
	frag2.attack(clap.getName());
	return (0);
}
