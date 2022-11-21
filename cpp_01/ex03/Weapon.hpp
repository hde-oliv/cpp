// Copyright (C) 2022  Henrique Rocha (hde-oliv)

#ifndef WEAPON_HPP
#define WEAPON_HPP

#include <string>

class Weapon {
	public:
	Weapon( std::string type );
	~Weapon();
	std::string const &getType( void ) const;
	void			   setType( std::string type );

	private:
	std::string type;
};

#endif
