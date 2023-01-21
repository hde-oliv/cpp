#include <deque>
#include <exception>
#include <iostream>
#include <vector>

#include "easyfind.hpp"

int main( void ) {
	std::cout << "--- vector tests ---" << std::endl;
	{
		std::vector<int> listy;
		listy.push_back( 10 );
		listy.push_back( 8 );
		listy.push_back( 3 );
		listy.push_back( 5 );
		listy.push_back( 9 );

		std::vector<int>::iterator iter1 = easyfind( listy, 10 );
		std::cout << "Found: " << *iter1 << std::endl;

		std::vector<int>::iterator iter2 = easyfind( listy, 8 );
		std::cout << "Found: " << *iter2 << std::endl;

		try {
			std::vector<int>::iterator iter3 = easyfind( listy, 11 );
			std::cout << "Found: " << *iter3 << std::endl;
		} catch ( std::exception &e ) {
			std::cout << "Caught exception trying to find 11." << std::endl;
		}
	}
	std::cout << std::endl;

	std::cout << "--- deque tests ---" << std::endl;
	{
		std::deque<int> queuey;

		queuey.push_back( 10 );
		queuey.push_back( 8 );
		queuey.push_back( 3 );
		queuey.push_back( 5 );
		queuey.push_back( 9 );

		std::deque<int>::iterator iter1 = easyfind( queuey, 10 );
		std::cout << "Found: " << *iter1 << std::endl;

		std::deque<int>::iterator iter2 = easyfind( queuey, 8 );
		std::cout << "Found: " << *iter2 << std::endl;

		try {
			std::deque<int>::iterator iter3 = easyfind( queuey, 11 );
			std::cout << "Found: " << *iter3 << std::endl;
		} catch ( std::exception &e ) {
			std::cout << "Caught exception trying to find 11." << std::endl;
		}
	}
}
