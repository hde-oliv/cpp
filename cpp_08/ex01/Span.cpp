#include "Span.hpp"

#include <algorithm>
#include <exception>
#include <iostream>
#include <string>
#include <vector>

Span::Span( void ) { this->N = 0; }

Span::Span( unsigned int N ) {
	this->N	  = N;
	this->vec = std::vector<int>();
}

Span::Span( Span const &ref ) {
	this->N	  = ref.N;
	this->vec = ref.vec;
}

Span::~Span( void ) {}

Span &Span::operator=( Span const &ref ) {
	this->N	  = ref.N;
	this->vec = ref.vec;
	return *this;
}

void Span::addNumber( int newNumber ) {
	if ( this->vec.size() == this->N ) {
		throw std::exception();
	}
	this->vec.push_back( newNumber );
}

unsigned int Span::longestSpan( void ) {
	if ( this->vec.size() < 2 ) {
		throw std::exception();
	}

	std::vector<int>::iterator s = std::min_element( this->vec.begin(), this->vec.end() );
	std::vector<int>::iterator l = std::max_element( this->vec.begin(), this->vec.end() );

	return ( *l - *s );
}

unsigned int Span::shortestSpan( void ) {
	if ( this->vec.size() < 2 ) {
		throw std::exception();
	}

	std::sort( this->vec.begin(), this->vec.end() );

	std::vector<int>::iterator first  = this->vec.begin();
	std::vector<int>::iterator second = ++( this->vec.begin() );

	int shortestSpan = *second - *first;

	while ( second != this->vec.end() ) {
		if ( ( *second - *first ) < shortestSpan ) {
			shortestSpan = *second - *first;
		}
		first = second;
		second++;
	}

	return shortestSpan;
}
