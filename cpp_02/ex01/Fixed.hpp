#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed {
	public:
	Fixed( void );
	Fixed( Fixed const &ref );
	Fixed( int const fixedPoint );
	Fixed( float const fixedPoint );
	~Fixed( void );
	Fixed &operator=( Fixed const &ref );
	int getRawBits( void ) const;
	void setRawBits( int const raw );
	float toFloat( void ) const;
	int toInt( void ) const;

	private:
	int fixedPoint;
	static int const fractionalBits;
};

std::ostream &operator<<( std::ostream &o, Fixed const &ref );

#endif
