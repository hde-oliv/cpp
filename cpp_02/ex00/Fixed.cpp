// Copyright (C) 2022  Henrique Rocha (hde-oliv)

#include "Fixed.hpp"

Fixed::Fixed( void ) {
	std::cout << "Default constructor called" << std::endl;
	this->fixedPoint = 0;
}

Fixed::~Fixed( void ) { std::cout << "Destructor called" << std::endl; }

Fixed::Fixed( Fixed const &ref ) {
	std::cout << "Copy constructor called" << std::endl;
	*this = ref;
}

Fixed &Fixed::operator=( Fixed const &ref ) {
	std::cout << "Copy assignment operator called" << std::endl;
	this->fixedPoint = ref.getRawBits();
	return ( *this );
}

int Fixed::getRawBits( void ) const {
	std::cout << "getRawBits member function called" << std::endl;
	return this->fixedPoint;
}

void Fixed::setRawBits( int const raw ) { this->fixedPoint = raw; }

const int Fixed::fractionalBits = 8;
