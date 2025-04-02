/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pauberna <pauberna@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-04-02 14:52:47 by pauberna          #+#    #+#             */
/*   Updated: 2025-04-02 14:52:47 by pauberna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN()
{
	std::cout<<GREEN<<"Default constructor called"<<RESET<<std::endl;
}

RPN::RPN(const RPN &copy)
{
	std::cout<<YELLOW<<"Copy constructor called"<<RESET<<std::endl;
	*this = copy;
}

RPN	&RPN::operator=(const RPN &copy)
{
	std::cout<<YELLOW<<"Copy assignment operator called"<<RESET<<std::endl;
	if (this != &copy)
		this->_stack = copy._stack;
	return (*this);
}

RPN::~RPN()
{
	std::cout<<RED<<"Destructor called"<<RESET<<std::endl;
}

void	RPN::checkInput(std::string input)
{
	for (int i = 0; i < input[i]; i++)
	{
		if (!isdigit(input[i]) && input[i] != '+' && input[i] != '-' && input[i] != '/' && input[i] != '*' && input[i] != ' ')
			throw InvalidInputException();
		else if (isdigit(input[i]) && input[i + 1] && isdigit(input[i + 1]))
			throw InvalidInputException();
	}
}

void	RPN::executeRPN(std::string input)
{
	this->checkInput(input);
	for (int i = 0; input[i]; i++)
	{
		if (isspace(input[i]))
			continue ;
		else if (isdigit(input[i]))
		{
			if (input[i + 1] && input[i + 1] != ' ')
				throw InvalidFormatException();
			this->_stack.push(atof(input.substr(i, 1).c_str()));
		}
		else if (input[i] == '+' || input[i] == '-' || input[i] == '/' || input[i] == '*')
		{
			if (input[i + 1] && input[i + 1] != ' ')
				throw InvalidFormatException();
			this->makeOperation(input[i]);
		}
	}
	if (this->_stack.size() != 1)
		throw ResultImpossibleException();
	std::cout<<this->_stack.top()<<std::endl;
}

void	RPN::makeOperation(char op)
{
	float	firstNumber;
	float	secondNumber;
	float	result;

	if (this->_stack.size() < 2)
		throw OperationImpossibleException();
	secondNumber = this->_stack.top();
	this->_stack.pop();
	firstNumber = this->_stack.top();
	this->_stack.pop();
	switch (op)
	{
		case '+':
			result = firstNumber + secondNumber;
			this->_stack.push(result);
			break;
		case '-':
			result = firstNumber - secondNumber;
			this->_stack.push(result);
			break;
		case '*':
			result = firstNumber * secondNumber;
			this->_stack.push(result);
			break;
		case '/':
			result = firstNumber / secondNumber;
			this->_stack.push(result);
			break;
	}
}

RPN::InvalidInputException::InvalidInputException():
std::runtime_error("Error") {}

RPN::OperationImpossibleException::OperationImpossibleException():
std::runtime_error("Error : Too few numbers to execute the operation") {}

RPN::ResultImpossibleException::ResultImpossibleException():
std::runtime_error("Error : Too few operators to get a result") {}

RPN::InvalidFormatException::InvalidFormatException():
std::runtime_error("Error : A space is required between arguments") {}
