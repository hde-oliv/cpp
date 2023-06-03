#include "PmergeMe.hpp"

PmergeMe::PmergeMe( void ) : d(), v() {}

PmergeMe::~PmergeMe( void ) {}

PmergeMe::PmergeMe( char **list, int size ) : d(), v() {
	for ( int i = 0; i < size; i++ ) {
		this->d.push_back( std::atoi( list[i] ) );
	}
	for ( int i = 0; i < size; i++ ) {
		this->v.push_back( std::atoi( list[i] ) );
	}
}

PmergeMe::PmergeMe( PmergeMe const &ref ) {
	this->v = ref.v;
	this->d = ref.d;
}

PmergeMe &PmergeMe::operator=( PmergeMe const &ref ) {
	if ( this != &ref ) {
		this->d = ref.d;
		this->v = ref.v;
	}
	return *this;
}

void PmergeMe::run( void ) {
	std::cout << "Before: ";
	for ( size_t i = 0; i < this->v.size(); i++ ) {
		std::cout << v[i] << " ";
	}
	std::cout << std::endl;

	this->vectorMergeInsertionSort();
	this->dequeMergeInsertionSort();

	std::cout << "After: ";
	for ( size_t i = 0; i < this->v.size(); i++ ) {
		std::cout << v[i] << " ";
	}
	std::cout << std::endl;

	std::cout <<  std::fixed << std::setprecision(4) << "Time to process a range of " << this->v.size()
			  << " elements with std::vector : " << this->vectorTime << " us"
			  << std::endl;

	std::cout <<  std::fixed << std::setprecision(4) << "Time to process a range of " << this->v.size()
			  << " elements with std::deque : " << this->dequeTime << " us"
			  << std::endl;
}

void PmergeMe::vectorMergeInsertionSort( void ) {
	std::clock_t start = std::clock();

	for ( size_t i = 0; i < this->v.size() - 1; i = i + 2 ) {
		if ( this->v[i] > this->v[i + 1] ) {
			std::swap( this->v[i], this->v[i + 1] );
		}
	}

	std::vector<std::pair<int, int> > pairs;

	for ( size_t i = 0; i < this->v.size() - 1; i = i + 2 ) {
		pairs.push_back( std::make_pair( this->v[i], this->v[i + 1] ) );
	}

	int last = *(--this->v.end());

	std::sort( pairs.begin(), pairs.end(), pcompare );

	std::vector<int> sorted;

	std::vector<std::pair<int, int> >::iterator it = pairs.begin();

	for ( ; it != pairs.end(); it++ ) {
		sorted.push_back( it->second );
	}

	for ( it = pairs.begin(); it != pairs.end(); it++ ) {
		std::vector<int>::iterator it2 =
			std::lower_bound( sorted.begin(), sorted.end(), it->first );
		sorted.insert( it2, it->first );
	}

	if ( this->v.size() % 2 != 0 ) {
		sorted.insert(
			std::lower_bound( sorted.begin(), sorted.end(), last ),
			last );
	}

	this->v			 = sorted;
	this->vectorTime = std::clock() - start;
}

void PmergeMe::dequeMergeInsertionSort( void ) {
	std::clock_t start = std::clock();

	for ( size_t i = 0; i < this->d.size() - 1; i = i + 2 ) {
		if ( this->d[i] > this->d[i + 1] ) {
			std::swap( this->d[i], this->d[i + 1] );
		}
	}

	std::deque<std::pair<int, int> > pairs;

	for ( size_t i = 0; i < this->d.size() - 1; i = i + 2 ) {
		pairs.push_back( std::make_pair( this->d[i], this->d[i + 1] ) );
	}

	int last = *(--this->d.end());

	std::sort( pairs.begin(), pairs.end(), pcompare );

	std::deque<int> sorted;

	std::deque<std::pair<int, int> >::iterator it = pairs.begin();

	for ( ; it != pairs.end(); it++ ) {
		sorted.push_back( it->second );
	}

	for ( it = pairs.begin(); it != pairs.end(); it++ ) {
		std::deque<int>::iterator it2 =
			std::lower_bound( sorted.begin(), sorted.end(), it->first );
		sorted.insert( it2, it->first );
	}

	if ( this->d.size() % 2 != 0 ) {
		sorted.insert(
			std::lower_bound( sorted.begin(), sorted.end(), last ),
			last );
	}

	this->d			= sorted;
	this->dequeTime = std::clock() - start;
}

bool pcompare( std::pair<int, int> a, std::pair<int, int> b ) {
	return ( a.second < b.second );
}
