/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pauberna <pauberna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 10:50:52 by pauberna          #+#    #+#             */
/*   Updated: 2025/01/21 11:58:20 by pauberna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal() : _type("Animal")
{
	std::cout<<"\033[1m\033[32mAnimal Default constructor called\033[0m"<<std::endl;
}

Animal::~Animal()
{
	std::cout<<"\033[1m\033[31mAnimal Destructor called\033[0m"<<std::endl;
}

Animal::Animal(Animal &copy)
{
	std::cout<<"\033[1m\033[33mAnimal Copy constructor called\033[0m"<<std::endl;
	*this = copy;
}

Animal	&Animal::operator=(Animal &copy)
{
	std::cout<<"\033[1m\033[33mAnimal Copy assignment operator called\033[0m"<<std::endl;
	if (this != &copy)
		_type = copy._type;
	return (*this);
}

std::string	Animal::getType() const
{
	return (_type);
}

void	Animal::makeSound() const
{
	std::cout<<"This animal doesnt make a sound..."<<std::endl;
}
