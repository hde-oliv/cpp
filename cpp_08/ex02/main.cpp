#include <iostream>
#include <stack>
#include <vector>

#include "MutantStack.hpp"

int main() {
	MutantStack<int> mstack;
	std::vector<int> vector;

	mstack.push( 5 );
	mstack.push( 17 );
	mstack.push( 3 );
	mstack.push( 5 );
	mstack.push( 737 );
	mstack.push( 0 );

	vector.push_back( 5 );
	vector.push_back( 17 );
	vector.push_back( 3 );
	vector.push_back( 5 );
	vector.push_back( 737 );
	vector.push_back( 0 );

	vector.pop_back();
	mstack.pop();

	MutantStack<int>::iterator mstack_b = mstack.begin();
	MutantStack<int>::iterator mstack_e = mstack.end();
	std::vector<int>::iterator vector_b = vector.begin();
	std::vector<int>::iterator vector_e = vector.end();

	++mstack_b;
	--mstack_b;

	std::cout << "MutantStack numbers:\n";
	while ( mstack_b != mstack_e ) {
		std::cout << *mstack_b << std::endl;
		++mstack_b;
	}

	std::cout << "vector numbers:\n";
	while ( vector_b != vector_e ) {
		std::cout << *vector_b << std::endl;
		++vector_b;
	}
}
