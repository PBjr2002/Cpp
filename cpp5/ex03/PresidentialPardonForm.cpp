/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pauberna <pauberna@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-02-05 16:27:35 by pauberna          #+#    #+#             */
/*   Updated: 2025-02-05 16:27:35 by pauberna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm("PresidentialPardonForm", 25, 5), _target("Default")
{
	std::cout<<GREEN"PresidentialPardonForm Default constructor called" RESET<<std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm("PresidentialPardonForm", 25, 5), _target(target)
{
	std::cout<<GREEN"PresidentialPardonForm Target constructor called" RESET<<std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm &copy) : AForm(copy)
{
	std::cout<<YELLOW"PresidentialPardonForm Copy constructor called" RESET<<std::endl;
	*this = copy;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
	std::cout<<RED"PresidentialPardonForm destructor called" RESET<<std::endl;
}

PresidentialPardonForm&	PresidentialPardonForm::operator=(PresidentialPardonForm &copy)
{
	std::cout<<YELLOW"PresidentialPardonForm Copy assignment operator called" RESET<<std::endl;
	if (this != &copy)
		_target = copy._target;
	return (*this);
}

void	PresidentialPardonForm::executeForm() const
{
	std::cout<<_target<<" as been pardoned by Zaphod Beeblebrox."<<std::endl;
}
