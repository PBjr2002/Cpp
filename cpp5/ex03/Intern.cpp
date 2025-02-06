/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pauberna <pauberna@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-02-06 14:30:58 by pauberna          #+#    #+#             */
/*   Updated: 2025-02-06 14:30:58 by pauberna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern()
{
	std::cout<<GREEN"Intern Default constructor called" RESET<<std::endl;
}

Intern::Intern(Intern &copy)
{
	std::cout<<YELLOW"Intern Copy constructor called" RESET<<std::endl;
	*this = copy;
}

Intern::~Intern()
{
	std::cout<<RED"Intern destructor called" RESET<<std::endl;
}

Intern	&Intern::operator=(Intern &copy)
{
	std::cout<<YELLOW"Intern Copy assignment operator called" RESET<<std::endl;
	(void)copy;
	return (*this);
}

AForm	*Intern::makeForm(std::string name, std::string target)
{
	std::string	forms[] = {"ShrubberyCreationForm", "RobotomyRequestForm", "PresidentialPardonForm"};
	int	n = 0;
	while (n < 3 && name != forms[n])
	{
		n++;
	}

	switch (n)
	{
	case 0:
	{
		std::cout<<"Creating ShrubberyCreationForm"<<std::endl;
		return (new ShrubberyCreationForm(target));
	}
	case 1:
	{
		std::cout<<"Creating RobotomyRequestForm"<<std::endl;
		return (new RobotomyRequestForm(target));
	}
	case 2:
	{
		std::cout<<"Creating PresidentialPardonForm"<<std::endl;
		return (new PresidentialPardonForm(target));
	}
	default:
		std::cout<<"That form doesnt exist"<<std::endl;
		break;
	}
	return (NULL);
}
