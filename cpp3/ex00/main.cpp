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

#include "ClapTrap.hpp"

int	main(void)
{
	ClapTrap	clap1("Bob");
	ClapTrap	clap2("Boby");

	for (int i = 0; i < ENERGY; i++)
	{
		clap1.attack("Boby");
		clap2.takeDamage(0);
	}
	clap1.attack("Boby");
	clap2.beRepaired(0);
	return (0);
}
