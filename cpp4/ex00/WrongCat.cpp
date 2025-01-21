/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pauberna <pauberna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 12:04:40 by pauberna          #+#    #+#             */
/*   Updated: 2025/01/21 12:22:25 by pauberna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal()
{
	std::cout<<"\033[1m\033[32mWrongCat Default constructor called\033[0m"<<std::endl;
	_type = "WrongCat";
}

WrongCat::~WrongCat()
{
	std::cout<<"\033[1m\033[31mWrongCat Destructor called\033[0m"<<std::endl;
}

WrongCat::WrongCat(WrongCat &copy) : WrongAnimal(copy)
{
	std::cout<<"\033[1m\033[33mWrongCat Copy constructor called\033[0m"<<std::endl;
	*this = copy;
}

WrongCat	&WrongCat::operator=(WrongCat &copy)
{
	std::cout<<"\033[1m\033[33mWrongCat Copy assignment operator called\033[0m"<<std::endl;
	if (this != &copy)
		_type = copy._type;
	return (*this);
}

void	WrongCat::makeSound() const
{
	std::cout<<"Wrong Meeeeeooowwwww"<<std::endl;
}
