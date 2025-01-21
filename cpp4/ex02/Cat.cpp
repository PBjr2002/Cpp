/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pauberna <pauberna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 11:08:18 by pauberna          #+#    #+#             */
/*   Updated: 2025/01/21 14:53:21 by pauberna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() : AAnimal(), _brain(new Brain)
{
	std::cout<<"\033[1m\033[32mCat Default constructor called\033[0m"<<std::endl;
	_type = "Cat";
}

Cat::~Cat()
{
	std::cout<<"\033[1m\033[31mCat Destructor called\033[0m"<<std::endl;
	delete _brain;
}

Cat::Cat(Cat &copy) : AAnimal(copy)
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

void	Cat::setIdeas(std::string idea)
{
	_brain->setIdeas(idea);
}

void	Cat::printIdeas()
{
	_brain->printIdeas();
}
