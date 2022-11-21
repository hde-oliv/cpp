#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include <iostream>

#include "Form.hpp"

class Form;

class PresidentialPardonForm : public Form {
	public:
	PresidentialPardonForm( void );
	PresidentialPardonForm( PresidentialPardonForm const &ref );
	PresidentialPardonForm( std::string const &target );
	~PresidentialPardonForm( void );
	PresidentialPardonForm &operator=( PresidentialPardonForm const &ref );
	virtual void			execute( Bureaucrat const &executor ) const;

	private:
	std::string target;
};

#endif
