/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pauberna <pauberna@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-02-04 16:02:28 by pauberna          #+#    #+#             */
/*   Updated: 2025-02-04 16:02:28 by pauberna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AForm_HPP
# define AForm_HPP

# include <iostream>
# include <string>
# include <exception>
# include "Bureaucrat.hpp"

# define RESET "\033[0m"
# define GREEN "\033[1m\033[32m"
# define RED "\033[1m\033[31m"
# define YELLOW "\033[1m\033[33m"

class Bureaucrat;

class AForm
{
private:
	const std::string	_name;
	bool	_signed;
	const int	_gradeToSign;
	const int	_gradeToExecute;
public:
	AForm();
	AForm(std::string name, int gradeToSign, int gradeToExecute);
	virtual ~AForm() = 0;
	AForm(AForm &copy);
	AForm	&operator=(AForm &copy);
	const std::string	getName()const;
	bool	getSigned();
	int	getGradeToSign()const;
	int	getGradeToExecute()const;
	void	beSigned(Bureaucrat &bureaucrat);
	void	execute(Bureaucrat const & executor) const;
	virtual void	executeForm() const = 0;
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
	class	FormNotSignedException : public std::exception
	{
		public:
			virtual const char *what() const throw();
	};
};

std::ostream	&operator<<(std::ostream &out, AForm &AForm);

#endif
