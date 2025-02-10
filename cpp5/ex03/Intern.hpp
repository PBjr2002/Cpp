/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pauberna <pauberna@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-02-06 14:31:02 by pauberna          #+#    #+#             */
/*   Updated: 2025-02-06 14:31:02 by pauberna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	INTERN_HPP
# define INTERN_HPP

# include <iostream>
# include <string>
# include <cstring>
# include <math.h>
# include <cmath>
# include <fstream>
# include "AForm.hpp"
# include "ShrubberyCreationForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "PresidentialPardonForm.hpp"

class Intern
{
public:
	Intern();
	Intern(Intern &copy);
	Intern& operator=(Intern &copy);
	~Intern();
	AForm	*makeForm(std::string name, std::string target);
};

#endif
