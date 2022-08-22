#include <cstdlib>
#include <iostream>
#include <sstream>

#include "Contact.hpp"
#include "PhoneBook.hpp"

const std::string ACCEPTABLE_COMMANDS[] = { "ADD", "SEARCH", "EXIT" };

std::string getInput( std::string prompt ) {
	std::string input;

	std::cout << prompt;
	std::getline( std::cin, input );
	return input;
}

std::string getNonEmptyInput( std::string prompt ) {
	do {
		std::string input = getInput( prompt );
		if ( std::cin.fail() ) return "";
		if ( input.empty() )
			std::cout << "Please enter a non-empty string." << std::endl;
		else
			return input;
	} while ( true );
}

std::string getCommandLoop( void ) {
	do {
		std::string command = getNonEmptyInput( "Enter command: " );
		if ( std::cin.fail() ) return "";
		for ( int i = 0; i < 3; i++ )
			if ( !command.compare( ACCEPTABLE_COMMANDS[i] ) ) return command;
	} while ( true );
}

int getContactIndex( int phoneBookSize ) {
	int				  index;
	std::stringstream ss;
	std::string contactIndex = getNonEmptyInput( "Enter contact index: " );

	ss << contactIndex;
	ss >> index;

	if ( std::cin.fail() ) return -1;
	if ( index >= phoneBookSize || index < 0 ) {
		std::cout << "Contact index out of range." << std::endl;
		return getContactIndex( phoneBookSize );
	}
	return index;
}

int main( void ) {
	std::string command;
	PhoneBook	aPhoneBook;

	while ( true ) {
		command = getCommandLoop();
		if ( std::cin.fail() ) return 1;
		if ( command == "EXIT" ) {
			break;
		} else if ( command == "ADD" ) {
			std::cout << std::endl;

			std::string firstName = getNonEmptyInput( "Enter first name: " );
			std::string lastName  = getNonEmptyInput( "Enter last name: " );
			std::string nickName  = getNonEmptyInput( "Enter nick name: " );
			std::string phoneNumber =
				getNonEmptyInput( "Enter phone number: " );
			std::string darkestSecret =
				getNonEmptyInput( "Enter darkest secret: " );

			aPhoneBook.setContact( firstName, lastName, nickName, phoneNumber,
								   darkestSecret );

			std::cout << "Contact added." << std::endl << std::endl;
		} else if ( command == "SEARCH" ) {
			std::cout << " |Index     |F. Name   |L. Name   |N. Name   | "
					  << std::endl;

			for ( int i = 0; i < aPhoneBook.getSize(); i++ ) {
				std::cout << aPhoneBook.getContact( i ).toFormat() << std::endl;
			}

			std::cout << std::endl;

			int index = getContactIndex( aPhoneBook.getSize() );
			if ( std::cin.fail() ) return 1;
			std::cout << aPhoneBook.getContact( index ).toString() << std::endl;

			std::cout << std::endl;
		}
	}
	return 0;
}
