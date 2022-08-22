#include "Form.hpp"

#include <iostream>
#include <stdexcept>
#include <string>

Form::Form( void ) : name( "Default" ), signGrade( 1 ), executeGrade( 1 ) {}

Form::Form( std::string const &name, int signGrade, int executeGrade )
	: name( name ), signGrade( signGrade ), executeGrade( executeGrade ) {
	if ( signGrade < this->maxGrade )
		throw Form::GradeTooHighException();
	else if ( signGrade > this->minGrade )
		throw Form::GradeTooLowException();
	if ( executeGrade < this->maxGrade )
		throw Form::GradeTooHighException();
	else if ( executeGrade > this->minGrade )
		throw Form::GradeTooLowException();
}

Form::Form( Form const &ref )
	: name( ref.getName() ),
	  signGrade( ref.getSignGrade() ),
	  executeGrade( ref.getExecuteGrade() ) {}

Form::~Form( void ) {}

Form &Form::operator=( Form const &ref ) { return *this; }

std::string Form::getName( void ) const { return this->name; }

bool Form::getIsSigned( void ) const { return this->isSigned; }

int Form::getSignGrade( void ) const { return this->signGrade; }

int Form::getExecuteGrade( void ) const { return this->executeGrade; }

void Form::beSigned( Bureaucrat const &ref ) {
	if ( ref.getGrade() <= this->signGrade ) {
		this->isSigned = true;
	} else {
		throw Form::GradeTooLowException();
	}
}

std::ostream &operator<<( std::ostream &o, Form const &ref ) {
	o << ref.getName();
	o << " form, sign grade ";
	o << ref.getSignGrade();
	o << ", execute grade ";
	o << ref.getExecuteGrade();
	o << ".";
	return o;
}

const char *Form::GradeTooHighException::what( void ) const throw() {
	return "GradeTooHighException: grade higher than 1.";
}

const char *Form::GradeTooLowException::what( void ) const throw() {
	return "GradeTooLowException: grade lower than 150.";
}
