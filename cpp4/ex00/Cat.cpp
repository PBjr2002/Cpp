/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pauberna <pauberna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 11:08:18 by pauberna          #+#    #+#             */
/*   Updated: 2025/01/21 11:59:35 by pauberna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() : Animal()
{
	std::cout<<"\033[1m\033[32mCat Default constructor called\033[0m"<<std::endl;
	_type = "Cat";
}

Cat::~Cat()
{
	std::cout<<"\033[1m\033[31mCat Destructor called\033[0m"<<std::endl;
}

Cat::Cat(Cat &copy) : Animal(copy)
{
	std::cout<<"\033[1m\033[33mCat Copy constructor called\033[0m"<<std::endl;
	*this = copy;
}

Cat	&Cat::operator=(Cat &copy)
{
	std::cout<<"\033[1m\033[33mCat Copy assignment operator called\033[0m"<<std::endl;
	if (this != &copy)
		_type = copy._type;
	return (*this);
}

void	Cat::makeSound() const
{
	std::cout<<"Meeeeeoooooowwwwwww"<<std::endl;
}
