#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <string>

class Animal {
	public:
	Animal( void );
	Animal( Animal const &ref );
	virtual ~Animal( void );
	Animal &operator=( Animal const &ref );
	virtual void makeSound( void ) const = 0;
	std::string getType( void ) const;

	protected:
	std::string type;
};

#endif
