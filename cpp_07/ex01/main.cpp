#include <cctype>
#include <cstring>
#include <iostream>
#include <string>

#include "iter.hpp"

char toUpper( char c ) {
	if ( std::isalpha( c ) && c > 96 ) return c - 32;
	return c;
}

int raisedByFive( int i ) { return i * i * i * i * i; }

int main( void ) {
	std::cout << "-- test with c-string --" << std::endl;
	{
		char *str = new char[80];

		std::strncpy( str,
					  "One more time, we're gonna celebrate Oh yeah, alright, "
					  "don't stop the dancing",
					  78 );

		std::cout << "Before:" << std::endl;
		std::cout << "\t" << str << std::endl;
		::iter( str, 77, *toUpper );

		std::cout << std::endl;
		std::cout << "After:" << std::endl;
		std::cout << "\t" << str << std::endl;
	}
	std::cout << std::endl;
	std::cout << "-- test with int array --" << std::endl;
	{
		int *list = new int[10];

		for ( int i = 0; i < 10; i++ ) {
			list[i] = i;
		}

		std::cout << "Before:" << std::endl;
		for ( int i = 0; i < 10; i++ ) {
			std::cout << "\t" << list[i];
		}
		std::cout << std::endl;
		::iter( list, 77, *raisedByFive );

		std::cout << std::endl;
		std::cout << "After:" << std::endl;
		for ( int i = 0; i < 10; i++ ) {
			std::cout << "\t" << list[i];
		}
		std::cout << std::endl;
	}
}
