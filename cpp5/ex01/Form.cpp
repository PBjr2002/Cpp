/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pauberna <pauberna@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-02-04 16:02:36 by pauberna          #+#    #+#             */
/*   Updated: 2025-02-04 16:02:36 by pauberna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form()
{
	std::cout<<GREEN"Form Default constructor called" RESET<<std::endl;
}

Form::~Form()
{
	std::cout<<RED"Form destructor called" RESET<<std::endl;
}

Form::Form(Form &copy)
{
	std::cout<<YELLOW"Form Copy constructor called" RESET<<std::endl;
	*this = copy;
}

Form	&Form::operator=(Form &copy)
{
	std::cout<<YELLOW"Form Copy assignment operator called" RESET<<std::endl;
	if (this != &copy)
	{
		_name = copy._name;
		_signed = copy._signed;
		_gradeToSign = copy._gradeToSign;
		_gradeToExecute = copy._gradeToExecute;
	}
	return (*this);
}
