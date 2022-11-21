#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include "Form.hpp"

class Form;

class RobotomyRequestForm : public Form {
	public:
	RobotomyRequestForm( void );
	RobotomyRequestForm( std::string const &target );
	RobotomyRequestForm( RobotomyRequestForm const &ref );
	~RobotomyRequestForm( void );
	RobotomyRequestForm &operator=( RobotomyRequestForm const &ref );
	virtual void		 execute( Bureaucrat const &executor ) const;

	private:
	std::string target;
};

#endif
