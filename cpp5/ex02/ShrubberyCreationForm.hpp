/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pauberna <pauberna@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-02-05 14:35:19 by pauberna          #+#    #+#             */
/*   Updated: 2025-02-05 14:35:19 by pauberna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

# include <iostream>
# include <string>
# include <cstring>
# include <math.h>
# include <cmath>
# include <fstream>
# include <exception>
# include "AForm.hpp"


class ShrubberyCreationForm : public AForm
{
private:
	std::string	_target;
public:
	ShrubberyCreationForm();
	ShrubberyCreationForm(std::string target);
	ShrubberyCreationForm(ShrubberyCreationForm &copy);
	ShrubberyCreationForm& operator=(ShrubberyCreationForm &copy);
	~ShrubberyCreationForm();
	virtual void	executeForm() const;
	class	FileNotOpenException : public std::exception
	{
		public:
			virtual const char *what() const throw();
	};
};

#endif
