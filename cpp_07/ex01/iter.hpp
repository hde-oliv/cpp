#ifndef ITER_HPP
#define ITER_HPP

template<typename T>
void iter( T *array, int length, T ( *func )( T ) ) {
	for ( int i = 0; i < length; i++ ) {
		func( array[i] );
	}
}

#endif
