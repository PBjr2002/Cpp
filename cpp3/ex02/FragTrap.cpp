/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pauberna <pauberna@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-01-16 17:24:38 by pauberna          #+#    #+#             */
/*   Updated: 2025-01-16 17:24:38 by pauberna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap()
{
	statDump();
	std::cout<<"\033[1m\033[32mFrag Default constructor called\033[0m"<<std::endl;
	_hitPts = Frag_HP;
	_energyPts = Frag_ENERGY;
	_atackDmg = Frag_DAMAGE;
	statDump();
}

FragTrap::~FragTrap()
{
	std::cout<<"\033[1m\033[31mFrag Destructor called\033[0m"<<std::endl;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
	statDump();
	std::cout<<"\033[1m\033[32mFrag Name constructor called\033[0m"<<std::endl;
	_hitPts = Frag_HP;
	_energyPts = Frag_ENERGY;
	_atackDmg = Frag_DAMAGE;
	statDump();
}

FragTrap::FragTrap(FragTrap &copy) : ClapTrap(copy._name)
{
	std::cout<<"\033[1m\033[33mFrag Copy constructor called\033[0m"<<std::endl;
	*this = copy;
}

FragTrap	&FragTrap::operator=(FragTrap &copy)
{
	std::cout<<"\033[1m\033[33mFrag Copy assignment operator called\033[0m"<<std::endl;
	if (this != &copy)
	{
		_hitPts = copy._hitPts;
		_energyPts = copy._energyPts;
		_atackDmg = copy._atackDmg;
	}
	return (*this);
}

void	FragTrap::attack(std::string target)
{
	if (_energyPts != 0)
	{
		std::cout<<"FragTrap \033[1m\033[36m"<<_name<<" attack "<<target<<", causing "<<_atackDmg<<" points of damage!\033[0m"<<std::endl;
		_energyPts--;
	}
	else
		std::cout<<"FragTrap \033[1m\033[33m"<<_name<<" is out of energy so cant do anything...\033[0m"<<std::endl;
}

void	FragTrap::highFiveGuys(void)
{
	if (_energyPts != 0)
	{
		std::cout<<"FragTrap \033[1m\033[33m"<<_name<<" is requesting a positive high five!\033[0m"<<std::endl;
		_energyPts--;
	}
	else
		std::cout<<"FragTrap \033[1m\033[33m"<<_name<<" is out of energy so cant do anything...\033[0m"<<std::endl;
}
