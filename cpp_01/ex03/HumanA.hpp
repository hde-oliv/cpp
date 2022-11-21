// Copyright (C) 2022  Henrique Rocha (hde-oliv)

#ifndef HUMANA_HPP
#define HUMANA_HPP

#include <string>

#include "Weapon.hpp"

class HumanA {
	public:
	HumanA( std::string name, Weapon &weapon );
	~HumanA( void );
	void attack( void );

	private:
	Weapon	   &weapon;
	std::string name;
};

#endif
