/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pauberna <pauberna@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-01-16 14:25:45 by pauberna          #+#    #+#             */
/*   Updated: 2025-01-16 14:25:45 by pauberna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap()
{
	statDump();
	std::cout<<"\033[1m\033[32mScav Default constructor called\033[0m"<<std::endl;
	_hitPts = Scav_HP;
	_energyPts = Scav_ENERGY;
	_atackDmg = Scav_DAMAGE;
	statDump();
}

ScavTrap::~ScavTrap()
{
	std::cout<<"\033[1m\033[31mScav Destructor called\033[0m"<<std::endl;
}

ScavTrap::ScavTrap(std::string str) : ClapTrap(str)
{
	statDump();
	std::cout<<"\033[1m\033[32mScav Name constructor called\033[0m"<<std::endl;
	_hitPts = Scav_HP;
	_energyPts = Scav_ENERGY;
	_atackDmg = Scav_DAMAGE;
	statDump();
}

ScavTrap::ScavTrap(ScavTrap &copy) : ClapTrap(copy._name)
{
	std::cout<<"\033[1m\033[33mScav Copy constructor called\033[0m"<<std::endl;
	*this = copy;
}

ScavTrap	&ScavTrap::operator=(ScavTrap &copy)
{
	std::cout<<"\033[1m\033[33mScav Copy assignment operator called\033[0m"<<std::endl;
	if (this != &copy)
	{
		_hitPts = copy._hitPts;
		_energyPts = copy._energyPts;
		_atackDmg = copy._atackDmg;
	}
	return (*this);
}

void	ScavTrap::attack(std::string target)
{
	if (_energyPts != 0)
	{
		std::cout<<"ScavTrap \033[1m\033[36m"<<_name<<" attack "<<target<<", causing "<<_atackDmg<<" points of damage!\033[0m"<<std::endl;
		_energyPts--;
	}
	else
		std::cout<<"ScavTrap \033[1m\033[33m"<<_name<<" is out of energy so cant do anything...\033[0m"<<std::endl;
}

void	ScavTrap::guardGate()
{
	if (_energyPts != 0)
	{
		std::cout<<"ScavTrap \033[1m\033[33m"<<_name<<" is now in Gate keeper mode!\033[0m"<<std::endl;
		_energyPts--;
	}
	else
		std::cout<<"ScavTrap \033[1m\033[33m"<<_name<<" is out of energy so cant do anything...\033[0m"<<std::endl;
}
