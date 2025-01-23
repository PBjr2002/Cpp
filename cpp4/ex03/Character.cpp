/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pauberna <pauberna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 12:35:00 by pauberna          #+#    #+#             */
/*   Updated: 2025/01/23 15:20:50 by pauberna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character() : _name("Nobody")
{
	std::cout<<"\033[1m\033[32mCharacter Default constructor called\033[0m"<<std::endl;
	for (int i = 0; i < 4; i++)
		_inv[i] = NULL;
}

Character::Character(std::string name) : _name(name)
{
	std::cout<<"\033[1m\033[32mCharacter Name constructor called\033[0m"<<std::endl;
	for (int i = 0; i < 4; i++)
		_inv[i] = NULL;
}

Character::~Character()
{
	std::cout<<"\033[1m\033[31mCharacter Destructor called\033[0m"<<std::endl;
	for (int i = 0; i < 4; i++)
		if (_inv[i])
			delete _inv[i];
}

Character::Character(Character &copy)
{
	std::cout<<"\033[1m\033[33mCharacter Copy constructor called\033[0m"<<std::endl;
	*this = copy;
}

Character	&Character::operator=(Character &copy)
{
	std::cout<<"\033[1m\033[33mCharacter Copy assignment operator called\033[0m"<<std::endl;
	if (this != & copy)
	{
		_name = copy._name;
		for (int i = 0; i < 4; i++)
		{
			if (_inv[i])
				delete _inv[i];
			if (copy._inv[i])
				_inv[i] = copy._inv[i]->clone();
		}
	}
	return (*this);
}

std::string const	&Character::getName() const
{
	return(_name);
}

void	Character::equip(AMateria *m)
{
	if (!m)
	{
		std::cout<<"AMateria is empty"<<std::endl;
		return ;
	}
	int	i = 0;
	while (i < 4 && _inv[i])
		i++;
	if (i < 4)
	{
		_inv[i] = m;
		std::cout<<_name<<" added "<<_inv[i]->getType()<<" to the Inventory"<<std::endl;
	}
	else
		std::cout<<_name<<"->Full Inventory"<<std::endl;
}

void	Character::unequip(int idx)
{
	if (idx < 0 || idx > 4)
		std::cout<<_name<<" doesnt have a slot like that in the Inventory"<<std::endl;
	else if (!_inv[idx])
		std::cout<<_name<<" has that slot already empty"<<std::endl;
	else
	{
		std::cout<<_name<<" unquiped "<<_inv[idx]->getType()<<" from the Inventory"<<std::endl;
		_inv[idx] = NULL;
	}
}

void	Character::use(int idx, ICharacter &target)
{
	if (idx < 0 || idx > 4)
		std::cout<<_name<<" doesnt have a slot like that in the Inventory"<<std::endl;
	else if (!_inv[idx])
		std::cout<<_name<<" has nothing to use in that slot"<<std::endl;
	else
	{
		std::cout<<_name<<" > ";
		_inv[idx]->use(target);
	}
}
