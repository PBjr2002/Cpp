/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pauberna <pauberna@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-02-10 14:21:56 by pauberna          #+#    #+#             */
/*   Updated: 2025-02-10 14:21:56 by pauberna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"


ScalarConverter::ScalarConverter()
{
	std::cout<<GREEN"ScalarConverter Default constructor called" RESET<<std::endl;
}

ScalarConverter::ScalarConverter(ScalarConverter &copy)
{
	std::cout<<YELLOW"ScalarConverter Copy constructor called" RESET<<std::endl;
	*this = copy;
}

ScalarConverter::~ScalarConverter()
{
	std::cout<<RED"ScalarConverter destructor called" RESET<<std::endl;
}

ScalarConverter&	ScalarConverter::operator=(ScalarConverter &copy)
{
	std::cout<<YELLOW"ScalarConverter Copy assignment operator called" RESET<<std::endl;
	(void) copy;
	return (*this);
}

void	ScalarConverter::convert(const std::string &input)
{
	size_t	len = input.length();
	int	type = findType(input, len);
	switch (type)
	{
	case (0):
		printSpecial(input);
		break;
	case (1):
		printInt(input);
		break;
	case (2):
		printChar(input);
		break;
	case (3):
		printDouble(input);
		break;
	case (4):
		printFloat(input);
		break;
	default:
		std::cout<<RED<<"Invalid Input"<<RESET<<std::endl;
		break;
	}
}

void	printSpecial(const std::string &str)
{
	if (str == "nan" || str == "nanf")
	{
		std::cout<<"char: impossible"<<std::endl;
		std::cout<<"int: impossible"<<std::endl;
		std::cout<<"float: nanf"<<std::endl;
		std::cout<<"double: nan"<<std::endl;
	}
	else if (str == "+inf" || str == "+inff")
	{
		std::cout<<"char: impossible"<<std::endl;
		std::cout<<"int: impossible"<<std::endl;
		std::cout<<"float: +inff"<<std::endl;
		std::cout<<"double: +inf"<<std::endl;
	}
	else if (str == "-inf" || str == "-inff")
	{
		std::cout<<"char: impossible"<<std::endl;
		std::cout<<"int: impossible"<<std::endl;
		std::cout<<"float: -inff"<<std::endl;
		std::cout<<"double: -inf"<<std::endl;
	}
}

void	printChar(const std::string &str)
{
	char	c;

	if (!str[1])
		c = str[0];
	else
		c = str[1];
	std::cout<<"char: ";
	if (isprint(c))
		std::cout<<"'"<<c<<"'"<<std::endl;
	else
		std::cout<<"Not displayable"<<std::endl;
	std::cout<<"int: "<<static_cast<int>(c)<<std::endl;
	std::cout<<"float: "<<static_cast<float>(c)<<".0f"<<std::endl;
	std::cout<<"double: "<<static_cast<double>(c)<<".0"<<std::endl;
}

void	printInt(const std::string &str)
{
	long	number = atol(str.c_str());

	if (number < 0 || number > 127)
		std::cout<<"char: impossible"<<std::endl;
	else if (!isprint(number))
		std::cout<<"char: Not displayable"<<std::endl;
	else
		std::cout<<"char: "<<"'"<<static_cast<char>(number)<<"'"<<std::endl;
	if (number < std::numeric_limits<int>::min() || number > std::numeric_limits<int>::max())
		std::cout<<"int: impossible"<<std::endl;
	else
		std::cout<<"int: "<<static_cast<int>(number)<<std::endl;
	std::cout<<"float: "<<static_cast<float>(number)<<".0f"<<std::endl;
	std::cout<<"double: "<<static_cast<double>(number)<<".0"<<std::endl;
}

void	printFloat(const std::string &str)
{
	float	number = atof(str.c_str());
	bool	decimalPart = fabs(number - static_cast<int>(number)) < 0.0000000000001;

	//char
	if (number < 0 || number > 127)
		std::cout<<"char: impossible"<<std::endl;
	else if (!isprint(number))
		std::cout<<"char: Not displayable"<<std::endl;
	else
		std::cout<<"char: "<<"'"<<static_cast<char>(number)<<"'"<<std::endl;

	//int
	if (number < std::numeric_limits<int>::min() || number > std::numeric_limits<int>::max())
		std::cout<<"int: impossible"<<std::endl;
	else
		std::cout<<"int: "<<static_cast<int>(number)<<std::endl;

	//float
	if (number < std::numeric_limits<float>::min() || number > std::numeric_limits<float>::max())
		std::cout<<"float: impossible"<<std::endl;
	else if (decimalPart == false)
		std::cout<<"float: "<<number<<"f"<<std::endl;
	else
		std::cout<<"float: "<<number<<".0f"<<std::endl;

	//double
	if (decimalPart == false)
		std::cout<<"double: "<<static_cast<double>(number)<<std::endl;
	else
		std::cout<<"double: "<<static_cast<double>(number)<<".0"<<std::endl;
}

void	printDouble(const std::string &str)
{
	double	number = atof(str.c_str());
	bool	decimalPart = fabs(number - static_cast<int>(number)) < 0.0000000000001;

	//char
	if (number < 0 || number > 127)
		std::cout<<"char: impossible"<<std::endl;
	else if (!isprint(number))
		std::cout<<"char: Not displayable"<<std::endl;
	else
		std::cout<<"char: "<<"'"<<static_cast<char>(number)<<"'"<<std::endl;

	//int
	if (number < std::numeric_limits<int>::min() || number > std::numeric_limits<int>::max())
		std::cout<<"int: impossible"<<std::endl;
	else
		std::cout<<"int: "<<static_cast<int>(number)<<std::endl;

	//float
	if (number < std::numeric_limits<float>::min() || number > std::numeric_limits<float>::max())
		std::cout<<"float: impossible"<<std::endl;
	else if (decimalPart == false)
		std::cout<<"float: "<<static_cast<float>(number)<<"f"<<std::endl;
	else
		std::cout<<"float: "<<static_cast<float>(number)<<".0f"<<std::endl;

	//double
	if (number < std::numeric_limits<double>::min() || number > std::numeric_limits<double>::max())
		std::cout<<"double: impossible"<<std::endl;
	else if (decimalPart == false)
		std::cout<<"double: "<<number<<std::endl;
	else
		std::cout<<"double: "<<number<<".0"<<std::endl;
}
