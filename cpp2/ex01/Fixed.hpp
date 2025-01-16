/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pauberna <pauberna@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-01-14 11:23:54 by pauberna          #+#    #+#             */
/*   Updated: 2025-01-14 11:23:54 by pauberna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	FIXED_HPP
# define FIXED_HPP

# include <cmath>
# include <iostream>
# include <string>

class Fixed
{
private:
	int	_fixedPt;
	static const int	_bits = 8;
public:
	Fixed();
	Fixed(const int _value);
	Fixed(const float _value);
	Fixed(const Fixed &_copy);
	Fixed	&operator=(const Fixed &_copy);
	~Fixed();
	int	getRawBits(void)const;
	void	setRawBits(int const raw);
	float	toFloat(void)const;
	int	toInt(void)const;
};

std::ostream	&operator<<(std::ostream &_out, const Fixed &_fixed);

#endif