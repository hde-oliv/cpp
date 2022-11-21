#include "PresidentialPardonForm.hpp"

#include <cstdlib>
#include <fstream>
#include <iostream>

PresidentialPardonForm::PresidentialPardonForm( void )
	: Form( "PresidentialPardon", 25, 5 ) {
	this->target = "";
}

PresidentialPardonForm::PresidentialPardonForm(
	PresidentialPardonForm const &ref )
	: Form( ref ) {
	this->target = ref.target;
}

PresidentialPardonForm::PresidentialPardonForm( std::string const &target )
	: Form( "PresidentialPardon", 25, 5 ) {
	this->target = target;
}

PresidentialPardonForm::~PresidentialPardonForm( void ) {}

PresidentialPardonForm &PresidentialPardonForm::operator=(
	PresidentialPardonForm const &ref ) {
	this->target = ref.target;
	return *this;
}

void PresidentialPardonForm::execute( Bureaucrat const &executor ) const {
	if ( !this->getIsSigned() ) throw Form::NotSignedException();

	if ( executor.getGrade() <= this->getExecuteGrade() ) {
		std::cout << "Zaphod Beeblebrox pardoned " << this->target << "."
				  << std::endl;
	} else {
		throw Form::GradeTooLowException();
	}
}
