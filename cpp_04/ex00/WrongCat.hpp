#ifndef WRONGCAT_HPP
#define WRONGCAT_HPP

#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal {
	public:
	WrongCat( void );
	WrongCat( WrongCat const &ref );
	~WrongCat( void );
	WrongCat &operator=( WrongCat const &ref );
	void makeSound( void ) const;
};

#endif
