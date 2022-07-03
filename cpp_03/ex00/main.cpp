#include <iostream>
#include <string>

#include "ClapTrap.hpp"

int main( void ) {
	ClapTrap first;
	ClapTrap second( "Billy" );
	ClapTrap third( second );

	second.attack( "Ghost" );
	third.attack( "Ghost" );

	second.takeDamage( 8 );
	first = second;
	first.takeDamage( 2312323 );

	std::cout << "--- trying to attack with first ---" << std::endl;
	first.attack( "Pringles" );

	std::cout << "--- trying to attack with second ---" << std::endl;
	second.attack( "Pringles" );

	third.beRepaired( 600 );
}
