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

# define RESET "\033[0m"
# define GREEN "\033[1m\033[32m"
# define RED "\033[1m\033[31m"
# define YELLOW "\033[1m\033[33m"

class Form
{
private:
	const std::string	_name;
	bool	_signed;
	const int	_gradeToSign;
	const int	_gradeToExecute;
public:
	Form();
	~Form();
	Form(Form &copy);
	Form	&operator=(Form &copy);
};

#endif
