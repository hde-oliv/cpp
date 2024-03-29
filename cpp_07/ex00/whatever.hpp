#ifndef WHATEVER_HPP
#define WHATEVER_HPP

template<typename T>
void swap( T &rhs, T &lhs ) {
	T tmp = rhs;
	rhs	  = lhs;
	lhs	  = tmp;
}

template<typename T>
T &min( T &rhs, T &lhs ) {
	return rhs >= lhs ? lhs : rhs;
}

template<typename T>
T &max( T &rhs, T &lhs ) {
	return rhs <= lhs ? lhs : rhs;
}

#endif
