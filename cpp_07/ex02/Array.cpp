#include "Array.hpp"

#include <exception>

template<class T>
Array<T>::Array( void ) {
	this->ptr = new T[];
	this->siz = 0;
}

template<class T>
Array<T>::Array( unsigned int n ) {
	this->ptr = new T[n];
	this->siz = n;
}

template<class T>
Array<T>::Array( Array const &ref ) {
	this->ptr = ref.ptr;
	this->siz = ref.siz;
}

template<class T>
Array<T>::~Array( void ) {
	delete[] this->ptr;
}

// TODO: Verify shallow copy
template<class T>
Array<T> &Array<T>::operator=( Array const &ref ) {
	delete[] this->ptr;
	this->ptr = ref.ptr;
	this->siz = ref.siz;
}

template<class T>
T &Array<T>::operator[]( int n ) {
	if ( n < 0 || n >= this->siz ) {
		throw std::exception( "Out of bounds." );
	}
	return this->ptr[n];
}

template<class T>
int Array<T>::size( void ) const {
	return this->siz;
}
