/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pauberna <pauberna@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-01-16 11:41:27 by pauberna          #+#    #+#             */
/*   Updated: 2025-01-16 11:41:27 by pauberna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : _hitPts(HP), _energyPts(ENERGY), _atackDmg(DAMAGE)
{
	std::cout<<"\033[1m\033[32mDefault constructor called\033[0m"<<std::endl;
}

ClapTrap::~ClapTrap()
{
	std::cout<<"\033[1m\033[31mDestructor called\033[0m"<<std::endl;
}

ClapTrap::ClapTrap(std::string str) : _name(str), _hitPts(HP), _energyPts(ENERGY), _atackDmg(DAMAGE)
{
	std::cout<<"\033[1m\033[32mName constructor called\033[0m"<<std::endl;
}

ClapTrap::ClapTrap(ClapTrap &copy)
{
	std::cout<<"\033[1m\033[33mCopy constructor called\033[0m"<<std::endl;
	*this = copy;
}

ClapTrap	&ClapTrap::operator=(ClapTrap &copy)
{
	std::cout<<"\033[1m\033[33mCopy assignment operator called\033[0m"<<std::endl;
	if (this != &copy)
		_name = copy.getName();
	return (*this);
}

std::string	ClapTrap::getName(void)
{
	return (_name);
}

void	ClapTrap::setName(std::string str)
{
	_name = str;
}

void	ClapTrap::attack(const std::string &target)
{
	if (_energyPts != 0)
	{
		std::cout<<"ClapTrap \033[1m\033[36m"<<_name<<" attack "<<target<<", causing "<<_atackDmg<<" points of damage!\033[0m"<<std::endl;
		_energyPts--;
	}
	else
		std::cout<<"ClapTrap \033[1m\033[33m"<<_name<<" is out of energy so cant do anything...\033[0m"<<std::endl;
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	std::cout<<"ClapTrap \033[1m\033[31m"<<_name<<" took "<<amount<<" points of damage!\033[0m"<<std::endl;
	_hitPts -= amount;
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (_energyPts != 0)
	{
		std::cout<<"ClapTrap \033[1m\033[32m"<<_name<<" repared itself gaining "<<amount<<" hit points!\033[0m"<<std::endl;
		_hitPts += amount;
		_energyPts--;
	}
	else
		std::cout<<"ClapTrap \033[1m\033[33m"<<_name<<" is out of energy so cant do anything...\033[0m"<<std::endl;
}
