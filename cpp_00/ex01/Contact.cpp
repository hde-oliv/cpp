#include "Contact.hpp"

#include <iostream>
#include <sstream>
#include <string>

Contact::Contact( std::string firstName, std::string lastName,
				  std::string nickName, std::string phoneNumber,
				  std::string darkestSecret ) {
	this->firstName		= firstName;
	this->lastName		= lastName;
	this->nickName		= nickName;
	this->phoneNumber	= phoneNumber;
	this->darkestSecret = darkestSecret;
}

Contact::Contact( void ) {}

Contact::~Contact( void ) {}

std::string Contact::getFirstName( void ) const { return this->firstName; }
std::string Contact::getLastName( void ) const { return this->lastName; }
std::string Contact::getNickName( void ) const { return this->nickName; }
std::string Contact::getPhoneNumber( void ) const { return this->phoneNumber; }
std::string Contact::getDarkestSecret( void ) const {
	return this->darkestSecret;
}
void Contact::setIndex( int index ) { this->index = index; }

void Contact::setFirstName( std::string firstName ) {
	this->firstName = firstName;
}
void Contact::setLastName( std::string lastName ) { this->lastName = lastName; }
void Contact::setNickName( std::string nickName ) { this->nickName = nickName; }
void Contact::setPhoneNumber( std::string phoneNumber ) {
	this->phoneNumber = phoneNumber;
}
void Contact::setDarkestSecret( std::string darkestSecret ) {
	this->darkestSecret = darkestSecret;
}

std::string Contact::toString( void ) const {
	std::string result = "";

	result.append( this->firstName + "\n" );
	result.append( this->lastName + "\n" );
	result.append( this->nickName + "\n" );
	result.append( this->phoneNumber + "\n" );
	result.append( this->darkestSecret );
	return result;
}

std::string Contact::toFormat( void ) const {
	std::string		  result = "";
	std::stringstream ss;
	std::string		  index;

	ss << this->index;
	ss >> index;
	result.append( " |" );
	result.append( index );
	result.append( "         |" );
	result.append( this->formatField( this->firstName ) );
	result.append( "|" );
	result.append( this->formatField( this->lastName ) );
	result.append( "|" );
	result.append( this->formatField( this->nickName ) );
	result.append( "| " );
	return result;
}

std::string Contact::formatField( std::string field ) const {
	std::string columnTemplate = "          ";
	if ( field.length() > 10 ) {
		columnTemplate.replace( 9, 1, "." );
		columnTemplate.replace( 0, 9, this->firstName.substr( 0, 9 ) );
		return columnTemplate;
	} else {
		return columnTemplate.replace( 0, field.length(), field );
	}
}
