#include "Brain.hpp"

#include <iostream>
#include <string>

Brain::Brain( void ) {
	std::cout << "Brain default constructor called." << std::endl;
}

Brain::Brain( Brain const &ref ) {
	std::cout << "Brain copy constructor called." << std::endl;
	for ( int i = 0; i < 100; i++ ) {
		this->ideas[i] = ref.ideas[i];
	}
}

Brain::Brain( std::string const &idea ) {
	for ( int i = 0; i < 100; i++ ) {
		this->ideas[i] = idea;
	}
	std::cout << "Brain parametric constructor called." << std::endl;
}

Brain::~Brain( void ) { std::cout << "Brain destructor called." << std::endl; }

Brain &Brain::operator=( Brain const &ref ) {
	std::cout << "Brain assignment operator called." << std::endl;
	for ( int i = 0; i < 100; i++ ) {
		this->ideas[i] = ref.ideas[i];
	}
	return ( *this );
}
