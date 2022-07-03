#ifndef SCAVTRAP_H
#define SCAVTRAP_H

#include <string>

#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap {
	public:
	ScavTrap( void );
	ScavTrap( ScavTrap const &ref );
	ScavTrap( std::string const &name );
	~ScavTrap( void );
	ScavTrap &operator=( ScavTrap const &ref );
	void attack( const std::string &target );
	void guardGate( void );
};

#endif
