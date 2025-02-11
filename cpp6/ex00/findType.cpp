/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   findType.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pauberna <pauberna@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-02-11 11:52:52 by pauberna          #+#    #+#             */
/*   Updated: 2025-02-11 11:52:52 by pauberna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

bool	checkInt(const std::string &str, size_t len)
{
	size_t	n = 0;
	bool	signal = false;
	if (str[n] == '-' || str[n] == '+')
	{
		signal = true;
		n++;
	}
	while (n < len)
	{
		if (!isdigit(str[n]))
			break ;
		n++;
	}
	if (n == len && ((signal == true && len < 11) || (signal == false && len < 10)))
		return (true);
	return (false);
}

bool	checkFloat(const std::string &str, size_t len, size_t dot)
{
	size_t	n = 0;
	bool	signal = false;
	if (str[n] == '-' || str[n] == '+')
	{
		signal = true;
		n++;
	}
	while (n < dot)
	{
		if (!isdigit(str[n]))
			break ;
		n++;
	}
	if (n != dot)
		return (false);
	n++;
	while (n < len)
	{
		if (!isdigit(str[n]))
			break ;
		n++;
	}
	if (str[n] == 'f' && !str[n + 1])
		return (true);
	return (false);
}

int	findType(const std::string &str, size_t len)
{
	size_t	dot = str.find('.');
	size_t	f = str.find('f');

	if (len == 0)
		return (-1);
	if (dot == std::string::npos)
	{
		//special
		if (str == "-inff" || str == "+inff" || str == "-inf" || str == "+inf" || str == "nan" || str == "nanf")
			return (0);
		//int
		if(checkInt(str, len) == true)
			return (1);
		//char
		if ((len == 1 && !isdigit(str[0])) || (len == 3 && str[0] == '\'' && str[2] == '\''))
			return (2);
	}
	else if (dot != std::string::npos && f == std::string::npos)
	{
		//double
		return (3);
	}
	else if (dot != std::string::npos && f != std::string::npos)
	{
		//float
		if (checkFloat(str, len, dot) == true)
			return (4);
	}
	return (-1);
}
