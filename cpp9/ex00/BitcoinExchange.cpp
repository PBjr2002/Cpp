/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pauberna <pauberna@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-04-01 15:05:42 by pauberna          #+#    #+#             */
/*   Updated: 2025-04-01 15:05:42 by pauberna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange()
{
	std::cout<<GREEN<<"Default constructor called"<<RESET<<std::endl;
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &copy)
{
	std::cout<<YELLOW<<"Copy constructor called"<<RESET<<std::endl;
	*this = copy;
}

BitcoinExchange	&BitcoinExchange::operator=(const BitcoinExchange &copy)
{
	std::cout<<YELLOW<<"Copy assignment operator called"<<RESET<<std::endl;
	if (this != &copy)
		this->_dataBase = copy._dataBase;
	return (*this);
}

BitcoinExchange::~BitcoinExchange()
{
	std::cout<<RED<<"Destructor called"<<RESET<<std::endl;
}

void	BitcoinExchange::loadDataBaseFile()
{
	std::ifstream	file;
	std::string	name = "data.csv";
	std::string	buffer;

	file.open(name.c_str());
	if (file.is_open())
	{
		getline(file, buffer);
		while (getline(file, buffer))
			this->_dataBase[buffer.substr(0, 10)] = strtof(buffer.substr(11).c_str(), NULL);
		file.close();
	}
	else
		throw ErrorOpeningFileException();
}

int	BitcoinExchange::getYearFromDataBase(std::map<std::string, float>::iterator it)
{
	if (it == this->_dataBase.end())
		it--;
	return (atoi(it->first.substr(0, 4).c_str()));
}

int	BitcoinExchange::getMonthFromDataBase(std::map<std::string, float>::iterator it)
{
	if (it == this->_dataBase.end())
		it--;
	return (atoi(it->first.substr(5, 2).c_str()));
}

int	BitcoinExchange::getDayFromDataBase(std::map<std::string, float>::iterator it)
{
	if (it == this->_dataBase.end())
		it--;
	return (atoi(it->first.substr(8, 2).c_str()));
}

void	BitcoinExchange::checkFile(char *input)
{
	std::string	buffer;

	this->_inputFd.open(input);
	if (this->_inputFd.is_open())
	{
		getline(this->_inputFd, buffer);
		if (buffer != "date | value")
		{
			this->_inputFd.close();
			throw InvalidFormatException();
		}
		while (getline(this->_inputFd, buffer))
		{
			try
			{
				this->checkFormat(buffer);
				this->checkYear(buffer.substr(0, 4));
				this->checkMonth(buffer.substr(5, 2), atoi(buffer.substr(0, 4).c_str()));
				this->checkDay(buffer.substr(8, 2), atoi(buffer.substr(5, 2).c_str()), atoi(buffer.substr(0, 4).c_str()));
				this->checkValue(buffer.substr(13));
				this->convert(buffer.substr(0,10), strtof(buffer.substr(13).c_str(), NULL));
			}
			catch(const std::exception& e)
			{
				std::cerr << e.what() << '\n';
			}
		}
		this->_inputFd.close();
	}
	else
		throw ErrorOpeningFileException();
}

void	BitcoinExchange::checkFormat(std::string buffer)
{
	if (buffer[4] != '-' || buffer[7] != '-' || buffer.substr(10, 3) != " | " || buffer.length() < 14)
		throw BadInputException(buffer);
}

void	BitcoinExchange::checkYear(std::string year)
{
	int	nb = atoi(year.c_str());

	if (year.length() != 4 || nb < 1)
		throw BadInputException(year);
	if (nb < this->getYearFromDataBase(this->_dataBase.begin()))
		throw BadInputException(year);
}

void	BitcoinExchange::checkMonth(std::string month, int year)
{
	int	nb = atoi(month.c_str());

	if (month.length() != 2 || nb < 1 || nb > 12)
		throw BadInputException(month);
	if (year == this->getYearFromDataBase(this->_dataBase.begin()) && nb < this->getMonthFromDataBase(this->_dataBase.begin()))
		throw BadInputException(month);
}

void	BitcoinExchange::checkDay(std::string day, int month, int year)
{
	int	nb = atoi(day.c_str());

	if (day.length() < 1 || day.length() > 2 || nb < 1 || nb > 31)
		throw BadInputException(day);
	if ((month == 4 || month == 6 || month == 9 || month == 11) && nb > 30)
		throw BadInputException(day);
	if (month == 2)
	{
		bool	leapYear = (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0));
		if (!leapYear && nb > 28)
			throw BadInputException(day);
		else if (leapYear && nb > 29)
			throw BadInputException(day);
	}
	if (year == this->getYearFromDataBase(this->_dataBase.begin())
		&& month == this->getMonthFromDataBase(this->_dataBase.begin())
		&& nb < this->getDayFromDataBase(this->_dataBase.begin()))
		throw BadInputException(day);
}

void	BitcoinExchange::checkValue(std::string value)
{
	float	nb = strtof(value.c_str(), NULL);
	unsigned int len = 0;

	if (value[len] == '+')
		throw HasSignalException(value);
	else if (value[len] == '-')
		throw NegativeValueException();
	else if (value[len] == '.')
		throw BadInputException(value);
	while (len < value.length())
	{
		if (!isdigit(value[len]) && value[len] != '.')
			throw BadInputException(value);
		len++;
	}
	if (value[len - 1] == '.')
		throw BadInputException(value);
	else if (std::count(value.begin(), value.end(), '.') > 1)
		throw BadInputException(value);
	if (nb < 0)
		throw NumberTooLowException();
	else if (nb > 1000)
		throw NumberTooBigException();
}

void	BitcoinExchange::convert(std::string date, float value)
{
	std::map<std::string, float>::iterator	it;
	it = this->_dataBase.find(date);
	if (it == this->_dataBase.end())
	{
		it = this->_dataBase.upper_bound(date);
		if (it != this->_dataBase.begin())
			it--;
	}
	std::cout<<date<<" => "<<value<<" = "<<(value * it->second)<<std::endl;
}

BitcoinExchange::ErrorOpeningFileException::ErrorOpeningFileException():
std::runtime_error("Error: could not open file.") {}

BitcoinExchange::InvalidFormatException::InvalidFormatException():
std::runtime_error("Error: invalid input format") {}

BitcoinExchange::BadInputException::BadInputException(std::string buffer):
std::runtime_error("Error: bad input => " + buffer) {}

BitcoinExchange::NegativeValueException::NegativeValueException():
std::runtime_error("Error: not a positive number.") {}

BitcoinExchange::HasSignalException::HasSignalException(std::string buffer):
std::runtime_error("Error: has a \"+\" signal => " + buffer) {}

BitcoinExchange::NumberTooBigException::NumberTooBigException():
std::runtime_error("Error: too large a number.") {}

BitcoinExchange::NumberTooLowException::NumberTooLowException():
std::runtime_error("Error: too lower a number.") {}
