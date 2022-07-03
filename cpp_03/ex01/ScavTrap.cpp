#include "ScavTrap.hpp"

#include <iostream>

ScavTrap::ScavTrap( void ) : ClapTrap() {
	this->attackDamage = 20;
	this->energyPoints = 50;
	this->hitPoints = 100;
	std::cout << "ScavTrap default constructor called." << std::endl;
}

ScavTrap::ScavTrap( std::string const &name ) : ClapTrap( name ) {
	this->attackDamage = 20;
	this->energyPoints = 50;
	this->hitPoints = 100;
	std::cout << "ScavTrap parametric constructor called." << std::endl;
}

ScavTrap::ScavTrap( ScavTrap const &ref ) : ClapTrap( ref ) {
	std::cout << "ScavTrap copy constructor called." << std::endl;
}

ScavTrap::~ScavTrap( void ) {
	std::cout << "ScavTrap destructor called." << std::endl;
}

ScavTrap &ScavTrap::operator=( ScavTrap const &ref ) {
	this->attackDamage = ref.attackDamage;
	this->energyPoints = ref.energyPoints;
	this->hitPoints = ref.hitPoints;
	this->name = ref.name;
	std::cout << "ScavTrap copy assignment called." << std::endl;
	return ( *this );
}

void ScavTrap::attack( const std::string &target ) {
	if ( this->hitPoints && this->energyPoints ) {
		std::cout << "ScavTrap ";
		std::cout << this->name;
		std::cout << " attacks ";
		std::cout << target;
		std::cout << ", causing ";
		std::cout << this->attackDamage;
		std::cout << " points of damage!" << std::endl;
		this->energyPoints--;
	}
}

void ScavTrap::guardGate( void ) {
	std::cout << "ScavTrap ";
	std::cout << this->name;
	std::cout << " is in GateKeeper mode!" << std::endl;
}
