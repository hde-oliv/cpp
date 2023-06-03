#include "RPN.hpp"

RPN::RPN( void ) : pile() {}

RPN::~RPN( void ) {}

RPN::RPN( RPN const &ref ) { this->pile = ref.pile; }

RPN &RPN::operator=( RPN const &ref ) {
	this->pile = ref.pile;
	return *this;
}

void RPN::storeNumber( int const number ) { this->pile.push( number ); }

void RPN::calculate( char const symbol ) {
	int left = this->pile.top();
	pile.pop();

	int right = this->pile.top();
	pile.pop();

	int result = 0;

	if ( symbol == '-' ) {
		result = right - left;
	} else if ( symbol == '+' ) {
		result = right + left;
	} else if ( symbol == '/' ) {
		result = right / left;
	} else if ( symbol == '*' ) {
		result = right * left;
	}

	this->pile.push( result );
}

int RPN::getResult( void ) {
	if ( this->pile.size() != 1 ) {
		throw std::exception();
	}
	return this->pile.top();
}
