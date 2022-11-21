// Copyright (C) 2022  Henrique Rocha (hde-oliv)

#include "Fixed.hpp"

#include <cmath>

Fixed::Fixed( void ) {
	std::cout << "Default constructor called" << std::endl;
	this->fixedPoint = 0;
}

Fixed::Fixed( Fixed const &ref ) {
	std::cout << "Copy constructor called" << std::endl;
	*this = ref;
}

Fixed::Fixed( int const fixedPoint ) {
	std::cout << "Int constructor called" << std::endl;
	this->fixedPoint = fixedPoint << this->fractionalBits;
}

Fixed::Fixed( float const fixedPoint ) {
	std::cout << "Float constructor called" << std::endl;
	const int fp	 = roundf( fixedPoint * ( 1 << this->fractionalBits ) );
	this->fixedPoint = fp;
}

Fixed::~Fixed( void ) { std::cout << "Destructor called" << std::endl; }

Fixed &Fixed::operator=( Fixed const &ref ) {
	std::cout << "Copy assignment operator called" << std::endl;
	this->fixedPoint = ref.getRawBits();
	return ( *this );
}

int Fixed::getRawBits( void ) const { return this->fixedPoint; }

void Fixed::setRawBits( int const raw ) { this->fixedPoint = raw; }

int Fixed::toInt( void ) const { return this->fixedPoint >> 8; }

float Fixed::toFloat( void ) const {
	float const integerPart = this->fixedPoint >> this->fractionalBits;
	float const fixedOne	= 1 << this->fractionalBits;
	float const decimalPart = ( ( this->fixedPoint & 0xFF ) / fixedOne );
	return integerPart + decimalPart;
}

const int Fixed::fractionalBits = 8;

std::ostream &operator<<( std::ostream &o, Fixed const &ref ) {
	o << ref.toFloat();
	return o;
}
