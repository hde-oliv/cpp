#include "PmergeMe.hpp"

bool isNumber( std::string number ) {
	for ( size_t i = 0; i < number.length(); i++ ) {
		if ( !isdigit( number[i] ) ) {
			return false;
		}
	}
	return true;
}

bool checkNumbers( char **list, int size ) {
	for ( int i = 0; i < size; i++ ) {
		std::string number( list[i] );
		if ( !isNumber( number ) ) {
			return false;
		}
		if ( std::atoll( number.c_str() ) > 2147483647 ) {
			return false;
		}
	}
	return true;
}

bool checkDuplicates( char **list, int size ) {
	for ( int i = 0; i < size; i++ ) {
		for ( int j = i + 1; j < size; j++ ) {
			std::string number1( list[i] );
			std::string number2( list[j] );
			if ( number1 == number2 ) {
				return false;
			}
		}
	}
	return true;
}

int main( int argc, char *argv[] ) {
	if ( argc < 2 ) {
		std::cout << "Error: not enough arguments." << std::endl;
		return 1;
	}
	if ( !checkNumbers( argv + 1, argc - 1 ) ) {
		std::cout << "Error: invalid arguments." << std::endl;
		return 1;
	}
	if ( !checkDuplicates( argv + 1, argc - 1 ) ) {
		std::cout << "Error: duplicate arguments." << std::endl;
		return 1;
	}

	PmergeMe p( argv + 1, argc - 1 );

	p.run();

	return 0;
}
