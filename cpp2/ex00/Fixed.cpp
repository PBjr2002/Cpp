#include "Fixed.hpp"

Fixed::Fixed()
{
	std::cout<<"\033[1m\033[32mDefault constructor called\033[0m"<<std::endl;
	_fixedPt = 0;
}

Fixed::~Fixed()
{
	std::cout<<"\033[1m\033[31mDestructor called\033[0m"<<std::endl;
}

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
