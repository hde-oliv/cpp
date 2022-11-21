// Copyright (C) 2022  Henrique Rocha (hde-oliv)

#include <iostream>

#include "Zombie.hpp"

Zombie *newZombie( std::string name ) { return new Zombie( name ); }
