#ifndef ITERATORS_HPP
#define ITERATORS_HPP


#include <iostream>

namespace ft {

	template <typename T>
	class iterator
	{
		public :
			typedef		T& reference; 
			typedef		T* pointer;
			typedef 	std::ptrdiff_t difference_type;
			typedef		T value_type;

	};
}

#endif