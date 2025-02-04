/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pauberna <pauberna@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-02-04 10:49:36 by pauberna          #+#    #+#             */
/*   Updated: 2025-02-04 10:49:36 by pauberna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include <string>
# include <exception>

# define RESET "\033[0m"
# define GREEN "\033[1m\033[32m"
# define RED "\033[1m\033[31m"
# define YELLOW "\033[1m\033[33m"

class Bureaucrat
{
private:
	const std::string	_name;
	int	_grade;
public:
	Bureaucrat();
	Bureaucrat(const std::string name, int grade);
	~Bureaucrat();
	Bureaucrat(Bureaucrat &copy);
	Bureaucrat	&operator=(Bureaucrat &copy);
	const std::string	getName();
	int	getGrade();
	void	increment();
	void	decrement();
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

std::ostream	&operator<<(std::ostream &out, Bureaucrat &bureaucrat);

#endif