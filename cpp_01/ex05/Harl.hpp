// Copyright (C) 2022  Henrique Rocha (hde-oliv)

#ifndef HARL_HPP
#define HARL_HPP

#include <string>

class Harl {
	public:
	Harl( void );
	~Harl( void );
	void complain( std::string level );

	private:
	void debug( void );
	void info( void );
	void warning( void );
	void error( void );
	void invalid( void );
};

#endif
