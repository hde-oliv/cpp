#include <iostream>
#include <string>

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main( void ) {
	std::cout << "--- creating first ---" << std::endl;
	ScavTrap first;

	std::cout << "--- creating second ---" << std::endl;
	ScavTrap second( "Billy" );

	std::cout << "--- creating third ---" << std::endl;
	ScavTrap third( second );

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
	std::cout << "--- guarding gate with all three ---" << std::endl;
	first.guardGate();
	second.guardGate();
	third.guardGate();
	std::cout << std::endl;
}
