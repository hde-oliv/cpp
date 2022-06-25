#include <iostream>
#include <string>

#include "Zombie.hpp"

int main( void ) {
	std::cout << "--- Test with newZombie ---" << std::endl << std::endl;
	Zombie *firstZombie = newZombie( "Ozzy" );
	firstZombie->announce();
	delete firstZombie;

	Zombie *secondZombie = newZombie( "Tony" );
	secondZombie->announce();
	delete secondZombie;

	std::cout << std::endl << "--- Test with randomChump ---" << std::endl << std::endl;
	randomChump( "Geezer" );
	randomChump( "Bill" );

	return 0;
}
