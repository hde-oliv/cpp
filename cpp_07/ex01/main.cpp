#include <cctype>
#include <cstring>
#include <iostream>
#include <string>

#include "iter.hpp"

void changeToA( char *ptr ) { *ptr = 'A'; }

void printAddress( int const *ptr ) { std::cout << ptr << std::endl; }

int main() {
	char c_string[]	 = "Dummy text";
	int	 int_array[] = { 1, 2, 3, 4, 5 };

	iter( c_string, 10, printIt<char> );
	std::cout << std::endl;

	iter( int_array, 5, printIt<int> );
	std::cout << std::endl;

	iter( c_string, 4, changeToA );
	std::cout << c_string << std::endl;
	std::cout << std::endl;

	iter(int_array, 5, printAddress);
	std::cout << std:: endl;
}
