#include "Intern.hpp"

#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

Intern::Intern( void ) {}

Intern::Intern( Intern const &ref ) { (void)ref; }

Intern::~Intern( void ) {}

Intern &Intern::operator=( Intern const &ref ) {
	(void)ref;
	return *this;
}

Form *presidentialPardon( std::string const &target ) {
	return new PresidentialPardonForm( target );
}

Form *robotomyRequest( std::string const &target ) {
	return new RobotomyRequestForm( target );
}

Form *shrubberyCreation( std::string const &target ) {
	return new ShrubberyCreationForm( target );
}

Form *Intern::makeForm( std::string const &formName,
						std::string const &target ) const {
	std::string forms[] = { "presidential pardon", "robotomy request",
							"shrubbery creation" };
	Form *( *fp[] )( std::string const &target ) = { &presidentialPardon,
													 &robotomyRequest,
													 &shrubberyCreation };

	for ( int i = 0; i < 3; i++ ) {
		if ( !formName.compare( forms[i] ) ) {
			return fp[i]( target );
		}
	}
	return new ShrubberyCreationForm;
}
