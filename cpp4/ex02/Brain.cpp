/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pauberna <pauberna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 13:23:38 by pauberna          #+#    #+#             */
/*   Updated: 2025/01/21 14:02:12 by pauberna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain()
{
	std::cout<<"\033[1m\033[32mBrain Default constructor called\033[0m"<<std::endl;
	for (int i = 0; i < NUM; i++)
	{
		_ideas[i] = "No idea just empty brain";
	}
}

Brain::~Brain()
{
	std::cout<<"\033[1m\033[31mBrain Destructor called\033[0m"<<std::endl;
}

Brain::Brain(Brain &copy)
{
	std::cout<<"\033[1m\033[33mBrain Copy constructor called\033[0m"<<std::endl;
	*this = copy;
}

Brain	&Brain::operator=(Brain &copy)
{
	std::cout<<"\033[1m\033[33mBrain Copy assignment operator called\033[0m"<<std::endl;
	if (this != &copy)
	{
		for (int i = 0; i < NUM; i++)
		{
			_ideas[i] = copy._ideas[i];
		}
	}
	return (*this);
}

void	Brain::setIdeas(std::string idea)
{
	for (int i = 0; i < NUM; i++)
	{
		_ideas[i] = idea;
	}
}

void	Brain::printIdeas()
{
	for (int i = 0; i < NUM; i++)
	{
		std::cout<<_ideas[i]<<std::endl;
	}
}
