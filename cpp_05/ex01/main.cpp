#include <iostream>
#include <string>

#include "Bureaucrat.hpp"

int main( void ) {
	std::cout << "--- create 2 bureaucrats" << std::endl;
	Bureaucrat first( "Prestes", 150 );
	Bureaucrat second( "Vargas", 1 );
	std::cout << first << std::endl;
	std::cout << second << std::endl;
	std::cout << std::endl;

	std::cout << "--- create 2 forms" << std::endl;
	Form firstForm( "Estado Novo", 1, 1 );
	Form secondForm( "Revolução de 30", 1, 1 );
	std::cout << firstForm << std::endl;
	std::cout << secondForm << std::endl;
	std::cout << std::endl;

	std::cout << "--- try to create form with 151 sign grade" << std::endl;
	try {
		Form errorForm1( "Error", 151, 1 );
		std::cout << "No exceptions!" << std::endl;
	} catch ( Form::GradeTooLowException &e ) {
		std::cout << "Exception caught!" << std::endl;
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl;

	std::cout << "--- try to create form with 0 sign grade" << std::endl;
	try {
		Form errorForm2( "Error", 0, 1 );
		std::cout << "No exceptions!" << std::endl;
	} catch ( Form::GradeTooHighException &e ) {
		std::cout << "Exception caught!" << std::endl;
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl;

	std::cout << "--- try to create form with 151 execute grade" << std::endl;
	try {
		Form errorForm3( "Error", 1, 151 );
		std::cout << "No exceptions!" << std::endl;
	} catch ( Form::GradeTooLowException &e ) {
		std::cout << "Exception caught!" << std::endl;
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl;

	std::cout << "--- try to create form with 0 execute grade" << std::endl;
	try {
		Form errorForm4( "Error", 1, 0 );
		std::cout << "No exceptions!" << std::endl;
	} catch ( Form::GradeTooHighException &e ) {
		std::cout << "Exception caught!" << std::endl;
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl;

	std::cout << "--- try to be signed: secondForm with first" << std::endl;
	try {
		secondForm.beSigned( first );
	} catch ( Form::GradeTooLowException &e ) {
		std::cout << "Exception caught!" << std::endl;
		std::cout << e.what() << std::endl;
	}
	std::cout << secondForm.getIsSigned() << std::endl;
	std::cout << std::endl;

	std::cout << "--- try to be signed: secondForm with second" << std::endl;
	try {
		secondForm.beSigned( second );
	} catch ( Form::GradeTooLowException &e ) {
		std::cout << "Exception caught!" << std::endl;
		std::cout << e.what() << std::endl;
	}
	std::cout << secondForm.getIsSigned() << std::endl;
	std::cout << std::endl;

	std::cout << "--- try to sign: firstForm with first" << std::endl;
	try {
		first.signForm( firstForm );
	} catch ( Form::GradeTooLowException &e ) {
		std::cout << "Exception caught!" << std::endl;
		std::cout << e.what() << std::endl;
	}
	std::cout << firstForm.getIsSigned() << std::endl;
	std::cout << std::endl;

	std::cout << "--- try to sign: firstForm with second" << std::endl;
	try {
		second.signForm( firstForm );
	} catch ( Form::GradeTooLowException &e ) {
		std::cout << "Exception caught!" << std::endl;
		std::cout << e.what() << std::endl;
	}
	std::cout << firstForm.getIsSigned() << std::endl;
	std::cout << std::endl;
	return 0;
}
