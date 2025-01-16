/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pauberna <pauberna@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-01-14 11:24:19 by pauberna          #+#    #+#             */
/*   Updated: 2025-01-14 11:24:19 by pauberna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

/* int main( void )
{
	Fixed	a;
	Fixed	const b(Fixed(5.05f) * Fixed(2));

	std::cout<<a<<std::endl;
	std::cout<<++a<<std::endl;
	std::cout<<a<<std::endl;
	std::cout<<a++<<std::endl;
	std::cout<<a<<std::endl;
	std::cout<<b<<std::endl;
	std::cout<<Fixed::max(a, b)<<std::endl;
	return (0);
} */

int main( void )
{
	Fixed a;
	Fixed c;
	Fixed d;
	Fixed const b(Fixed(5.05f) * Fixed(2));

	c = 10;
	d = 19.10f;
	std::cout<<a<<std::endl;
	std::cout<<++a<<std::endl;
	std::cout<<a<<std::endl;
	std::cout<<a++<<std::endl;
	std::cout<<a<<std::endl;
	std::cout<<b<<std::endl;
	std::cout<<Fixed::max( a, b )<<std::endl;
	std::cout<<Fixed::min( d, c )<<std::endl;
	std::cout<<d + c<<std::endl;
	std::cout<<d - c<<std::endl;
	std::cout<<d * c<<std::endl;
	std::cout<<d / c<<std::endl;
	return (0);
}
