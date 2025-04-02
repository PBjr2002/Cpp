/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pauberna <pauberna@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-04-02 14:52:56 by pauberna          #+#    #+#             */
/*   Updated: 2025-04-02 14:52:56 by pauberna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
# define RPN_HPP

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

class RPN
{
	private:
		std::stack<float>	_stack;
	public:
		RPN();
		RPN(const RPN &copy);
		RPN	&operator=(const RPN &copy);
		~RPN();
		void	checkInput(std::string input);
		void	executeRPN(std::string input);
		void	makeOperation(char op);
		class	InvalidInputException : public std::runtime_error
		{
			public:
				InvalidInputException();
		};
		class	OperationImpossibleException : public std::runtime_error
		{
			public:
				OperationImpossibleException();
		};
		class	ResultImpossibleException : public std::runtime_error
		{
			public:
				ResultImpossibleException();
		};
		class	InvalidFormatException : public std::runtime_error
		{
			public:
				InvalidFormatException();
		};
};

#endif
