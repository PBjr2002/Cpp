/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pauberna <pauberna@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-02-04 10:49:46 by pauberna          #+#    #+#             */
/*   Updated: 2025-02-04 10:49:46 by pauberna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name("Default"), _grade(150)
{
	std::cout<<GREEN"Bureaucrat Default constructor called" RESET<<std::endl;
}

Bureaucrat::Bureaucrat(const std::string name, int grade) : _name(name)
{
	std::cout<<GREEN"Bureaucrat Name constructor called" RESET<<std::endl;
	if (grade > 150)
		throw GradeTooLowException();
	else if (grade < 1)
		throw GradeTooHighException();
	else
		_grade = grade;
}

Bureaucrat::~Bureaucrat()
{
	std::cout<<RED"Bureaucrat destructor called" RESET<<std::endl;
}

Bureaucrat::Bureaucrat(Bureaucrat &copy)
{
	std::cout<<YELLOW"Bureaucrat Copy constructor called" RESET<<std::endl;
	*this = copy;
}

Bureaucrat	&Bureaucrat::operator=(Bureaucrat &copy)
{
	std::cout<<YELLOW"Bureaucrat Copy assignment operator called" RESET<<std::endl;
	if (this != &copy)
		_grade = copy.getGrade();
	return (*this);
}

std::ostream	&operator<<(std::ostream &out, Bureaucrat &bureaucrat)
{
	out<<bureaucrat.getName()<<", bureaucrat grade "<<bureaucrat.getGrade()<<".";
	return (out);
}

const std::string	Bureaucrat::getName()
{
	return (_name);
}

int	Bureaucrat::getGrade()
{
	return (_grade);
}

void	Bureaucrat::increment()
{
	if (_grade > 1)
		_grade--;
	else
		throw GradeTooHighException();
}

void	Bureaucrat::decrement()
{
	if (_grade < 150)
		_grade++;
	else
		throw GradeTooLowException();
}

const char	*Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("Grade too high");
}

const char	*Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("Grade too low");
}
