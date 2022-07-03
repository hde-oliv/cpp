#ifndef DOG_HPP
#define DOG_HPP

#include <string>

#include "Animal.hpp"

class Dog : public Animal {
	public:
	Dog( void );
	Dog( Dog const &ref );
	~Dog( void );
	Dog &operator=( Dog const &ref );
	virtual void makeSound( void ) const;
};

#endif
