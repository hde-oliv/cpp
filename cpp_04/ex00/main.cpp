#include <iostream>
#include <string>

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main( void ) {
	{
		std::cout << "--- pdf tests ---" << std::endl;
		const Animal* meta = new Animal();
		const Animal* j	   = new Dog();
		const Animal* i	   = new Cat();
		std::cout << j->getType() << " " << std::endl;
		std::cout << i->getType() << " " << std::endl;
		i->makeSound();	 // will output the cat sound!
		j->makeSound();
		meta->makeSound();
		std::cout << std::endl;

		delete meta;
		delete j;
		delete i;
	}
	{
		std::cout << "--- pdf tests with wrongcat---" << std::endl;
		const WrongAnimal* meta = new WrongAnimal();
		// const WrongAnimal* j = new Dog();
		const WrongAnimal* i = new WrongCat();
		// std::cout << j->getType() << " " << std::endl;
		std::cout << i->getType() << " " << std::endl;
		i->makeSound();	 // will not output the cat sound!
		// j->makeSound();
		meta->makeSound();
		std::cout << std::endl;

		delete meta;
		delete i;
	}
	{
		std::cout << "--- my tests ---" << std::endl;

		const Cat firstCat;
		const Cat secondCat( firstCat );

		const Dog firstDog;
		const Dog secondDog( firstDog );

		const Animal firstAnimal;
		const Animal secondAnimal( firstAnimal );

		std::cout << firstCat.getType() << std::endl;
		std::cout << secondCat.getType() << std::endl;
		std::cout << firstDog.getType() << std::endl;
		std::cout << secondDog.getType() << std::endl;
		std::cout << firstAnimal.getType() << std::endl;
		std::cout << secondAnimal.getType() << std::endl;

		firstCat.makeSound();
		secondCat.makeSound();
		firstDog.makeSound();
		secondDog.makeSound();
		firstAnimal.makeSound();
		secondAnimal.makeSound();

		std::cout << std::endl;

		const WrongAnimal firstWrongAnimal;
		const WrongAnimal secondWrongAnimal( firstWrongAnimal );
		const WrongCat	  firstWrongCat;
		const WrongCat	  secondWrongCat( firstWrongCat );

		std::cout << firstWrongAnimal.getType() << std::endl;
		std::cout << secondWrongAnimal.getType() << std::endl;
		std::cout << firstWrongCat.getType() << std::endl;
		std::cout << secondWrongCat.getType() << std::endl;

		firstWrongAnimal.makeSound();
		secondWrongAnimal.makeSound();
		firstWrongCat.makeSound();
		secondWrongCat.makeSound();
	}
	return 0;
}
