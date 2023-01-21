#include <cstdlib>
#include <ctime>
#include <iostream>

#include "A.hpp"
#include "B.hpp"
#include "Base.hpp"
#include "C.hpp"

Base *generate( void ) {
	std::srand( std::time( NULL ) );
	int r = std::rand() % 3;

	switch ( r ) {
		case 0:
			return new A();
		case 1:
			return new B();
		case 2:
			return new C();
	}
	return NULL;
}

void identify( Base *p ) {
	A *ptr1 = dynamic_cast<A *>( p );
	if ( ptr1 != NULL ) {
		std::cout << "Type is A." << std::endl;
		return;
	}

	B *ptr2 = dynamic_cast<B *>( p );
	if ( ptr2 != NULL ) {
		std::cout << "Type is B." << std::endl;
		return;
	}

	C *ptr3 = dynamic_cast<C *>( p );
	if ( ptr3 != NULL ) {
		std::cout << "Type is C." << std::endl;
		return;
	}
}

void identify( Base &p ) {
	try {
		A &ref = dynamic_cast<A &>( p );
		std::cout << "Type is A." << std::endl;
		(void)ref;
	} catch ( std::exception &e ) {
		try {
			B &ref = dynamic_cast<B &>( p );
			std::cout << "Type is B." << std::endl;
			(void)ref;
		} catch ( std::exception &e ) {
			try {
				C &ref = dynamic_cast<C &>( p );
				std::cout << "Type is C." << std::endl;
				(void)ref;
			} catch ( std::exception &e ) {
				return;
			}
		}
	}
}

int main( void ) {
	Base *p = generate();
	identify( p );

	Base &r = *p;
	identify( r );
}
