#include "RobotomyRequestForm.hpp"

#include <cstdlib>
#include <ctime>
#include <fstream>
#include <iostream>

RobotomyRequestForm::RobotomyRequestForm( void )
	: Form( "RobotomyRequest", 72, 45 ) {
	this->target = "";
}

RobotomyRequestForm::RobotomyRequestForm( RobotomyRequestForm const &ref )
	: Form( ref ) {
	this->target = ref.target;
}

RobotomyRequestForm::RobotomyRequestForm( std::string const &target )
	: Form( "RobotomyRequest", 72, 45 ) {
	this->target = target;
}

RobotomyRequestForm::~RobotomyRequestForm( void ) {}

RobotomyRequestForm &RobotomyRequestForm::operator=(
	RobotomyRequestForm const &ref ) {
	this->target = ref.target;
	return *this;
}

void RobotomyRequestForm::execute( Bureaucrat const &executor ) const {
	if ( !this->getIsSigned() ) throw Form::NotSignedException();

	if ( executor.getGrade() <= this->getExecuteGrade() ) {
		std::cout << "~drill noises~" << std::endl;
		std::srand( std::time( NULL ) );
		int r = std::rand() % 2;
		if ( r ) {
			std::cout << this->target << " was robotomized." << std::endl;
		} else {
			std::cout << "Robotomy failed." << std::endl;
		}
	} else {
		throw Form::GradeTooLowException();
	}
}
