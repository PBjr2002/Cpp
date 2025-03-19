/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pauberna <pauberna@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-03-19 10:57:25 by pauberna          #+#    #+#             */
/*   Updated: 2025-03-19 10:57:25 by pauberna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

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
# include <algorithm>

# define RESET "\033[0m"
# define GREEN "\033[1m\033[32m"
# define RED "\033[1m\033[31m"
# define YELLOW "\033[1m\033[33m"

template <class T>
class MutantStack : public std::stack<T>
{
private:
	typedef std::stack<T>	_stack;
public:
	typedef typename std::deque<T>::iterator	iterator;
	typedef typename std::deque<T>::reverse_iterator	reverse;
	MutantStack()
	{
		std::cout<<GREEN<<"Deafult constructor called"<<RESET<<std::endl;
	}
	MutantStack(const MutantStack &copy) : std::stack<T>(copy)
	{
		std::cout<<YELLOW<<"Copy constructor called"<<RESET<<std::endl;
	}
	MutantStack	&operator=(const MutantStack &copy)
	{
		std::cout<<YELLOW<<"Copy assignment operator called"<<RESET<<std::endl;
		if (this != &copy)
			_stack::c = copy.c;
		return (*this);
	}
	~MutantStack()
	{
		std::cout<<RED<<"Deafult destructor called"<<RESET<<std::endl;
	}
	iterator	begin()
	{
		return (_stack::c.begin());
	}
	iterator	end()
	{
		return (_stack::c.end());
	}
	reverse		rbegin()
	{
		return (_stack::c.rbegin());
	}
	reverse		rend()
	{
		return (_stack::c.rend());
	}
};

#endif
