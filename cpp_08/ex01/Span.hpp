#ifndef SPAN_HPP
#define SPAN_HPP
#include <algorithm>
#include <exception>
#include <iterator>
#include <string>
#include <vector>

class Span {
	public:
	Span( void );
	Span( unsigned int N );
	Span( Span const &ref );
	~Span( void );
	Span &operator=( Span const &ref );
	void  addNumber( int newNumber );

	template<typename T>
	void addRange( T b, T e ) {
		if ( std::distance( b, e ) > ( this->N - (long long)this->vec.size() ) ) {
			throw std::exception();
		}
		while ( b != e ) {
			this->vec.push_back( *b );
			b++;
		}
	}

	unsigned int shortestSpan( void );
	unsigned int longestSpan( void );

	private:
	unsigned int	 N;
	std::vector<int> vec;
};

#endif
