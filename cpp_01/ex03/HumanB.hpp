// Copyright (C) 2022  Henrique Rocha (hde-oliv)

#ifndef HUMANB_HPP
#define HUMANB_HPP

#include <string>

#include "Weapon.hpp"

class HumanB {
	public:
	HumanB( std::string name );
	~HumanB( void );
	void attack( void );
	void setWeapon( Weapon &weapon );

	private:
	Weapon	   *weapon;
	std::string name;
};

#endif
