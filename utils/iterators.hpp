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
 			typedef		std::random_access_iterator_tag	iterator_category;

			iterator(pointer ptr) : _ptr(ptr){};
			iterator(const iterator<T>& src) : _ptr(src._ptr) {}
			iterator() : _ptr(){};
			~iterator(){};

			operator iterator<const T>() 
            {
                return iterator<const T>(_ptr);
            }
			
			iterator& operator=(const iterator& rhs){this->_ptr = rhs._ptr; return *this; }

			reference operator*() { return *_ptr; };
			pointer   operator->() { return _ptr; };
			
			iterator& operator++() { _ptr++; return *this; };
			iterator operator++(int) { iterator tmp = *this; _ptr++; return tmp; };

			iterator& operator--() { _ptr--; return *this; };
			iterator operator--(int) { iterator tmp = *this; _ptr--; return tmp; };

			iterator operator+(const difference_type n) const { return  (_ptr + n); };
			iterator operator-(const difference_type n) const { return  (_ptr - n); };
			
			
			iterator&  operator+=(const difference_type n) { _ptr = _ptr + n; return *this; };
			iterator&  operator-=(const difference_type n) { _ptr = _ptr - n; return *this; };

			difference_type operator-(iterator<T> const & src){return(this->_ptr - src._ptr);}
			
			reference operator[](difference_type n) const {return *(_ptr + n); }

			pointer base() const
			{
				return(_ptr);
			}

			template <typename B, typename A>
			friend bool operator== (const iterator<B>& lhs,const iterator<A>& rhs);
			
			template <typename B, typename A>
			friend bool operator!= (const iterator<B>& lhs, const iterator<A>& rhs);
			
			template <typename B, typename A>
			friend bool operator<(const iterator<B>& lhs,const iterator<A>& rhs);
			
			template <typename B, typename A>
			friend bool operator<=(const iterator<B>& lhs,const iterator<A>& rhs);
			
			template <typename B, typename A>
			friend bool operator>(const iterator<B>& lhs,const iterator<A>& rhs);
			
			template <typename B, typename A>
			friend bool operator>=(const iterator<B>& lhs,const iterator<A>& rhs);

		private :
			pointer _ptr;

	};

	template <typename B, typename A>
 	bool operator== (const iterator<B>& lhs,const iterator<A>& rhs)
	{
		return (lhs._ptr == rhs._ptr);
	}
	
	template <typename B,typename A>
  	bool operator!= (const iterator<B>& lhs,const iterator<A>& rhs)
	{
		
		return (lhs._ptr != rhs._ptr);
  	}
	
	template <typename B,typename A>
	bool operator<(const iterator<B>& lhs,const iterator<A>& rhs)
	{
		return (lhs._ptr < rhs._ptr);
	}
	
	template <typename B,typename A>
	bool operator<=(const iterator<B>& lhs,const iterator<A>& rhs)
	{
		return (lhs._ptr <= rhs._ptr);
	}
	
	template <typename B,typename A>
	bool operator>(const iterator<B>& lhs,const iterator<A>& rhs)
	{
		return (lhs._ptr > rhs._ptr);
	}
	
	template <typename B,typename A>
	bool operator>=(const iterator<B>& lhs,const iterator<A>& rhs)
	{
		return (lhs._ptr >= rhs._ptr);
	}
	
	template <typename B>
	iterator<B> operator+ (typename iterator<B>::difference_type n, const iterator<B>& it)
	{
		return(it + n);
	}
}

#endif
