// Copyright (C) 2022  Henrique Rocha (hde-oliv)

#include <iostream>
#include <string>

#include "Zombie.hpp"

int main( void ) {
	std::cout << "--- Test with 10 zombies ---" << std::endl << std::endl;

	const int N		= 10;
	Zombie	 *horde = zombieHorde( N, "Naruto" );
	for ( int i = 0; i < N; i++ ) {
		horde[i].announce();
	}
	delete[] horde;

	return 0;
}
