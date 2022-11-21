// Copyright (C) 2022  Henrique Rocha (hde-oliv)

#include "Zombie.hpp"

#include <iostream>
#include <string>

Zombie::Zombie( void ) {}
Zombie::Zombie( std::string name ) : name( name ) {}
Zombie::~Zombie( void ) { std::cout << this->name << ": died." << std::endl; }

void Zombie::announce( void ) {
	std::cout << this->name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
void Zombie::setName( std::string name ) { this->name = name; }
