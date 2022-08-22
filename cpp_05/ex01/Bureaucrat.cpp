#include "Bureaucrat.hpp"

#include <iostream>
#include <stdexcept>
#include <string>

Bureaucrat::Bureaucrat( void ) : name( "Enzo" ) {}

Bureaucrat::Bureaucrat( std::string name, int grade ) : name( name ) {
	if ( grade < this->maxGrade )
		throw Bureaucrat::GradeTooHighException();
	else if ( grade > this->minGrade )
		throw Bureaucrat::GradeTooLowException();
	else
		this->grade = grade;
}

Bureaucrat::Bureaucrat( Bureaucrat const &ref ) : name( ref.getName() ) {
	this->grade = ref.grade;
}

Bureaucrat::~Bureaucrat( void ) {}

Bureaucrat &Bureaucrat::operator=( Bureaucrat const &ref ) {
	this->grade = ref.grade;
	return *this;
}

std::string Bureaucrat::getName( void ) const { return this->name; }

int Bureaucrat::getGrade( void ) const { return this->grade; }

void Bureaucrat::incrementGrade( void ) {
	if ( this->grade - 1 < this->maxGrade )
		throw Bureaucrat::GradeTooHighException();
	else
		this->grade--;
}

void Bureaucrat::decrementGrade( void ) {
	if ( this->grade + 1 > this->minGrade )
		throw Bureaucrat::GradeTooLowException();
	else
		this->grade++;
}

void Bureaucrat::signForm( Form &ref ) const {
	try {
		ref.beSigned( *this );
		std::cout << this->name << " signed " << ref.getName() << std::endl;
	} catch ( std::exception &e ) {
		std::cout << this->name << " could't sign " << ref.getName()
				  << "because" << e.what() << std::endl;
	}
}

std::ostream &operator<<( std::ostream &o, Bureaucrat const &ref ) {
	o << ref.getName();
	o << ", bureaucrat grade ";
	o << ref.getGrade();
	o << ".";
	return o;
}

const char *Bureaucrat::GradeTooHighException::what( void ) const throw() {
	return "GradeTooHighException: grade higher than 1.";
}

const char *Bureaucrat::GradeTooLowException::what( void ) const throw() {
	return "GradeTooLowException: grade lower than 150.";
}
