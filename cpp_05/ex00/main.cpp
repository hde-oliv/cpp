#include <iostream>
#include <string>

#include "Bureaucrat.hpp"

int main( void ) {
	{
		std::cout << "--- test constructors ---" << std::endl;
		try {
			Bureaucrat first;
			Bureaucrat second( "FHC", 3 );
			Bureaucrat third( second );
			std::cout << "No exceptions!" << std::endl;
		} catch ( std::exception &e ) {
			std::cout << "Exception caught!" << std::endl;
			std::cout << e.what() << std::endl;
		}
		std::cout << std::endl;

		std::cout << "--- try to create with 0 grade ---" << std::endl;
		try {
			Bureaucrat( "Sarney", 0 );
			std::cout << "No exceptions!" << std::endl;
		} catch ( Bureaucrat::GradeTooHighException &e ) {
			std::cout << "Exception caught!" << std::endl;
			std::cout << e.what() << std::endl;
		}
		std::cout << std::endl;

		std::cout << "--- try to create with 151 grade ---" << std::endl;
		try {
			Bureaucrat( "Collor", 151 );
			std::cout << "No exceptions!" << std::endl;
		} catch ( Bureaucrat::GradeTooLowException &e ) {
			std::cout << "Exception caught!" << std::endl;
			std::cout << e.what() << std::endl;
		}
		std::cout << std::endl;

		std::cout << "--- try to increment 1 grade ---" << std::endl;
		Bureaucrat fourth( "Tancredo", 1 );
		std::cout << fourth << std::endl;
		try {
			fourth.incrementGrade();
			std::cout << "No exceptions!" << std::endl;
		} catch ( Bureaucrat::GradeTooHighException &e ) {
			std::cout << "Exception caught!" << std::endl;
			std::cout << e.what() << std::endl;
		}
		std::cout << std::endl;

		std::cout << "--- try to decrement 151 grade ---" << std::endl;
		Bureaucrat fifth( "Itamar", 150 );
		std::cout << fifth << std::endl;
		try {
			fifth.decrementGrade();
			std::cout << "No exceptions!" << std::endl;
		} catch ( Bureaucrat::GradeTooLowException &e ) {
			std::cout << "Exception caught!" << std::endl;
			std::cout << e.what() << std::endl;
		}
	}

	return 0;
}
