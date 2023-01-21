#include <cctype>
#include <cmath>
#include <cstdlib>
#include <iostream>
#include <string>

std::string INFINITE_LITERALS[] = { "-inff", "+inff", "nanf", "-inf", "+inf", "nan", "inf", "inff" };

std::string LIMITS[] = { "-2147483648", "2147483647" };

void toChar( double input ) {
	if ( input < 32 ) {
		std::cout << "char: Non printable character." << std::endl;
		return;
	} else if ( input > 255 ) {
		std::cout << "char: impossible." << std::endl;
		return;
	}

	char toPrint = static_cast<char>( input );
	std::cout << "char: "
			  << "'" << toPrint << "'" << std::endl;
}

void toChar( int input ) {
	if ( input < 32 ) {
		std::cout << "char: Non printable character." << std::endl;
		return;
	} else if ( input > 255 ) {
		std::cout << "char: impossible." << std::endl;
		return;
	}

	char toPrint = static_cast<char>( input );
	std::cout << "char: " << toPrint << std::endl;
}

void toDouble( double input ) { std::cout << "double: " << input << std::endl; }

void toFloat( double input ) {
	float toPrint = static_cast<float>( input );

	if ( toPrint == floor( toPrint ) ) {
		std::cout << "float: " << toPrint << ".0f" << std::endl;
	} else {
		std::cout << "float: " << toPrint << "f" << std::endl;
	}
}

void toInt( double input ) {
	int toPrint = static_cast<int>( input );
	std::cout << "int: " << toPrint << std::endl;
}

void handleInfiniteLiterals( std::string literal ) {
	double convertedInput = std::atof( literal.c_str() );

	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;
	std::cout << "float: " << convertedInput << "f" << std::endl;
	std::cout << "double: " << convertedInput << std::endl;
}

void handleLimits( std::string limit ) {
	double convertedInput = std::atof( limit.c_str() );

	std::cout << "char: impossible." << std::endl;
	std::cout << "int: impossible." << std::endl;
	std::cout << "float: " << convertedInput << "f" << std::endl;
	std::cout << "double: " << convertedInput << std::endl;
}

int main( int argc, char *argv[] ) {
	if ( argc != 2 ) {
		return 1;
	}

	std::string input( argv[1] );

	for ( int i = 0; i < 8; i++ ) {
		if ( !input.compare( INFINITE_LITERALS[i] ) ) {
			handleInfiniteLiterals( INFINITE_LITERALS[i] );
			return 0;
		}
	}

	if ( std::atoll( input.c_str() ) > 2147483647 || std::atoll( input.c_str() ) < -2147483648 ) {
		handleLimits( input );
		return 0;
	}

	double convertedInput;
	if ( input.length() == 1 && !std::isdigit( input.c_str()[0] ) ) {
		convertedInput = static_cast<int>( input.c_str()[0] );
	} else {
		convertedInput = std::atof( input.c_str() );
	}

	toChar( convertedInput );
	toInt( convertedInput );
	toFloat( convertedInput );
	toDouble( convertedInput );
	return 0;
}
