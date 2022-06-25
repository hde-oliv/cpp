#include "PhoneBook.hpp"

#include <iostream>

#include "Contact.hpp"

PhoneBook::PhoneBook( void ) { this->size = 0; }
PhoneBook::~PhoneBook( void ) {}

Contact PhoneBook::getContact( int index ) const { return this->contacts[index]; }

void PhoneBook::setContact( std::string firstName, std::string lastName, std::string nickName, std::string phoneNumber,
							std::string darkestSecret ) {
	Contact *aContact = &this->contacts[nextContactSlot];
	aContact->setFirstName( firstName );
	aContact->setLastName( lastName );
	aContact->setNickName( nickName );
	aContact->setPhoneNumber( phoneNumber );
	aContact->setDarkestSecret( darkestSecret );
	aContact->setIndex( nextContactSlot );
	nextContactSlot = ( nextContactSlot + 1 ) % 8;
	if ( this->size < 8 ) this->size++;
}

int PhoneBook::getSize() const { return this->size; }

int PhoneBook::nextContactSlot = 0;
