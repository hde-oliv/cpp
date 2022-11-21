// Copyright (C) 2022  Henrique Rocha (hde-oliv)

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
	Fixed			   &operator=( Fixed const &ref );
	bool				operator>( Fixed const &ref ) const;
	bool				operator<( Fixed const &ref ) const;
	bool				operator>=( Fixed const &ref ) const;
	bool				operator<=( Fixed const &ref ) const;
	bool				operator!=( Fixed const &ref ) const;
	bool				operator==( Fixed const &ref ) const;
	Fixed				operator+( Fixed const &ref ) const;
	Fixed				operator-( Fixed const &ref ) const;
	Fixed				operator*( Fixed const &ref ) const;
	Fixed				operator/( Fixed const &ref ) const;
	Fixed			   &operator++( void );
	Fixed				operator++( int );
	Fixed			   &operator--( void );
	Fixed				operator--( int );
	static Fixed	   &min( Fixed &first, Fixed &second );
	static Fixed const &min( Fixed const &first, Fixed const &second );
	static Fixed	   &max( Fixed &first, Fixed &second );
	static Fixed const &max( Fixed const &first, Fixed const &second );
	int					getRawBits( void ) const;
	void				setRawBits( int const raw );
	float				toFloat( void ) const;
	int					toInt( void ) const;

	private:
	int				 fixedPoint;
	static int const fractionalBits;
};

std::ostream &operator<<( std::ostream &o, Fixed const &ref );

#endif
