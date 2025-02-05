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

Form::Form() : _name("Default"), _signed(false), _gradeToSign(150), _gradeToExecute(150)
{
	std::cout<<GREEN"Form Default constructor called" RESET<<std::endl;
}

Form::Form(std::string name, int gradeToSign, int gradeToExecute) : _name(name), _signed(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute)
{
	std::cout<<GREEN"Form Default constructor called" RESET<<std::endl;
}

Form::~Form()
{
	std::cout<<RED"Form destructor called" RESET<<std::endl;
}

Form::Form(Form &copy) : _name(copy._name), _signed(copy._signed), _gradeToSign(copy._gradeToSign), _gradeToExecute(copy._gradeToExecute)
{
	std::cout<<YELLOW"Form Copy constructor called" RESET<<std::endl;
}

Form	&Form::operator=(Form &copy)
{
	std::cout<<YELLOW"Form Copy assignment operator called" RESET<<std::endl;
	if (this != &copy)
		_signed = copy._signed;
	return (*this);
}

const std::string	Form::getName()
{
	return(_name);
}

bool	Form::getSigned()
{
	return (_signed);
}

int	Form::getGradeToSign()const
{
	return (_gradeToSign);
}

int	Form::getGradeToExecute()const
{
	return (_gradeToExecute);
}

void	Form::beSigned(Bureaucrat &bureaucrat)
{
	if (bureaucrat.getGrade() <= _gradeToSign && _signed == false)
		_signed = true;
	else if (_signed == true)
		std::cout<<_name<<" is already signed ."<<std::endl;
	else
		throw GradeTooLowException();
}

std::ostream	&operator<<(std::ostream &out, Form &form)
{
	out<<form.getName()<<", form signed : "<<form.getSigned()<<std::endl;
	out<<form.getName()<<", form grade to sign : "<<form.getGradeToSign()<<std::endl;
	out<<form.getName()<<", form grade to execute : "<<form.getGradeToExecute();
	return (out);
}

const char	*Form::GradeTooHighException::what() const throw()
{
	return ("Form Grade too high");
}

const char	*Form::GradeTooLowException::what() const throw()
{
	return ("Form Grade too low");
}
