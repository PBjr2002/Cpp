/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pauberna <pauberna@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-02-04 16:02:36 by pauberna          #+#    #+#             */
/*   Updated: 2025-02-04 16:02:36 by pauberna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm() : _name("Default"), _signed(false), _gradeToSign(150), _gradeToExecute(150)
{
	std::cout<<GREEN"AForm Default constructor called" RESET<<std::endl;
}

AForm::AForm(std::string name, int gradeToSign, int gradeToExecute) : _name(name), _signed(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute)
{
	std::cout<<GREEN"AForm constructor called" RESET<<std::endl;
}

AForm::~AForm()
{
	std::cout<<RED"AForm destructor called" RESET<<std::endl;
}

AForm::AForm(AForm &copy) : _name(copy._name), _signed(copy._signed), _gradeToSign(copy._gradeToSign), _gradeToExecute(copy._gradeToExecute)
{
	std::cout<<YELLOW"AForm Copy constructor called" RESET<<std::endl;
}

AForm	&AForm::operator=(AForm &copy)
{
	std::cout<<YELLOW"AForm Copy assignment operator called" RESET<<std::endl;
	if (this != &copy)
		_signed = copy._signed;
	return (*this);
}

const std::string	AForm::getName()const
{
	return(_name);
}

bool	AForm::getSigned()
{
	return (_signed);
}

int	AForm::getGradeToSign()const
{
	return (_gradeToSign);
}

int	AForm::getGradeToExecute()const
{
	return (_gradeToExecute);
}

void	AForm::beSigned(Bureaucrat &bureaucrat)
{
	if (bureaucrat.getGrade() <= _gradeToSign && _signed == false)
		_signed = true;
	else if (_signed == true)
		std::cout<<_name<<" is already signed ."<<std::endl;
	else
		throw GradeTooLowException();
}

void	AForm::execute(Bureaucrat const &executor) const
{
	if (_signed == false)
		throw FormNotSignedException();
	else if (executor.getGrade() > _gradeToExecute)
		throw GradeTooLowException();
	else
		executeForm();
}

std::ostream	&operator<<(std::ostream &out, AForm &form)
{
	out<<form.getName()<<", signed : "<<form.getSigned()<<std::endl;
	out<<form.getName()<<", grade to sign : "<<form.getGradeToSign()<<std::endl;
	out<<form.getName()<<", grade to execute : "<<form.getGradeToExecute();
	return (out);
}

const char	*AForm::GradeTooHighException::what() const throw()
{
	return ("AForm Grade too high");
}

const char	*AForm::GradeTooLowException::what() const throw()
{
	return ("AForm Grade too low");
}

const char	*AForm::FormNotSignedException::what() const throw()
{
	return (RED"AForm is not signed therefore cannot be executed"RESET);
}
