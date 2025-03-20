/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pauberna <pauberna@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-03-18 14:16:41 by pauberna          #+#    #+#             */
/*   Updated: 2025-03-18 14:16:41 by pauberna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

# include <iostream>
# include <string>
# include <cstring>
# include <math.h>
# include <cmath>
# include <fstream>
# include <climits>
# include <list>
# include <vector>
# include <algorithm>

# define RESET "\033[0m"
# define GREEN "\033[1m\033[32m"
# define RED "\033[1m\033[31m"
# define YELLOW "\033[1m\033[33m"

class Span
{
	private:
		std::vector<int>	_vector;
		unsigned int	_size;
		Span();
	public:
		Span(unsigned int N);
		Span(const Span &copy);
		Span	&operator=(const Span &copy);
		~Span();
		void	addNumber(int number);
		void	fillSpan();
		unsigned int		shortestSpan() const;
		unsigned int		longestSpan() const;

		class	VectorFullException : public std::exception
		{
			public:
				virtual const char	*what() const throw()
				{
					return ("Vector is already full");
				}
		};
		class	VectorEmptyException : public std::exception
		{
			public:
				virtual const char	*what() const throw()
				{
					return ("Vector is empty");
				}
		};
};

#endif