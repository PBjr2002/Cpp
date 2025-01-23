/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pauberna <pauberna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 11:36:02 by pauberna          #+#    #+#             */
/*   Updated: 2025/01/23 12:29:02 by pauberna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

Ice::Ice() : AMateria("ice")
{
	std::cout<<"\033[1m\033[32mIce Default constructor called\033[0m"<<std::endl;
}

Ice::~Ice()
{
	std::cout<<"\033[1m\033[31mIce Destructor called\033[0m"<<std::endl;
}

Ice::Ice(const Ice &copy) : AMateria("ice")
{
	std::cout<<"\033[1m\033[33mIce Copy constructor called\033[0m"<<std::endl;
	*this = copy;
}

Ice	&Ice::operator=(const Ice &copy)
{
	std::cout<<"\033[1m\033[33mIce Copy assignment operator called\033[0m"<<std::endl;
	if (this != &copy)
		_type = copy._type;
	return (*this);
}

Ice	*Ice::clone() const
{
	Ice	*cloned = new Ice(*this);
	return (cloned);
}

void	Ice::use(ICharacter &target)
{
	std::cout<<"* shoots an ice bolt at "<<target.getName()<<" *"<<std::endl;
}
