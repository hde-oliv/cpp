#include "Animal.hpp"

#include <iostream>
#include <string>

Animal::Animal( void ) {
	std::cout << "Animal default constructor called." << std::endl;
}

Animal::Animal( Animal const &ref ) {
	this->type = ref.type;
	std::cout << "Animal copy constructor called." << std::endl;
}

Animal::~Animal( void ) {
	std::cout << "Animal destructor called." << std::endl;
}

Animal &Animal::operator=( Animal const &ref ) {
	this->type = ref.type;
	std::cout << "Animal assignment operator called." << std::endl;
	return *this;
}

std::string Animal::getType( void ) const { return this->type; }

void Animal::makeSound( void ) const { std::cout << "正解" << std::endl; }
