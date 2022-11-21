#ifndef INTERN_HPP
#define INTERN_HPP

#include <iostream>

#include "Form.hpp"

class Intern {
	public:
	Intern( void );
	Intern( Intern const &ref );
	~Intern( void );
	Intern &operator=( Intern const &ref );
	Form   *makeForm( std::string const &formName,
					  std::string const &target ) const;
};

#endif
