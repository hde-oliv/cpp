// Copyright (C) 2022  Henrique Rocha (hde-oliv)

#include "FragTrap.hpp"

#include <iostream>

FragTrap::FragTrap( void ) : ClapTrap() {
	this->attackDamage = 30;
	this->energyPoints = 100;
	this->hitPoints	   = 100;
	std::cout << "FragTrap default constructor called." << std::endl;
}

FragTrap::FragTrap( std::string const &name ) : ClapTrap( name ) {
	this->attackDamage = 30;
	this->energyPoints = 100;
	this->hitPoints	   = 100;
	std::cout << "FragTrap parametric constructor called." << std::endl;
}

FragTrap::FragTrap( FragTrap const &ref ) : ClapTrap( ref ) {
	std::cout << "FragTrap copy constructor called." << std::endl;
}

FragTrap::~FragTrap( void ) {
	std::cout << "FragTrap destructor called." << std::endl;
}

FragTrap &FragTrap::operator=( FragTrap const &ref ) {
	this->attackDamage = ref.attackDamage;
	this->energyPoints = ref.energyPoints;
	this->hitPoints	   = ref.hitPoints;
	this->name		   = ref.name;
	std::cout << "FragTrap copy assignment called." << std::endl;
	return ( *this );
}

void FragTrap::attack( const std::string &target ) {
	if ( this->hitPoints && this->energyPoints ) {
		std::cout << "FragTrap ";
		std::cout << this->name;
		std::cout << " attacks ";
		std::cout << target;
		std::cout << ", causing ";
		std::cout << this->attackDamage;
		std::cout << " points of damage!" << std::endl;
		this->energyPoints--;
	}
}

void FragTrap::highFivesGuys( void ) {
	std::cout << "FragTrap ";
	std::cout << this->name;
	std::cout << " says: \'Let\'s do a high five!\'." << std::endl;
}
