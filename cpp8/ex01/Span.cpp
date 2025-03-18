/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pauberna <pauberna@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-03-18 14:16:33 by pauberna          #+#    #+#             */
/*   Updated: 2025-03-18 14:16:33 by pauberna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span() : _size(0)
{
	std::cout<<GREEN<<"Deafult constructor called"<<RESET<<std::endl;
}

Span::Span(unsigned int N) : _size(N)
{
	std::cout<<GREEN<<"Maximum Integers constructor called"<<RESET<<std::endl;
	_vector.reserve(_size);
}

Span::Span(const Span &copy)
{
	std::cout<<YELLOW<<"Copy constructor called"<<RESET<<std::endl;
	*this = copy;
}

Span	&Span::operator=(const Span &copy)
{
	std::cout<<YELLOW<<"Copy assignment operator called"<<RESET<<std::endl;
	if (this != &copy)
	{
		_vector = copy._vector;
		_size = copy._size;
	}
	return (*this);
}

Span::~Span()
{
	std::cout<<RED<<"Deafult destructor called"<<RESET<<std::endl;
}

void	Span::addNumber(int number)
{
	if (_vector.size() == _vector.capacity())
		throw (VectorFullException());
	_vector.push_back(number);
}

void	Span::fillSpan()
{
	int	random_number;
	unsigned int iterator = 0;

	while (iterator != _size)
	{
		random_number = rand();
		try
		{
			addNumber(random_number);
			std::cout<<"Adding "<<random_number<<" to Span"<<std::endl;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
		iterator++;
	}
}

unsigned int	Span::shortestSpan() const
{
	if (_vector.size() == 0)
		throw (VectorEmptyException());
	std::vector<int>	tmp(_vector);
	unsigned int	rest = UINT_MAX;
	std::sort(tmp.begin(), tmp.end());

	std::vector<int>::iterator	iterator =  tmp.begin();
	std::vector<int>::iterator	next_iterator = tmp.begin() + 1;
	while (next_iterator != tmp.end())
	{
		if (rest > (unsigned int)(*next_iterator - *iterator))
			rest = *next_iterator - *iterator;
		next_iterator++;
		iterator++;
	}
	if (rest == UINT_MAX)
		return (0);
	return (rest);
}

unsigned int	Span::longestSpan() const
{
	if (_vector.size() == 0)
		throw (VectorEmptyException());
	std::vector<int>	tmp(_vector);
	std::sort(tmp.begin(), tmp.end());

	std::vector<int>::iterator	iterator =  tmp.begin();
	std::vector<int>::iterator	max_iterator = tmp.end() - 1;
	return (*max_iterator - *iterator);
}

