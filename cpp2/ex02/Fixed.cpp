/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pauberna <pauberna@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-01-14 11:24:09 by pauberna          #+#    #+#             */
/*   Updated: 2025-01-14 11:24:09 by pauberna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

//Constructors
Fixed::Fixed()
{
	std::cout<<"\033[1m\033[32mDefault constructor called\033[0m"<<std::endl;
	_fixedPt = 0;
}

Fixed::Fixed(const int _value)
{
	std::cout<<"\033[1m\033[32mInt constructor called\033[0m"<<std::endl;
	_fixedPt = _value << _bits;
}

Fixed::Fixed(const float _value)
{
	std::cout<<"\033[1m\033[32mFloat constructor called\033[0m"<<std::endl;
	_fixedPt = (int)roundf(_value * (1<<_bits));
}

//Destructor
Fixed::~Fixed()
{
	std::cout<<"\033[1m\033[31mDestructor called\033[0m"<<std::endl;
}

//Copy operators
Fixed::Fixed(const Fixed &_copy)
{
	std::cout<<"\033[1m\033[33mCopy constructor called\033[0m"<<std::endl;
	*this = _copy;
}

Fixed	&Fixed::operator=(const Fixed &_copy)
{
	std::cout<<"\033[1m\033[33mCopy assignment operator called\033[0m"<<std::endl;
	if (this != &_copy)
		_fixedPt = _copy.getRawBits();
	return *this;
}

int	Fixed::getRawBits(void)const
{
	std::cout<<"getRawBits member function called"<<std::endl;
	return (_fixedPt);
}

void	Fixed::setRawBits(int const raw)
{
	_fixedPt = raw;
}

//Comparison Operators
bool	Fixed::operator>(const Fixed &_fixed)const
{
	return (getRawBits() > _fixed.getRawBits());
}

bool	Fixed::operator<(const Fixed &_fixed)const
{
	return (getRawBits() < _fixed.getRawBits());
}

bool	Fixed::operator>=(const Fixed &_fixed)const
{
	return (getRawBits() >= _fixed.getRawBits());
}

bool	Fixed::operator<=(const Fixed &_fixed)const
{
	return (getRawBits() <= _fixed.getRawBits());
}

bool	Fixed::operator==(const Fixed &_fixed)const
{
	return (getRawBits() == _fixed.getRawBits());
}

bool	Fixed::operator!=(const Fixed &_fixed)const
{
	return (getRawBits() != _fixed.getRawBits());
}

//Arithmetic Operators

Fixed	Fixed::operator+(const Fixed &_fixed)const
{
	Fixed	_result;

	_result.setRawBits(getRawBits() + _fixed.getRawBits());
	return (_result);
}

Fixed	Fixed::operator-(const Fixed &_fixed)const
{
	Fixed	_result;

	_result.setRawBits(getRawBits() - _fixed.getRawBits());
	return (_result);
}

Fixed	Fixed::operator*(const Fixed &_fixed)const
{
	Fixed	_result;

	_result.setRawBits((getRawBits() * _fixed.getRawBits())>>_bits);
	return (_result);
}

Fixed	Fixed::operator/(const Fixed &_fixed)const
{
	Fixed	_result;

	_result.setRawBits((getRawBits()<<_bits) / _fixed.getRawBits());
	return (_result);
}

//Increment Operators

//++_fixedPT
Fixed	&Fixed::operator++()
{
	_fixedPt++;
	return (*this);
}

//--_fixedPT
Fixed	&Fixed::operator--()
{
	_fixedPt--;
	return (*this);
}

//_fixedPT++
Fixed	Fixed::operator++(int)
{
	Fixed	_result = *this;
	this->_fixedPt++;
	return (_result);
}

//_fixedPT--
Fixed	Fixed::operator--(int)
{
	Fixed	_result = *this;
	this->_fixedPt--;
	return (_result);
}

//other
const Fixed	&Fixed::min(const Fixed &_fixed1, const Fixed &_fixed2)
{
	if (_fixed1 < _fixed2)
		return (_fixed1);
	return (_fixed2);
}

Fixed	&Fixed::min(Fixed &_fixed1, Fixed &_fixed2)
{
	if (_fixed1 < _fixed2)
		return (_fixed1);
	return (_fixed2);
}

const Fixed	&Fixed::max(const Fixed &_fixed1, const Fixed &_fixed2)
{
	if (_fixed1 > _fixed2)
		return (_fixed1);
	return (_fixed2);
}

Fixed	&Fixed::max(Fixed &_fixed1, Fixed &_fixed2)
{
	if (_fixed1 > _fixed2)
		return (_fixed1);
	return (_fixed2);
}

std::ostream	&operator<<(std::ostream &_out, const Fixed &_fixed)
{
	_out<<_fixed.toFloat();
	return (_out);
}

float	Fixed::toFloat(void)const
{
	return ((float)_fixedPt / (float)(1<<_bits));
}

int	Fixed::toInt(void)const
{
	return ((int)_fixedPt>>_bits);
}
