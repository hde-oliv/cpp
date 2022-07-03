#include "WrongCat.hpp"

#include <iostream>
#include <string>

WrongCat::WrongCat( void ) : WrongAnimal() {
	std::cout << "WrongCat default constructor called." << std::endl;
	this->type = "WrongCat";
}

WrongCat::WrongCat( WrongCat const &ref ) : WrongAnimal( ref ) {
	std::cout << "WrongCat copy constructor called." << std::endl;
	this->type = ref.type;
}

WrongCat::~WrongCat( void ) {
	std::cout << "WrongCat destructor called." << std::endl;
}

WrongCat &WrongCat::operator=( WrongCat const &ref ) {
	std::cout << "WrongCat assignment operator called." << std::endl;
	this->type = ref.type;
	return *this;
}

void WrongCat::makeSound( void ) const { std::cout << "ケロケロ" << std::endl; }
