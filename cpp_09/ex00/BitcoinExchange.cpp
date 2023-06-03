
#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange( void ) : database() {
	std::ifstream databaseFile( "data.csv" );

	if ( !databaseFile.is_open() ) {
		std::cout << "Could not open database." << std::endl;
		throw std::exception();
	}

	std::string line;
	while ( std::getline( databaseFile, line ) ) {
		std::string date = line.substr( 0, line.find( "," ) );
		std::string rate = line.substr( line.find( "," ) + 1 );

		this->database[date] = rate;
	}

	databaseFile.close();
}

BitcoinExchange::BitcoinExchange( BitcoinExchange const &ref ) {
	this->database = ref.database;
}

BitcoinExchange::~BitcoinExchange( void ) {}

BitcoinExchange &BitcoinExchange::operator=( BitcoinExchange const &ref ) {
	this->database = ref.database;

	return *this;
}

std::string BitcoinExchange::findRate( std::string const &date ) const {
	std::string recentDate = "";
	c_iter		it		   = this->database.find( date );

	if ( it != this->database.end() ) {
		return it->second;
	} else {
		for ( cr_iter rit = this->database.rbegin();
			  rit != this->database.rend(); ++rit ) {
			if ( rit->first <= date ) {
				recentDate = rit->first;
				break;
			}
		}
		if ( recentDate == "" ) {
			return this->database.begin()->second;
		}
		return this->database.find( recentDate )->second;
	}
}
