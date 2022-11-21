#include <iostream>
#include <string>

#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main( void ) {
	{
		std::cout << "--- PresidentialPardon tests" << std::endl;
		std::cout << "--- create 2 bureaucrats" << std::endl;
		Bureaucrat first( "Deodoro", 24 );
		Bureaucrat second( "Peixoto", 1 );
		std::cout << first << std::endl;
		std::cout << second << std::endl;
		std::cout << std::endl;

		std::cout << "--- create PresidentialPardon" << std::endl;
		PresidentialPardonForm form( "Pedro" );
		std::cout << form << std::endl;
		std::cout << std::endl;

		std::cout << "--- try to execute before sign" << std::endl;
		try {
			second.executeForm( form );
			std::cout << "success!" << std::endl;
		} catch ( Form::NotSignedException &e ) {
			std::cout << "exception caught!" << std::endl;
			std::cout << e.what() << std::endl;
		}
		std::cout << std::endl;

		std::cout << "--- try to signForm" << std::endl;
		first.signForm( form );
		std::cout << std::endl;

		std::cout << "--- try to execute with first bureaucrat" << std::endl;
		try {
			first.executeForm( form );
			std::cout << "success!" << std::endl;
		} catch ( Form::GradeTooLowException &e ) {
			std::cout << "exception caught!" << std::endl;
			std::cout << e.what() << std::endl;
		}
		std::cout << std::endl;

		std::cout << "--- try to execute" << std::endl;
		second.executeForm( form );
		std::cout << std::endl;
	}
	{
		std::cout << "--- RobotomyRequest tests" << std::endl;
		std::cout << "--- create 2 bureaucrats" << std::endl;
		Bureaucrat first( "Deodoro", 71 );
		Bureaucrat second( "Peixoto", 44 );
		std::cout << first << std::endl;
		std::cout << second << std::endl;
		std::cout << std::endl;

		std::cout << "--- create RobotomyRequest" << std::endl;
		RobotomyRequestForm form( "Pedro" );
		std::cout << form << std::endl;
		std::cout << std::endl;

		std::cout << "--- try to execute before sign" << std::endl;
		try {
			second.executeForm( form );
			std::cout << "success!" << std::endl;
		} catch ( Form::NotSignedException &e ) {
			std::cout << "exception caught!" << std::endl;
			std::cout << e.what() << std::endl;
		}
		std::cout << std::endl;

		std::cout << "--- try to signForm" << std::endl;
		first.signForm( form );
		std::cout << std::endl;

		std::cout << "--- try to execute with first bureaucrat" << std::endl;
		try {
			first.executeForm( form );
			std::cout << "success!" << std::endl;
		} catch ( Form::GradeTooLowException &e ) {
			std::cout << "exception caught!" << std::endl;
			std::cout << e.what() << std::endl;
		}
		std::cout << std::endl;

		std::cout << "--- try to execute" << std::endl;
		second.executeForm( form );
		std::cout << std::endl;
	}
	{
		std::cout << "--- ShrubberyCreation tests" << std::endl;
		std::cout << "--- create 2 bureaucrats" << std::endl;
		Bureaucrat first( "Deodoro", 144 );
		Bureaucrat second( "Peixoto", 136 );
		std::cout << first << std::endl;
		std::cout << second << std::endl;
		std::cout << std::endl;

		std::cout << "--- create ShrubberyCreation" << std::endl;
		ShrubberyCreationForm form( "Pedro" );
		std::cout << form << std::endl;
		std::cout << std::endl;

		std::cout << "--- try to execute before sign" << std::endl;
		try {
			second.executeForm( form );
			std::cout << "success!" << std::endl;
		} catch ( Form::NotSignedException &e ) {
			std::cout << "exception caught!" << std::endl;
			std::cout << e.what() << std::endl;
		}
		std::cout << std::endl;

		std::cout << "--- try to signForm" << std::endl;
		first.signForm( form );
		std::cout << std::endl;

		std::cout << "--- try to execute with first bureaucrat" << std::endl;
		try {
			first.executeForm( form );
			std::cout << "success!" << std::endl;
		} catch ( Form::GradeTooLowException &e ) {
			std::cout << "exception caught!" << std::endl;
			std::cout << e.what() << std::endl;
		}
		std::cout << std::endl;

		std::cout << "--- try to execute" << std::endl;
		second.executeForm( form );
		std::cout << std::endl;
	}
	return 0;
}
