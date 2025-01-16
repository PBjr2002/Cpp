/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScaveTrap.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pauberna <pauberna@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-01-16 14:25:56 by pauberna          #+#    #+#             */
/*   Updated: 2025-01-16 14:25:56 by pauberna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include <iostream>
# include <string>
# include <iomanip>
# include <climits>
# include "ClapTrap.hpp"

# define Scav_HP 100
# define Scav_ENERGY 50
# define Scav_DAMAGE 20

class ScavTrap : public ClapTrap
{
public:
	ScavTrap();
	ScavTrap(std::string _name);
	~ScavTrap();
	ScavTrap(ScavTrap &_copy);
	ScavTrap	&operator=(ScavTrap &_copy);
	void	attack(std::string target);
	void	guardGate();
};

#endif