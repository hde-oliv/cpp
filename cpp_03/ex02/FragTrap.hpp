// Copyright (C) 2022  Henrique Rocha (hde-oliv)

#ifndef FRAGTRAP_H
#define FRAGTRAP_H

#include <string>

#include "ClapTrap.hpp"

class FragTrap : public ClapTrap {
	public:
	FragTrap( void );
	FragTrap( FragTrap const &ref );
	FragTrap( std::string const &name );
	~FragTrap( void );
	FragTrap &operator=( FragTrap const &ref );
	void	  attack( const std::string &target );
	void	  highFivesGuys( void );
};

#endif
