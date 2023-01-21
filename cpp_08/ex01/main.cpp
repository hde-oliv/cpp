#include <iostream>

#include "Span.hpp"

int main( void ) {
	std::cout << "--- pdf tests ---" << std::endl;
	{
		Span sp( 5 );

		sp.addNumber( 6 );
		sp.addNumber( 3 );
		sp.addNumber( 17 );
		sp.addNumber( 9 );
		sp.addNumber( 11 );

		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
	}
	std::cout << "--- test with random 100000 ---" << std::endl;
	{
		Span sp( 100000 );

		srand( time( NULL ) );
		for ( int i = 0; i < 100000; i++ ) {
			const int value = rand();
			sp.addNumber( value );
		}

		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
	}
	std::cout << "--- test with 10000 ---" << std::endl;
	{
		Span sp( 10000 );

		for ( int i = 0; i < 10000; i++ ) {
			sp.addNumber( i );
		}
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
	}
	std::cout << "--- try to add more than limit ---" << std::endl;
	{
		Span sp( 10000 );

		for ( int i = 0; i < 100000; i++ ) {
			try {
				sp.addNumber( i );
			} catch ( std::exception &e ) {
				std::cout << "exception caught on: " << i << std::endl;
				break;
			}
		}
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
	}
	std::cout << "--- test with range ---" << std::endl;
	{
		Span			 sp( 100 );
		std::vector<int> vec;

		for ( int i = 0; i < 100; i++ ) {
			vec.push_back( i );
		}

		sp.addRange( vec.begin(), vec.end() );

		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
	}
	std::cout << "--- test with big range ---" << std::endl;
	{
		Span			 sp( 100 );
		std::vector<int> vec;

		for ( int i = 0; i < 10000; i++ ) {
			vec.push_back( i );
		}

		try {
			sp.addRange( vec.begin(), vec.end() );
		} catch ( std::exception &e ) {
			std::cout << "exception caught on range." << std::endl;
		}

		try {
			std::cout << sp.shortestSpan() << std::endl;
		} catch ( std::exception &e ) {
			std::cout << "exception caught on shortest." << std::endl;
		}

		try {
			std::cout << sp.longestSpan() << std::endl;
		} catch ( std::exception &e ) {
			std::cout << "exception caught on longest." << std::endl;
		}
	}
	return 0;
}
