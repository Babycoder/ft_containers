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
			iterator(iterator const &src) { this->_ptr = src._ptr;};
			iterator(){};
			~iterator(){};
			
			iterator& operator=(const iterator& rhs){this->_ptr = rhs._ptr; return *this; }
			
			reference operator*() { return *_ptr; };
			pointer   operator->() { return _ptr; };
			
			iterator& operator++() { _ptr++; return *this; };
			iterator operator++(int) { iterator tmp = *this; ++(*this); return tmp; };

			iterator operator--() { _ptr--; return *this; };
			iterator& operator--(int) { iterator tmp = *this; --(*this); return tmp; };

			iterator& operator+(const difference_type n) { return  (_ptr + n); };
			iterator& operator-(const difference_type n) { return  (_ptr - n); };
			iterator& operator-(iterator& rhs) { return  _ptr = _ptr - rhs.ptr;};
			
			iterator&  operator+=(const difference_type n) { _ptr = _ptr + n; return *this; };
			iterator&  operator-=(const difference_type n) { _ptr = _ptr - n; return *this; };

			reference operator[](difference_type n) const {return *(_ptr + n); }

			//bool operator==(const iterator& rhs) const{ return this->_ptr == rhs._ptr; };
			friend bool operator== (const iterator<T>& lhs,const iterator<T>& rhs);
			
			bool operator!=(const iterator& rhs) const{ return this->_ptr != rhs._ptr; };

			bool operator<(const iterator& rhs)const { return this->_ptr < rhs._ptr; };
			bool operator<=(const iterator& rhs)const { return this->_ptr <= rhs._ptr; };
			bool operator>(const iterator& rhs)const { return this->_ptr > rhs._ptr; };
			bool operator>=(const iterator& rhs)const { return this->_ptr >= rhs._ptr; };
			
		private :
			pointer _ptr;

	};

	template <typename T>
 	bool operator== (const iterator<T>& lhs,const iterator<T>& rhs)
	{
		return (lhs._ptr == rhs._ptr);
	}

}

#endif