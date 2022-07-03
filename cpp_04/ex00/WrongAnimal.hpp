#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP

#include <string>

class WrongAnimal {
	public:
	WrongAnimal( void );
	WrongAnimal( WrongAnimal const &ref );
	~WrongAnimal( void );
	WrongAnimal &operator=( WrongAnimal const &ref );
	void makeSound( void ) const;
	std::string getType( void ) const;

	protected:
	std::string type;
};

#endif
