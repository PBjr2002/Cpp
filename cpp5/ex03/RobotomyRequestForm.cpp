/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pauberna <pauberna@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-02-05 14:41:43 by pauberna          #+#    #+#             */
/*   Updated: 2025-02-05 14:41:43 by pauberna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyRequestForm", 72, 45), _target("Default")
{
	std::cout<<GREEN"RobotomyRequestForm Default constructor called" RESET<<std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("RobotomyRequestForm", 72, 45), _target(target)
{
	std::cout<<GREEN"RobotomyRequestForm Target constructor called" RESET<<std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm &copy) : AForm(copy)
{
	std::cout<<YELLOW"RobotomyRequestForm Copy constructor called" RESET<<std::endl;
	*this = copy;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	std::cout<<RED"RobotomyRequestForm destructor called" RESET<<std::endl;
}

RobotomyRequestForm	&RobotomyRequestForm::operator=(RobotomyRequestForm &copy)
{
	std::cout<<YELLOW"RobotomyRequestForm Copy assignment operator called" RESET<<std::endl;
	if (this != &copy)
		_target = copy._target;
	return (*this);
}

void	RobotomyRequestForm::executeForm() const
{
	int	randomNumber = rand() % 2;
	std::cout<<YELLOW"Drilling noise..."RESET<<std::endl;
	if (randomNumber == 1)
		std::cout<<GREEN<<_target<<" has been Robotomized successufuly!"RESET<<std::endl;
	else
		throw RobotomyFailedException();
}

const char	*RobotomyRequestForm::RobotomyFailedException::what() const throw()
{
	return (RED"Robotomy Failed, oops"RESET);
}
