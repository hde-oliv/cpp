// Copyright (C) 2022  Henrique Rocha (hde-oliv)

#include "Fixed.hpp"

#include <cmath>

Fixed::Fixed( void ) { this->fixedPoint = 0; }

Fixed::Fixed( Fixed const &ref ) { *this = ref; }

Fixed::Fixed( int const fixedPoint ) {
	this->fixedPoint = fixedPoint << this->fractionalBits;
}

Fixed::Fixed( float const fixedPoint ) {
	const int fp	 = roundf( fixedPoint * ( 1 << this->fractionalBits ) );
	this->fixedPoint = fp;
}

Fixed::~Fixed( void ) {}

Fixed &Fixed::operator=( Fixed const &ref ) {
	this->fixedPoint = ref.getRawBits();
	return ( *this );
}

bool Fixed::operator!=( Fixed const &ref ) const {
	return this->fixedPoint != ref.fixedPoint;
}

bool Fixed::operator<=( Fixed const &ref ) const {
	return this->fixedPoint <= ref.fixedPoint;
}

bool Fixed::operator>=( Fixed const &ref ) const {
	return this->fixedPoint >= ref.fixedPoint;
}

bool Fixed::operator==( Fixed const &ref ) const {
	return this->fixedPoint == ref.fixedPoint;
}

bool Fixed::operator<( Fixed const &ref ) const {
	return this->fixedPoint < ref.fixedPoint;
}

bool Fixed::operator>( Fixed const &ref ) const {
	return this->fixedPoint > ref.fixedPoint;
}

Fixed Fixed::operator+( Fixed const &ref ) const {
	Fixed newFixed;
	newFixed.setRawBits( this->fixedPoint + ref.fixedPoint );
	return Fixed( newFixed );
}

Fixed Fixed::operator-( Fixed const &ref ) const {
	Fixed newFixed;
	newFixed.setRawBits( this->fixedPoint - ref.fixedPoint );
	return Fixed( newFixed );
}

Fixed Fixed::operator*( Fixed const &ref ) const {
	float const resultValue = this->toFloat() * ref.toFloat();
	return Fixed( resultValue );
}

Fixed Fixed::operator/( Fixed const &ref ) const {
	float const resultValue = this->toFloat() / ref.toFloat();
	return Fixed( resultValue );
}

Fixed &Fixed::operator++( void ) {
	this->fixedPoint += 1;
	return ( *this );
}

Fixed &Fixed::operator--( void ) {
	this->fixedPoint -= 1;
	return ( *this );
}

Fixed Fixed::operator++( int ) {
	Fixed old( *this );
	++( *this );
	return ( old );
}

Fixed Fixed::operator--( int ) {
	Fixed old( *this );
	--( *this );
	return ( old );
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

Fixed &Fixed::min( Fixed &first, Fixed &second ) {
	return first > second ? second : first;
}

Fixed &Fixed::max( Fixed &first, Fixed &second ) {
	return first < second ? second : first;
}

Fixed const &Fixed::min( Fixed const &first, Fixed const &second ) {
	return first > second ? second : first;
}

Fixed const &Fixed::max( Fixed const &first, Fixed const &second ) {
	return first < second ? second : first;
}

const int Fixed::fractionalBits = 8;

std::ostream &operator<<( std::ostream &o, Fixed const &ref ) {
	o << ref.toFloat();
	return o;
}
