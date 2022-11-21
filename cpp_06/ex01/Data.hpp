#ifndef DATA_HPP
#define DATA_HPP

#include <string>

class Data {
	public:
	Data( void );
	Data( std::string const &name );
	Data( Data const &ref );
	~Data( void );
	Data	   &operator=( Data const &ref );
	std::string getName( void ) const;
	void		setName( std::string const &name );

	private:
	std::string name;
};

#endif
