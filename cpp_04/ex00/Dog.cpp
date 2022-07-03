#include "Dog.hpp"

#include <iostream>
#include <string>

Dog::Dog( void ) : Animal() {
	std::cout << "Dog default constructor called." << std::endl;
	this->type = "Dog";
}

Dog::Dog( Dog const &ref ) : Animal( ref ) {
	std::cout << "Dog copy constructor called." << std::endl;
	this->type = ref.type;
}

Dog::~Dog( void ) { std::cout << "Dog destructor called." << std::endl; }

Dog &Dog::operator=( Dog const &ref ) {
	std::cout << "Dog assignment operator called." << std::endl;
	this->type = ref.type;
	return *this;
}

void Dog::makeSound( void ) const { std::cout << "ワンワン" << std::endl; }
