/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pauberna <pauberna@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-03-17 12:58:41 by pauberna          #+#    #+#             */
/*   Updated: 2025-03-17 12:58:41 by pauberna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <iostream>
# include <string>
# include <cstring>
# include <math.h>
# include <cmath>
# include <fstream>

# define RESET "\033[0m"
# define GREEN "\033[1m\033[32m"
# define RED "\033[1m\033[31m"
# define YELLOW "\033[1m\033[33m"

template<typename T>
class Array
{
	private:
		T	*_array;
		unsigned int	_size;
	public:
		Array();
		Array(unsigned int size);
		Array(const Array &copy);
		Array	&operator=(const Array &copy);
		T	&operator[](unsigned int index);
		~Array();
		int	size();
		class	InvalidIndexException : public std::exception
		{
		public:
			virtual const char	*what() const throw();
		};
};

template<typename T>
Array<T>::Array() : _size(0)
{
	std::cout<<GREEN<<"Default constructor called"<<RESET<<std::endl;
	_array = new T[_size];
}

template<typename T>
Array<T>::Array(unsigned int size) : _size(size)
{
	std::cout<<GREEN<<"Constructor with size called"<<RESET<<std::endl;
	_array = new T[_size];
}

template<typename T>
Array<T>::Array(const Array &copy)
{
	std::cout<<YELLOW<<"Copy constructor called"<<RESET<<std::endl;
	_array = NULL;
	*this = copy;
}

template<typename T>
Array<T>	&Array<T>::operator=(const Array &copy)
{
	std::cout<<YELLOW<<"Copy assignment operator called"<<RESET<<std::endl;
	if (this != &copy)
	{
		_size = copy._size;
		if (_array != NULL)
			delete [] _array;
		if (copy._size != 0)
		{
			_array = new T[_size];
			for (unsigned int i = 0; i < _size; i++)
			{
				_array[i] = copy._array[i];
			}
		}
	}
	return (*this);
}

template<typename T>
T	&Array<T>::operator[](unsigned int index)
{
	if (!_array || index >= _size)
	{
		throw Array<T>::InvalidIndexException();
	}
	return (_array[index]);
}

template<typename T>
Array<T>::~Array()
{
	std::cout<<RED<<"Default destructor called"<<RESET<<std::endl;
	delete [] _array;
}

template<typename T>
int	Array<T>::size()
{
	return (_size);
}

template< typename T >
const char	*Array<T>::InvalidIndexException::what() const throw()
{
	return ("Invalid index");
}

#endif
