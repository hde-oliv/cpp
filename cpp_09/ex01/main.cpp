#include <cctype>
#include <cstdlib>
#include <iostream>
#include <sstream>
#include <stack>
#include <string>

#include "RPN.hpp"

void parseNumberOrSymbol( char const c, RPN *calculator );
void checkForSpace( char const space );
void parseFirstNumber( char const first, RPN *calculator );
void panic( std::string const &error );

int main( int argc, char *argv[] ) {
	if ( argc != 2 ) {
		std::cout << "Missing or too much arguments." << std::endl;
		return 1;
	}

	std::string expression( argv[1] );
	RPN			calculator;

	for ( size_t i = 0; i < expression.length(); i++ ) {
		if ( i == 0 ) {
			parseFirstNumber( expression[i], &calculator );
		} else if ( i % 2 == 1 ) {
			checkForSpace( expression[i] );
		} else {
			parseNumberOrSymbol( expression[i], &calculator );
		}
	}

	try {
		std::cout << calculator.getResult() << std::endl;
	} catch ( std::exception &e ) {
		panic( "Missing final symbol to calculate." );
	}
}

void parseNumberOrSymbol( char const c, RPN *calculator ) {
	if ( std::isdigit( c ) ) {
		calculator->storeNumber( c - '0' );
	} else if ( c == '-' || c == '+' || c == '/' || c == '*' ) {
		calculator->calculate( c );
	} else {
		panic( "Invalid element on notation." );
	}
}

void checkForSpace( char const space ) {
	if ( space != ' ' ) {
		panic( "Invalid spacing on notation." );
	}
}

void parseFirstNumber( char const first, RPN *calculator ) {
	if ( std::isdigit( first ) ) {
		calculator->storeNumber( first - '0' );
	} else {
		panic( "First char not a digit." );
	}
}

void panic( std::string const &error ) {
	std::cout << error << std::endl;
	exit( 1 );
}
