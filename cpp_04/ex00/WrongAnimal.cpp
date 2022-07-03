#include "WrongAnimal.hpp"

#include <iostream>
#include <string>

WrongAnimal::WrongAnimal( void ) {
	std::cout << "WrongAnimal default constructor called." << std::endl;
}

WrongAnimal::WrongAnimal( WrongAnimal const &ref ) {
	this->type = ref.type;
	std::cout << "WrongAnimal copy constructor called." << std::endl;
}

WrongAnimal::~WrongAnimal( void ) {
	std::cout << "WrongAnimal destructor called." << std::endl;
}

WrongAnimal &WrongAnimal::operator=( WrongAnimal const &ref ) {
	this->type = ref.type;
	std::cout << "WrongAnimal assignment operator called." << std::endl;
	return *this;
}

std::string WrongAnimal::getType( void ) const { return this->type; }

void WrongAnimal::makeSound( void ) const { std::cout << "違う" << std::endl; }
