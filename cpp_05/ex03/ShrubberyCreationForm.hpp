#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include "Form.hpp"

class Form;

class ShrubberyCreationForm : public Form {
	public:
	ShrubberyCreationForm( void );
	ShrubberyCreationForm( std::string const &target );
	ShrubberyCreationForm( ShrubberyCreationForm const &ref );
	~ShrubberyCreationForm( void );
	ShrubberyCreationForm &operator=( ShrubberyCreationForm const &ref );
	virtual void		   execute( Bureaucrat const &executor ) const;

	private:
	std::string target;
};

#endif
