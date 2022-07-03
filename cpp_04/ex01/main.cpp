#include <iostream>
#include <string>

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

int main( void ) {
	{
		std::cout << "--- pdf tests ---" << std::endl;
		const Animal *j = new Dog();
		const Animal *i = new Cat();

		delete j;
		delete i;
		std::cout << std::endl;
	}
	{
		std::cout << "--- pdf tests again---" << std::endl;
		Animal *array = new Animal[100];

		for ( int i = 0; i < 100; i++ ) {
			if ( i < 50 ) array[i] = new Dog();
		}
	}
	return 0;
}
