/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pauberna <pauberna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 12:04:30 by pauberna          #+#    #+#             */
/*   Updated: 2025/01/21 12:26:51 by pauberna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : _type("WrongAnimal")
{
	std::cout<<"\033[1m\033[32mWrongAnimal Default constructor called\033[0m"<<std::endl;
}

WrongAnimal::~WrongAnimal()
{
	std::cout<<"\033[1m\033[31mWrongAnimal Destructor called\033[0m"<<std::endl;
}

WrongAnimal::WrongAnimal(WrongAnimal &copy)
{
	std::cout<<"\033[1m\033[33mWrongAnimal Copy constructor called\033[0m"<<std::endl;
	*this = copy;
}

WrongAnimal	&WrongAnimal::operator=(WrongAnimal &copy)
{
	std::cout<<"\033[1m\033[33mWrongAnimal Copy assignment operator called\033[0m"<<std::endl;
	if (this != &copy)
		_type = copy._type;
	return (*this);
}

std::string	WrongAnimal::getType() const
{
	return (_type);
}

void	WrongAnimal::makeSound() const
{
	std::cout<<"This WrongAnimal Doesnt make a sound..."<<std::endl;
}
