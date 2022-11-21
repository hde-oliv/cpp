#include "Dog.hpp"

#include <iostream>
#include <string>

#include "Brain.hpp"

Dog::Dog( void ) : Animal() {
	std::cout << "Dog default constructor called." << std::endl;
	this->type	= "Dog";
	this->brain = new Brain();
}

Dog::Dog( Dog const &ref ) : Animal( ref ) {
	std::cout << "Dog copy constructor called." << std::endl;
	this->type	= ref.type;
	this->brain = new Brain( *ref.brain );
}

Dog::~Dog( void ) {
	std::cout << "Dog destructor called." << std::endl;
	delete this->brain;
}

Dog &Dog::operator=( Dog const &ref ) {
	std::cout << "Dog assignment operator called." << std::endl;
	this->type = ref.type;
	return *this;
}

void Dog::makeSound( void ) const { std::cout << "ワンワン" << std::endl; }
