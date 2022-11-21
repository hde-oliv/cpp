// Copyright (C) 2022  Henrique Rocha (hde-oliv)

#include "ClapTrap.hpp"

#include <iostream>
#include <string>

ClapTrap::ClapTrap( void )
	: hitPoints( 10 ), energyPoints( 10 ), attackDamage( 0 ) {
	std::cout << "Default constructor called." << std::endl;
}

ClapTrap::ClapTrap( std::string name )
	: name( name ), hitPoints( 10 ), energyPoints( 10 ), attackDamage( 0 ) {
	std::cout << "Parametric constructor called." << std::endl;
}

ClapTrap::ClapTrap( ClapTrap const &ref ) {
	this->name		   = ref.name;
	this->attackDamage = ref.attackDamage;
	this->energyPoints = ref.energyPoints;
	this->hitPoints	   = ref.hitPoints;
	std::cout << "Copy constructor called." << std::endl;
}

ClapTrap::~ClapTrap( void ) { std::cout << "Destructor called." << std::endl; }

ClapTrap &ClapTrap::operator=( ClapTrap const &ref ) {
	this->name		   = ref.name;
	this->attackDamage = ref.attackDamage;
	this->energyPoints = ref.energyPoints;
	this->hitPoints	   = ref.hitPoints;
	std::cout << "Copy assignment called." << std::endl;

	return ( *this );
}

void ClapTrap::attack( const std::string &target ) {
	if ( this->hitPoints && this->energyPoints ) {
		std::cout << "ClapTrap ";
		std::cout << this->name;
		std::cout << " attacks ";
		std::cout << target;
		std::cout << ", causing ";
		std::cout << this->attackDamage;
		std::cout << " points of damage!" << std::endl;
		this->energyPoints--;
	}
}

void ClapTrap::takeDamage( unsigned int amount ) {
	std::cout << "ClapTrap ";
	std::cout << this->name;
	std::cout << " takes ";
	std::cout << amount;
	std::cout << " damage." << std::endl;

	this->hitPoints = amount > this->hitPoints ? 0 : this->hitPoints - amount;
}

void ClapTrap::beRepaired( unsigned int amount ) {
	if ( this->hitPoints && this->energyPoints ) {
		std::cout << "ClapTrap ";
		std::cout << this->name;
		std::cout << " repairs itself by ";
		std::cout << amount;
		std::cout << " points." << std::endl;
		this->hitPoints += amount;
		this->energyPoints--;
	}
}
