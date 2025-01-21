/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pauberna <pauberna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 14:44:52 by pauberna          #+#    #+#             */
/*   Updated: 2025/01/21 14:58:21 by pauberna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"

AAnimal::AAnimal() : _type("AAnimal")
{
	std::cout<<"\033[1m\033[32mAAnimal Default constructor called\033[0m"<<std::endl;
}

AAnimal::~AAnimal()
{
	std::cout<<"\033[1m\033[31mAAnimal Destructor called\033[0m"<<std::endl;
}

AAnimal::AAnimal(AAnimal &copy)
{
	std::cout<<"\033[1m\033[33mAAnimal Copy constructor called\033[0m"<<std::endl;
	*this = copy;
}

AAnimal	&AAnimal::operator=(AAnimal &copy)
{
	std::cout<<"\033[1m\033[33mAAnimal Copy assignment operator called\033[0m"<<std::endl;
	if (this != &copy)
		_type = copy._type;
	return (*this);
}

std::string	AAnimal::getType() const
{
	return (_type);
}
