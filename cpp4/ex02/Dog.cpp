/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pauberna <pauberna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 11:07:55 by pauberna          #+#    #+#             */
/*   Updated: 2025/01/21 14:53:34 by pauberna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() : AAnimal(), _brain(new Brain)
{
	std::cout<<"\033[1m\033[32mDog Default constructor called\033[0m"<<std::endl;
	_type = "Dog";
}

Dog::~Dog()
{
	std::cout<<"\033[1m\033[31mDog Destructor called\033[0m"<<std::endl;
	delete _brain;
}

Dog::Dog(Dog &copy) : AAnimal(copy)
{
	std::cout<<"\033[1m\033[33mDog Copy constructor called\033[0m"<<std::endl;
	*this = copy;
}

Dog	&Dog::operator=(Dog &copy)
{
	std::cout<<"\033[1m\033[33mDog Copy assignment operator called\033[0m"<<std::endl;
	if (this != &copy)
		_type = copy._type;
	return (*this);
}

void	Dog::makeSound() const
{
	std::cout<<"Woof Woof"<<std::endl;
}

void	Dog::setIdeas(std::string idea)
{
	_brain->setIdeas(idea);
}

void	Dog::printIdeas()
{
	_brain->printIdeas();
}
