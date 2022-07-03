#include "Cat.hpp"

#include <iostream>
#include <string>

#include "Brain.hpp"

Cat::Cat( void ) : Animal() {
	std::cout << "Cat default constructor called." << std::endl;
	this->type = "Cat";
	this->brain = new Brain();
}

Cat::Cat( Cat const &ref ) : Animal( ref ) {
	std::cout << "Cat copy constructor called." << std::endl;
	this->type = ref.type;
	this->brain = new Brain( *ref.brain );
}

Cat::~Cat( void ) {
	std::cout << "Cat destructor called." << std::endl;
	delete this->brain;
}

Cat &Cat::operator=( Cat const &ref ) {
	std::cout << "Cat assignment operator called." << std::endl;
	this->type = ref.type;
	return *this;
}

void Cat::makeSound( void ) const { std::cout << "ニャーニャー" << std::endl; }
