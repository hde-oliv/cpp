// Copyright (C) 2022  Henrique Rocha (hde-oliv)

#include "Zombie.hpp"

void randomChump( std::string name ) {
	Zombie zombie( name );
	zombie.announce();
}
