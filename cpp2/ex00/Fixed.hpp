#ifndef	FIXED_HPP
# define FIXED_HPP

# include <cmath>
# include <iostream>
# include <string>
# include <iomanip>
# include <climits>

class Fixed
{
private:
	int	_fixedPt;
	static const int	_bits = 8;
public:
	Fixed();
	Fixed(const Fixed &_copy);
	Fixed	&operator=(const Fixed &_copy);
	~Fixed();
	int	getRawBits(void)const;
	void	setRawBits(int const raw);
};

#endif