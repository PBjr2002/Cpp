/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pauberna <pauberna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 11:19:29 by pauberna          #+#    #+#             */
/*   Updated: 2025/01/23 15:08:54 by pauberna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria() : _type("AMateria")
{
	std::cout<<"\033[1m\033[32mAMateria Default constructor called\033[0m"<<std::endl;
}

AMateria::AMateria(std::string const &type) : _type(type)
{
	std::cout<<"\033[1m\033[32mAMateria Type constructor called\033[0m"<<std::endl;
}

AMateria::~AMateria()
{
	std::cout<<"\033[1m\033[31mAMateria Destructor called\033[0m"<<std::endl;
}

AMateria::AMateria(AMateria &copy)
{
	std::cout<<"\033[1m\033[33mAMateria Copy constructor called\033[0m"<<std::endl;
	*this = copy;
}

AMateria	&AMateria::operator=(AMateria &copy)
{
	std::cout<<"\033[1m\033[33mAMateria Copy assignment operator called\033[0m"<<std::endl;
	if (this != &copy)
		_type = copy._type;
	return (*this);
}

std::string const	&AMateria::getType() const
{
	return (_type);
}

void	AMateria::use(ICharacter &target)
{
	std::cout<<"Nothing to use against "<<target.getName()<<std::endl;
}
