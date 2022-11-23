#include <cstdlib>
#include <iostream>

#include "Array.hpp"

#define MAX_VAL 750
int main( int, char** ) {
	std::cout << "--- pdf tests ---" << std::endl;
	{
		Array<int> numbers( MAX_VAL );
		int*	   mirror = new int[MAX_VAL];
		srand( time( NULL ) );

		for ( int i = 0; i < MAX_VAL; i++ ) {
			const int value = rand();
			numbers[i]		= value;
			mirror[i]		= value;
		}
		{
			Array<int> tmp = numbers;
			Array<int> test( tmp );
		}

		for ( int i = 0; i < MAX_VAL; i++ ) {
			if ( mirror[i] != numbers[i] ) {
				std::cerr << "didn't save the same value!!" << std::endl;
				return 1;
			}
		}

		try {
			numbers[-2] = 0;
		} catch ( const std::exception& e ) {
			std::cerr << e.what() << '\n';
		}

		try {
			numbers[MAX_VAL] = 0;
		} catch ( const std::exception& e ) {
			std::cerr << e.what() << '\n';
		}

		for ( int i = 0; i < MAX_VAL; i++ ) {
			numbers[i] = rand();
		}

		delete[] mirror;
	}
	std::cout << "--- my tests ---" << std::endl;
	{
		Array<char> chars( 75 );
		int			i;

		std::string str =
			"Grey Poupon is a brand of Dijon mustard which originated in "
			"Dijon, France.";

		for ( i = 0; i < 75; i++ ) {
			chars[i] = str[i];
		}

		for ( i = 0; i < 75; i++ ) {
			std::cout << chars[i];
		}
		std::cout << std::endl;

		Array<char> anotherOne( chars );
		for ( i = 0; i < 75; i++ ) {
			std::cout << anotherOne[i];
		}
		std::cout << std::endl;

		Array<char> secondOne( 60 );

		std::string str_2 =
			"White wine is a wine that is fermented without skin contact.";
		for ( i = 0; i < 60; i++ ) {
			secondOne[i] = str_2[i];
		}
		for ( i = 0; i < 60; i++ ) {
			std::cout << secondOne[i];
		}
		std::cout << std::endl;

		anotherOne = secondOne;

		for ( i = 0; i < 60; i++ ) {
			std::cout << anotherOne[i];
		}
		std::cout << std::endl;
	}
	return 0;
}
