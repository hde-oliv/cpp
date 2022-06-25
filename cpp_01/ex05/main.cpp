#include <iostream>
#include <string>

#include "Harl.hpp"

int main( void ) {
	Harl aHarl;

	aHarl.complain( "DEBUG" );
	aHarl.complain( "INFO" );
	aHarl.complain( "WARNING" );
	aHarl.complain( "ERROR" );
	aHarl.complain( "ERRO" );
	aHarl.complain( "ERR" );
	aHarl.complain( "ER" );
	aHarl.complain( "E" );
	aHarl.complain( "" );
}
