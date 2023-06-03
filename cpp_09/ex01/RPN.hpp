#ifndef RPN_HPP
#define RPN_HPP

#include <exception>
#include <fstream>
#include <iostream>
#include <stack>
#include <string>

class RPN {
	typedef std::stack<int> i_stack;

	public:
	RPN( void );
	RPN( RPN const &ref );
	~RPN( void );
	RPN &operator=( RPN const &ref );
	void storeNumber( int const number );
	void calculate( char const symbol );
	int	 getResult( void );

	private:
	i_stack pile;
};

#endif
