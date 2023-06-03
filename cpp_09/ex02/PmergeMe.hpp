#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <exception>
#include <fstream>
#include <iostream>
#include <iterator>
#include <list>
#include <map>
#include <sstream>
#include <stack>
#include <string>
#include <vector>
#include <iomanip>

class PmergeMe {
	typedef std::deque<int>			   i_deque;
	typedef std::vector<int>		   i_vector;
	typedef std::vector<int>::iterator i_vector_it;

	public:
	PmergeMe( void );
	PmergeMe( PmergeMe const &ref );
	PmergeMe( char **list, int size );
	~PmergeMe( void );
	PmergeMe &operator=( PmergeMe const &ref );
	void	  run( void );

	private:
	i_deque	 d;
	i_vector v;

	std::clock_t vectorTime;
	std::clock_t dequeTime;

	void vectorMergeInsertionSort( void );
	void dequeMergeInsertionSort( void );
};

bool pcompare( std::pair<int, int> a, std::pair<int, int> b );

#endif
