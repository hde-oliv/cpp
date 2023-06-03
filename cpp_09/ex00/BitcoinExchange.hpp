#ifndef BITCOIN_EXCHANGE_HPP
#define BITCOIN_EXCHANGE_HPP

#include <exception>
#include <fstream>
#include <iostream>
#include <map>
#include <string>

class BitcoinExchange {
	typedef std::map<std::string, std::string>::const_reverse_iterator cr_iter;
	typedef std::map<std::string, std::string>::const_iterator		   c_iter;
	typedef std::map<std::string, std::string>						   ss_map;

	public:
	BitcoinExchange( void );
	BitcoinExchange( BitcoinExchange const &ref );
	~BitcoinExchange( void );
	BitcoinExchange &operator=( BitcoinExchange const &ref );
	std::string		 findRate( std::string const &date ) const;

	private:
	ss_map database;
};

#endif
