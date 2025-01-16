/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pauberna <pauberna@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-01-16 17:24:50 by pauberna          #+#    #+#             */
/*   Updated: 2025-01-16 17:24:50 by pauberna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

# include <iostream>
# include <string>
# include <iomanip>
# include <climits>
# include "ScavTrap.hpp"

# define Frag_HP 100
# define Frag_ENERGY 100
# define Frag_DAMAGE 30

class FragTrap : public ClapTrap
{
public:
	FragTrap();
	FragTrap(std::string name);
	FragTrap(FragTrap &copy);
	FragTrap	&operator=(FragTrap &copy);
	~FragTrap();
	void		highFiveGuys(void);
	void		attack(std::string target);
};

#endif