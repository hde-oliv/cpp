#ifndef CLAPTRAP_H
#define CLAPTRAP_H

#include <string>

class ClapTrap {
	public:
	ClapTrap( void );
	ClapTrap( std::string const &name );
	ClapTrap( ClapTrap const &ref );
	~ClapTrap( void );
	ClapTrap &operator=( ClapTrap const &ref );
	void attack( const std::string &target );
	void takeDamage( unsigned int amount );
	void beRepaired( unsigned int amount );

	protected:
	std::string name;
	unsigned int hitPoints;
	unsigned int energyPoints;
	unsigned int attackDamage;
};

#endif
