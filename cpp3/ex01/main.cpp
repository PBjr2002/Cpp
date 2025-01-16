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

#include "ScavTrap.hpp"

int	main(void)
{
	ClapTrap	clap("Bob");
	ScavTrap	scav("Boby");

	scav.guardGate();
	for (int i = 0; i < Clap_ENERGY; i++)
	{
		clap.attack(scav.getName());
	}
	clap.attack(scav.getName());
	scav.attack(clap.getName());
	return (0);
}
