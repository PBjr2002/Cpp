/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pauberna <pauberna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 12:09:42 by pauberna          #+#    #+#             */
/*   Updated: 2025/01/23 12:40:26 by pauberna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

Cure::Cure() : AMateria("cure")
{
	std::cout<<"\033[1m\033[32mCure Default constructor called\033[0m"<<std::endl;
}

Cure::~Cure()
{
	std::cout<<"\033[1m\033[31mCure Destructor called\033[0m"<<std::endl;
}

Cure::Cure(const Cure &copy) : AMateria("cure")
{
	std::cout<<"\033[1m\033[33mCure Copy constructor called\033[0m"<<std::endl;
	*this = copy;
}

Cure	&Cure::operator=(const Cure &copy)
{
	std::cout<<"\033[1m\033[33mCure Copy assignment operator called\033[0m"<<std::endl;
	if (this != &copy)
		_type = copy._type;
	return (*this);
}

Cure	*Cure::clone() const
{
	Cure	*cloned = new Cure(*this);
	return (cloned);
}

void	Cure::use(ICharacter &target)
{
	std::cout<<"* heals "<<target.getName()<<"’s wounds *"<<std::endl;
}
