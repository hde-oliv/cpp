#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <stdexcept>
#include <string>

#include "Form.hpp"

class Bureaucrat {
	public:
	Bureaucrat( void );
	Bureaucrat( Bureaucrat const &ref );
	Bureaucrat( std::string name, int grade );
	~Bureaucrat( void );
	Bureaucrat &operator=( Bureaucrat const &ref );
	std::string getName( void ) const;
	int getGrade( void ) const;
	void incrementGrade( void );
	void decrementGrade( void );
	void signForm( Form &ref ) const;

	class GradeTooHighException : public std::exception {
		public:
		virtual const char *what( void ) const throw();
	};

	class GradeTooLowException : public std::exception {
		public:
		virtual const char *what( void ) const throw();
	};

	private:
	std::string const name;
	int grade;
	const int maxGrade = 1;
	const int minGrade = 150;
};

std::ostream &operator<<( std::ostream &o, Bureaucrat const &ref );

#endif
