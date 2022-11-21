#include "ShrubberyCreationForm.hpp"

#include <fstream>
#include <iostream>

ShrubberyCreationForm::ShrubberyCreationForm( void )
	: Form( "ShrubberyCreation", 145, 137 ) {
	this->target = "";
}

ShrubberyCreationForm::ShrubberyCreationForm( ShrubberyCreationForm const &ref )
	: Form( ref ) {
	this->target = ref.target;
}

ShrubberyCreationForm::ShrubberyCreationForm( std::string const &target )
	: Form( "ShrubberyCreation", 145, 137 ) {
	this->target = target;
}

ShrubberyCreationForm::~ShrubberyCreationForm( void ) {}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(
	ShrubberyCreationForm const &ref ) {
	this->target = ref.target;
	return *this;
}

void ShrubberyCreationForm::execute( Bureaucrat const &executor ) const {
	if ( !this->getIsSigned() ) throw Form::NotSignedException();

	if ( executor.getGrade() <= this->getExecuteGrade() ) {
		std::string	  filename = this->target + "_shrubbery";
		std::ofstream file( filename.c_str() );

		for ( int i = 0; i < 2; i++ ) {
			file << "         #o#";
			file << std::endl;
			file << "       ####o#";
			file << std::endl;
			file << "      #o# \\#|_#,#";
			file << std::endl;
			file << "     ###\\ |/   #o#";
			file << std::endl;
			file << "      # {}{      #";
			file << std::endl;
			file << "ejm      }{{";
			file << std::endl;
			file << "        ,'  `";
			file << std::endl;
		}

		file.close();
	} else {
		throw Form::GradeTooLowException();
	}
}
