#include <cmath>
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <map>
#include <sstream>
#include <string>

#include "BitcoinExchange.hpp"

bool  validateDate( std::string const &dateString );
bool  isFloat( std::string const &str );
bool  hasPipe( std::string const &str );
float toFloat( std::string const &str );
int	  toInt( std::string const &str );

int main( int argc, char *argv[] ) {
	if ( argc != 2 ) {
		std::cout << "Missing or too much arguments." << std::endl;
		return 1;
	}

	BitcoinExchange					   btc;
	std::ifstream					   databaseFile;
	std::string						   line;
	std::map<std::string, std::string> database;

	databaseFile.open( argv[1] );

	if ( !databaseFile.is_open() ) {
		std::cout << "Could not open argument database." << std::endl;
		return 1;
	}

	while ( std::getline( databaseFile, line ) ) {
		if ( !hasPipe( line ) ) {
			std::cout << "Error: invalid line." << std::endl;
			continue;
		}

		std::string date  = line.substr( 0, line.find( " |" ) );
		std::string value = line.substr( line.find( "| " ) + 1 );

		if (line == "date | value") {
			continue;
		}

		if ( !validateDate( date ) ) {
			std::cout << "Error: invalid date." << std::endl;
			continue;
		}

		std::string rate = btc.findRate( date );

		if ( isFloat( value ) ) {
			float floatValue = toFloat( value );

			if ( floatValue < 0 || floatValue > 1000.0 ) {
				std::cout << "Error: value not in boundary." << std::endl;
				continue;
			}

			std::cout << date << " => " << floatValue << " = "
					  << toFloat( rate ) * floatValue << std::endl;
		} else {
			if ( std::atoll( value.c_str() ) > 2147483647 ||
				 std::atoll( value.c_str() ) < -2147483648 ) {
				std::cout << "Error: value not in boundary." << std::endl;
				continue;
			}

			int intValue = toInt( value );

			if ( intValue < 0 || intValue > 1000 ) {
				std::cout << "Error: value not in boundary." << std::endl;
				continue;
			}

			if ( isFloat( rate ) ) {
				std::cout << date << " => " << intValue << " = "
						  << toFloat( rate ) * intValue << std::endl;
			} else {
				std::cout << date << " => " << intValue << " = "
						  << toInt( rate ) * intValue << std::endl;
			}
		}
	}

	databaseFile.close();

	return 0;
}

bool validateDate( std::string const &dateString ) {
	std::stringstream ss( dateString );
	int				  year, month, day;
	char			  delimiter;

	if ( !( ss >> year >> delimiter >> month >> delimiter >> day ) )
		return false;

	if ( delimiter != '-' ) return false;

	for ( size_t i = 0; i < dateString.length(); i++ ) {
		if ( dateString[i] == '-' || isdigit( dateString[i] )) {
			continue;
		} else {
			return false;
		}
	}
	return true;
}

bool isFloat( std::string const &str ) {
	if ( str.find( "." ) == std::string::npos ) {
		return false;
	}
	return true;
}

bool hasPipe( std::string const &str ) {
	if ( str.find( "|" ) == std::string::npos ) {
		return false;
	}
	return true;
}

float toFloat( std::string const &str ) {
	float			  result;
	std::stringstream ss( str );

	ss >> result;
	return result;
}

int toInt( std::string const &str ) {
	int				  result;
	std::stringstream ss( str );

	ss >> result;
	return result;
}
