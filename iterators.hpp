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
			iterator(const iterator<T>& src) : _ptr(src._ptr) {}
			iterator() : _ptr(){};
			~iterator(){};
			
			iterator& operator=(const iterator& rhs){this->_ptr = rhs._ptr; return *this; }

			reference operator*() { return *_ptr; };
			pointer   operator->() { return _ptr; };
			
			iterator& operator++() { _ptr++; return *this; };
			iterator operator++(int) { iterator tmp = *this; _ptr++; return tmp; };

			iterator& operator--() { _ptr--; return *this; };
			iterator operator--(int) { iterator tmp = *this; _ptr--; return tmp; };

			iterator& operator+(const difference_type n) { return  (_ptr + n); };
			iterator& operator-(const difference_type n) { return  (_ptr - n); };
			
			
			iterator&  operator+=(const difference_type n) { _ptr = _ptr + n; return *this; };
			iterator&  operator-=(const difference_type n) { _ptr = _ptr - n; return *this; };

			
			iterator& operator-(iterator& rhs) { return  _ptr = _ptr - rhs.ptr;};
			reference operator[](difference_type n) const {return *(_ptr + n); }

			
			friend bool operator==(const iterator<T>& lhs,const iterator<T>& rhs);
			friend bool operator!=(const iterator<T>& lhs, const iterator<T>& rhs);
			friend bool operator<(const iterator<T>& lhs,const iterator<T>& rhs);
			friend bool operator<=(const iterator<T>& lhs,const iterator<T>& rhs);
			friend bool operator>(const iterator<T>& lhs,const iterator<T>& rhs);
			friend bool operator>=(const iterator<T>& lhs,const iterator<T>& rhs);

		private :
			pointer _ptr;

	};

	template <typename T>
 	bool operator== (const iterator<T>& lhs,const iterator<T>& rhs)
	{
		return (lhs._ptr == rhs._ptr);
	}

	template <typename T>
  	bool operator!= (const iterator<T>& lhs, const iterator<T>& rhs)
	{
		return (lhs._ptr != rhs._ptr);
  	}

	template <typename T>
	bool operator<(const iterator<T>& lhs,const iterator<T>& rhs)
	{
		return (lhs._ptr < rhs._ptr);
	}

	template <typename T>
	bool operator<=(const iterator<T>& lhs,const iterator<T>& rhs)
	{
		return (lhs._ptr <= rhs._ptr);
	}

	template <typename T>
	bool operator>(const iterator<T>& lhs,const iterator<T>& rhs)
	{
		return (lhs._ptr > rhs._ptr);
	}

	template <typename T>
	bool operator>=(const iterator<T>& lhs,const iterator<T>& rhs)
	{
		return (lhs._ptr >= rhs._ptr);
	}

	template <typename T>
	iterator<T> operator+ (typename iterator<T>::difference_type n, const iterator<T>& it)
	{
		return(n + it._ptr);
	}
}

#endif
