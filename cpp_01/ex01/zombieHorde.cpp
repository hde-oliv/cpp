// Copyright (C) 2022  Henrique Rocha (hde-oliv)

#include "Zombie.hpp"

Zombie *zombieHorde( int N, std::string name ) {
	Zombie *zombieArray = new Zombie[N];
	for ( int i = 0; i < N; i++ ) {
		zombieArray[i].setName( name );
	}
	return zombieArray;
}
