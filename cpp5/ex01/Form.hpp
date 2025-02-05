/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pauberna <pauberna@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-02-04 16:02:28 by pauberna          #+#    #+#             */
/*   Updated: 2025-02-04 16:02:28 by pauberna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>
# include <string>
# include <exception>
# include "Bureaucrat.hpp"

# define RESET "\033[0m"
# define GREEN "\033[1m\033[32m"
# define RED "\033[1m\033[31m"
# define YELLOW "\033[1m\033[33m"

class Bureaucrat;

class Form
{
private:
	const std::string	_name;
	bool	_signed;
	const int	_gradeToSign;
	const int	_gradeToExecute;
public:
	Form();
	Form(std::string name, int gradeToSign, int gradeToExecute);
	~Form();
	Form(Form &copy);
	Form	&operator=(Form &copy);
	const std::string	getName();
	bool	getSigned();
	int	getGradeToSign()const;
	int	getGradeToExecute()const;
	void	beSigned(Bureaucrat &bureaucrat);
	class	GradeTooHighException : public std::exception
	{
		public:
			virtual const char *what() const throw();
	};
	class	GradeTooLowException : public std::exception
	{
		public:
			virtual const char *what() const throw();
	};
};

std::ostream	&operator<<(std::ostream &out, Form &form);

#endif
