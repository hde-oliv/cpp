#include <iostream>
#include <string>

#include "ClapTrap.hpp"
#include "FragTrap.hpp"
#include "ScavTrap.hpp"

int main( void ) {
	std::cout << "--- creating first ---" << std::endl;
	FragTrap first;

	std::cout << "--- creating second ---" << std::endl;
	FragTrap second( "Billy" );

	std::cout << "--- creating third ---" << std::endl;
	FragTrap third( second );

	std::cout << std::endl;
	std::cout << "--- trying to attack with second ---" << std::endl;
	second.attack( "Ghost" );
	std::cout << "--- trying to attack with third ---" << std::endl;
	third.attack( "Ghost" );

	std::cout << std::endl;
	std::cout << "--- copying second to first ---" << std::endl;
	first = second;
	std::cout << "--- trying to attack with first ---" << std::endl;
	first.attack( "Pringles" );

	std::cout << std::endl;
	std::cout << "--- high five with all three ---" << std::endl;
	first.highFivesGuys();
	second.highFivesGuys();
	third.highFivesGuys();
	std::cout << std::endl;
}
