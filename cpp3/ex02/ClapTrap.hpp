/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pauberna <pauberna@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-01-16 11:41:39 by pauberna          #+#    #+#             */
/*   Updated: 2025-01-16 11:41:39 by pauberna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <iostream>
# include <string>
# include <iomanip>
# include <climits>

# define Clap_HP 10
# define Clap_ENERGY 10
# define Clap_DAMAGE 0

class ClapTrap
{
protected:
	std::string	_name;
	int	_hitPts;
	int	_energyPts;
	int	_atackDmg;
public:
	ClapTrap();
	ClapTrap(std::string name);
	ClapTrap(ClapTrap &copy);
	ClapTrap	&operator=(ClapTrap &copy);
	~ClapTrap();
	std::string	getName(void);
	void		setName(std::string str);
	void		attack(const std::string &target);
	void		takeDamage(unsigned int amount);
	void		beRepaired(unsigned int amount);
	void		statDump(void);
};

#endif
