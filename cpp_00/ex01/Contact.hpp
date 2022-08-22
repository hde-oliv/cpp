#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <iostream>
#include <string>

class Contact {
	public:
	Contact( std::string firstName, std::string lastName, std::string nickName,
			 std::string phoneNumber, std::string darkestSecret );
	Contact( void );
	~Contact( void );
	std::string getFirstName( void ) const;
	std::string getLastName( void ) const;
	std::string getNickName( void ) const;
	std::string getPhoneNumber( void ) const;
	std::string getDarkestSecret( void ) const;
	void		setFirstName( std::string firstName );
	void		setLastName( std::string lastName );
	void		setNickName( std::string nickName );
	void		setPhoneNumber( std::string phoneNumber );
	void		setDarkestSecret( std::string darkestSecret );
	std::string toString( void ) const;
	std::string toFormat( void ) const;
	void		setIndex( int index );

	private:
	int			index;
	std::string firstName;
	std::string lastName;
	std::string nickName;
	std::string phoneNumber;
	std::string darkestSecret;
	std::string formatField( std::string field ) const;
};

#endif
