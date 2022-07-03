#include <iostream>
#include <string>

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

int main( void ) {
	{
		std::cout << "--- pdf tests ---" << std::endl;
		// const Animal* meta = new Animal();
		const Animal* j = new Dog();
		const Animal* i = new Cat();
		std::cout << j->getType() << " " << std::endl;
		std::cout << i->getType() << " " << std::endl;
		i->makeSound();	 // will output the cat sound!
		j->makeSound();
		// meta->makeSound();
		std::cout << std::endl;
	}
	return 0;
}
