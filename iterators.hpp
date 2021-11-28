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

			iterator(pointer ptr) : _ptr(ptr){};

			reference operator*() const { return *_ptr; };
			pointer   operator->() { return _ptr; };
			
			iterator& operator++() { _ptr++; return *this };
			iterator operator++(T) { iterator tmp = *this; ++(*this); return tmp; };

			friend bool operator==(const iterator& a, const iterator& b) { return a._ptr == b._ptr; };
			friend bool operator!=(const iterator& a, const iterator& b) { return a._ptr != b._ptr; };





		private :
			pointer _ptr;

	};
}

#endif