// Copyright (C) 2022  Henrique Rocha (hde-oliv)

#include <cctype>
#include <iostream>

void printStringInUppercase( std::string string ) {
	for ( int i = 0; i < (int)string.size(); i++ ) {
		std::cout << (char)toupper( string[i] );
	}
}

int main( int argc, char *argv[] ) {
	if ( argc == 1 )
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	else {
		for ( int i = 1; i < argc; i++ ) {
			std::string temp = argv[i];
			printStringInUppercase( temp );
		}
		std::cout << std::endl;
	}
	return 0;
}
