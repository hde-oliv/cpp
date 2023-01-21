#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>

template<typename T>
void printIt( T const &it ) {
	std::cout << it << std::endl;
}

template<typename T>
void iter( T *array, int length, void( func )( T & ) ) {
	for ( int i = 0; i < length; i++ ) {
		func( array[i] );
	}
}

template<typename T>
void iter( T *array, int length, void( func )( T * ) ) {
	for ( int i = 0; i < length; i++ ) {
		func( &( array[i] ) );
	}
}

template<typename T>
void iter( T *array, int length, void( func )( T const * ) ) {
	for ( int i = 0; i < length; i++ ) {
		func( &( array[i] ) );
	}
}

template<typename T>
void iter( T *array, int length, void( func )( T const & ) ) {
	for ( int i = 0; i < length; i++ ) {
		func( array[i] );
	}
}

#endif
