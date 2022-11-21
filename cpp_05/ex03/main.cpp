#include <iostream>
#include <string>

#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main( void ) {
	Bureaucrat b( "Deodoro", 1 );

	std::cout << "--- test robotomy request" << std::endl;
	{
		Intern first;
		Form  *ptr;

		ptr = first.makeForm( "robotomy request", "Pedro" );
		b.signForm( *ptr );
		b.executeForm( *ptr );
		delete ptr;
	}
	std::cout << std::endl;
	std::cout << "--- test presidential pardon" << std::endl;
	{
		Intern first;
		Form  *ptr;

		ptr = first.makeForm( "presidential pardon", "Pedro" );
		b.signForm( *ptr );
		b.executeForm( *ptr );
		delete ptr;
	}
	std::cout << std::endl;
	std::cout << "--- test shrubbery creation" << std::endl;
	{
		Intern first;
		Form  *ptr;

		ptr = first.makeForm( "shrubbery creation", "Pedro" );
		b.signForm( *ptr );
		b.executeForm( *ptr );
		delete ptr;
	}
	std::cout << std::endl;
	return 0;
}
