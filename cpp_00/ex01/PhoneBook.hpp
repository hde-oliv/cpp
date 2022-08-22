#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"

class PhoneBook {
	public:
	PhoneBook( void );
	~PhoneBook( void );
	Contact getContact( int index ) const;
	void	setContact( std::string firstName, std::string lastName,
						std::string nickName, std::string phoneNumber,
						std::string darkestSecret );
	int		getSize( void ) const;

	private:
	Contact	   contacts[8];
	static int nextContactSlot;
	int		   size;
};

#endif
