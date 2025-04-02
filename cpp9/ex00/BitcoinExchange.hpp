/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pauberna <pauberna@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-04-01 15:04:58 by pauberna          #+#    #+#             */
/*   Updated: 2025-04-01 15:04:58 by pauberna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE
# define BITCOINEXCHANGE

# include <iostream>
# include <string>
# include <cstring>
# include <math.h>
# include <cmath>
# include <fstream>
# include <climits>
# include <list>
# include <vector>
# include <stack>
# include <map>
# include <algorithm>

# define RESET "\033[0m"
# define GREEN "\033[1m\033[32m"
# define RED "\033[1m\033[31m"
# define YELLOW "\033[1m\033[33m"

class BitcoinExchange
{
	private:
		std::map<std::string, float>	_dataBase;
		std::ifstream					_inputFd;
	public:
		BitcoinExchange();
		BitcoinExchange(const BitcoinExchange &copy);
		BitcoinExchange	&operator=(const BitcoinExchange &copy);
		~BitcoinExchange();
		void	loadDataBaseFile();
		int		getYearFromDataBase(std::map<std::string, float>::iterator it);
		int		getMonthFromDataBase(std::map<std::string, float>::iterator it);
		int		getDayFromDataBase(std::map<std::string, float>::iterator it);
		void	checkFile(char *input);
		void	checkFormat(std::string buffer);
		void	checkYear(std::string year);
		void	checkMonth(std::string month, int year);
		void	checkDay(std::string day, int month, int year);
		void	checkValue(std::string value);
		void	convert(std::string date, float value);
		class	ErrorOpeningFileException : public std::runtime_error
		{
			public:
				ErrorOpeningFileException();
		};
		class	InvalidFormatException : public std::runtime_error
		{
			public:
				InvalidFormatException();
		};
		class	BadInputException : public std::runtime_error
		{
			public:
				BadInputException(std::string buffer);
		};
		class	NegativeValueException : public std::runtime_error
		{
			public:
				NegativeValueException();
		};
		class	HasSignalException : public std::runtime_error
		{
			public:
				HasSignalException(std::string buffer);
		};
		class	NumberTooBigException : public std::runtime_error
		{
			public:
				NumberTooBigException();
		};
		class	NumberTooLowException : public std::runtime_error
		{
			public:
				NumberTooLowException();
		};
};

#endif
