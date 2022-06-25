#include <cctype>
#include <iostream>

void printStringInUppercase( std::string string ) {
	for ( int i = 0; i < (int)string.size(); i++ ) {
		char temp = toupper( string[i] );
		if ( !std::isspace( temp ) ) std::cout << temp;
	}
}

int main( int argc, char *argv[] ) {
	if ( argc == 1 )
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	else {
		for ( int i = 1; i < argc; i++ ) {
			std::string temp = argv[i];
			printStringInUppercase( temp );
			std::cout << " ";
		}
		std::cout << std::endl;
	}
	return 0;
}
