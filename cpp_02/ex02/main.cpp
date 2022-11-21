// Copyright (C) 2022  Henrique Rocha (hde-oliv)

#include <iostream>

#include "Fixed.hpp"

int main( void ) {
	{
		std::cout << "PDF Tests" << std::endl;
		Fixed		a;
		Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );

		std::cout << a << std::endl;
		std::cout << ++a << std::endl;
		std::cout << a << std::endl;
		std::cout << a++ << std::endl;
		std::cout << a << std::endl;

		std::cout << b << std::endl;

		std::cout << Fixed::max( a, b ) << std::endl;
	}
	{
		std::cout << std::endl;
		std::cout << "My tests" << std::endl;

		Fixed a;
		Fixed b;

		a = Fixed( 2 );
		b = Fixed( a / Fixed( 4 ) );

		std::cout << "Numbers" << std::endl;
		std::cout << a << std::endl;
		std::cout << b << std::endl;
		std::cout << std::endl;

		std::cout << "Boolean" << std::endl;
		std::cout << ( a < b ) << std::endl;
		std::cout << ( a > b ) << std::endl;
		std::cout << ( a >= b ) << std::endl;
		std::cout << ( a <= b ) << std::endl;
		std::cout << ( a != b ) << std::endl;
		std::cout << ( a == b ) << std::endl;
		std::cout << std::endl;

		std::cout << "Basic operations" << std::endl;
		std::cout << ( a + b ) << std::endl;
		std::cout << ( a - b ) << std::endl;
		std::cout << ( a * b ) << std::endl;
		std::cout << ( a / b ) << std::endl;
		std::cout << std::endl;

		Fixed c = a;
		std::cout << "Prefix/Postfix" << std::endl;
		std::cout << a << std::endl;
		std::cout << --a << std::endl;
		std::cout << a << std::endl;
		std::cout << a-- << std::endl;
		std::cout << a << std::endl;
		std::cout << std::endl;

		a = c;
		std::cout << "Min/Max" << std::endl;
		std::cout << Fixed::min( a, b ) << std::endl;
		std::cout << Fixed::max( a, b ) << std::endl;

		Fixed const d( 5 );
		Fixed const e( 9.6f );

		std::cout << Fixed::min( d, e ) << std::endl;
		std::cout << Fixed::max( d, e ) << std::endl;
	}
}
