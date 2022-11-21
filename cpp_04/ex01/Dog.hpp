#ifndef DOG_HPP
#define DOG_HPP

#include <string>

#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal {
	public:
	Dog( void );
	Dog( Dog const &ref );
	virtual ~Dog( void );
	Dog			&operator=( Dog const &ref );
	virtual void makeSound( void ) const;

	private:
	Brain *brain;
};

#endif
