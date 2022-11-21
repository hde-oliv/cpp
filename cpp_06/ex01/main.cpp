#include <stdint.h>

#include <cctype>
#include <cmath>
#include <cstdlib>
#include <iostream>
#include <string>

#include "Data.hpp"

uintptr_t serialize( Data *ptr ) { return reinterpret_cast<uintptr_t>( ptr ); }

Data *deserialize( uintptr_t raw ) { return reinterpret_cast<Data *>( raw ); }

int main( void ) {
	Data *someone = new Data( "John" );

	uintptr_t ptr = serialize( someone );

	std::cout << someone->getName() << std::endl;

	someone = deserialize( ptr );

	std::cout << someone->getName() << std::endl;

	return 0;
}
