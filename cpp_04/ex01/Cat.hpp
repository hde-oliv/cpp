#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal {
	public:
	Cat( void );
	Cat( Cat const &ref );
	virtual ~Cat( void );
	Cat &operator=( Cat const &ref );
	virtual void makeSound( void ) const;

	private:
	Brain *brain;
};

#endif
