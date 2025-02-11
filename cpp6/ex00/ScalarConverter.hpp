/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pauberna <pauberna@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-02-11 16:59:46 by pauberna          #+#    #+#             */
/*   Updated: 2025-02-11 16:59:46 by pauberna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
 

#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <iostream>
# include <string>
# include <cstring>
# include <math.h>
# include <cmath>
# include <fstream>
# include <limits>

# define RESET "\033[0m"
# define GREEN "\033[1m\033[32m"
# define RED "\033[1m\033[31m"
# define YELLOW "\033[1m\033[33m"

class ScalarConverter
{
public:
	ScalarConverter();
	ScalarConverter(ScalarConverter &copy);
	virtual ~ScalarConverter() = 0;
	ScalarConverter&	operator=(ScalarConverter &copy);
	static void	convert(const std::string &input);
};

void	printSpecial(const std::string &str);
void	printChar(const std::string &str);
void	printInt(const std::string &str);
void	printFloat(const std::string &str);
void	printDouble(const std::string &str);
int		findType(const std::string &str, size_t len);
bool	checkInt(const std::string &str, size_t len);
bool	checkFloat(const std::string &str, size_t len, size_t dot);

#endif