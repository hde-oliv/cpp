// Copyright (C) 2022  Henrique Rocha (hde-oliv)

#include "Weapon.hpp"

#include <string>

Weapon::Weapon( std::string type ) : type( type ) {}
Weapon::~Weapon( void ) {}

std::string const &Weapon::getType( void ) const { return this->type; }
void			   Weapon::setType( std::string type ) { this->type = type; }
