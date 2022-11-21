#ifndef ARRAY_HPP
#define ARRAY_HPP

template<class T>
class Array {
	public:
	Array( void );
	Array( unsigned int n );
	Array( Array const &ref );
	~Array( void );
	Array &operator=( Array const &ref );
	T	  &operator[]( int n );
	int	   size( void ) const;

	private:
	T  *ptr;
	int siz;
};

#endif
