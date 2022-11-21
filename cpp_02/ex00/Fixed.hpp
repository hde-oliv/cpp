// Copyright (C) 2022  Henrique Rocha (hde-oliv)

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed {
	public:
	Fixed( void );
	~Fixed( void );
	Fixed( Fixed const &ref );
	Fixed &operator=( Fixed const &ref );
	int	   getRawBits( void ) const;
	void   setRawBits( int const raw );

	private:
	int				 fixedPoint;
	static int const fractionalBits;
};

#endif
