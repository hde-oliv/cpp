#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <exception>
#include <stdexcept>

template<class T>
class Array {
	public:
	Array<T>( void ) {
		this->ptr = NULL;
		this->siz = 0;
	}

	Array<T>( unsigned int n ) {
		this->ptr = new T[n];
		this->siz = n;
	}

	Array<T>( Array<T> const &ref ) {
		this->ptr = new T[ref.siz];
		this->siz = ref.siz;

		for ( int i = 0; i < ref.siz; i++ ) {
			ptr[i] = ref.ptr[i];
		}
	}

	~Array<T>( void ) { delete[] this->ptr; }

	Array<T> &operator=( Array<T> const &ref ) {
		if ( this->ptr ) {
			delete[] this->ptr;
		}

		this->ptr = new T[ref.siz];
		this->siz = ref.siz;

		for ( int i = 0; i < ref.siz; i++ ) {
			ptr[i] = ref.ptr[i];
		}
		return *this;
	}

	T &operator[]( int n ) {
		if ( n < 0 || n >= this->siz ) {
			throw std::exception();
		}
		return this->ptr[n];
	}

	int size( void ) const { return this->siz; };

	private:
	T  *ptr;
	int siz;
};

#endif
