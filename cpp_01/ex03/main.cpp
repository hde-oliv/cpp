// Copyright (C) 2022  Henrique Rocha (hde-oliv)

#include <iostream>
#include <string>

#include "HumanA.hpp"
#include "HumanB.hpp"
#include "Weapon.hpp"

int main( void ) {
	std::cout << "---- PDF Tests ----" << std::endl << std::endl;
	{
		Weapon club = Weapon( "crude spiked club" );

		HumanA bob( "Bob", club );
		bob.attack();
		club.setType( "some other type of club" );
		bob.attack();
	}
	{
		Weapon club = Weapon( "crude spiked club" );

		HumanB jim( "Jim" );
		jim.setWeapon( club );
		jim.attack();
		club.setType( "some other type of club" );
		jim.attack();
	}

	std::cout << "---- My Tests ----" << std::endl << std::endl;
	{
		Weapon katana = Weapon( "Hattori Hanzo" );
		HumanB kiddo( "Kiddo" );

		kiddo.setWeapon( katana );
		kiddo.attack();
		katana.setType( "random wood splunk" );
		kiddo.attack();
		katana.setType( "Hattori Hanzo" );
		kiddo.attack();

		Weapon punch = Weapon( "Death Punch" );
		kiddo.setWeapon( punch );
		kiddo.attack();
	}
	{
		Weapon revolver = Weapon( "Revolver" );
		HumanA bill( "Bill", revolver );

		bill.attack();
		revolver.setType( "random Colt revolver" );
		bill.attack();
		revolver.setType( "Revolver" );
		bill.attack();
	}
}
