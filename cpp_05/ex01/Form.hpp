#ifndef FORM_HPP
#define FORM_HPP

#include <string>

#include "Bureaucrat.hpp"

class Form {
	public:
	Form( void );
	Form( std::string const &name, int signGrade, int executeGrade );
	Form( Form const &ref );
	~Form( void );
	Form &operator=( Form const &ref );
	std::string getName( void ) const;
	bool getIsSigned( void ) const;
	int getSignGrade( void ) const;
	int getExecuteGrade( void ) const;
	void beSigned( Bureaucrat const &ref );

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
	bool isSigned;
	int const signGrade;
	int const executeGrade;
	int const maxGrade = 1;
	int const minGrade = 150;
};

std::ostream &operator<<( std::ostream &o, Bureaucrat const &ref );

#endif
