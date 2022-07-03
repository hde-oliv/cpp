#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <string>

class Brain {
	public:
	Brain( void );
	Brain( Brain const &ref );
	Brain( std::string const &idea );
	~Brain( void );
	Brain &operator=( Brain const &ref );
	std::string ideas[100];
};

#endif
