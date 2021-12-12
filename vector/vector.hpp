
#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <iostream>

// my headers :

#include "../iterators.hpp"
#include "../reverse_iterator.hpp"
#include "../iterators_traits.hpp"
#include "../type_traits.hpp"
#include "../algorithm.hpp"

/*******************************************/

namespace ft
{	
	template < class T, class Allocator = std::allocator<T> >
	class vector{
		 
		public	:

			// MEMBER TYPES :
			typedef T															value_type;
			typedef Allocator													allocator_type;
			typedef typename allocator_type::reference							reference;
			typedef typename allocator_type::const_reference					const_reference;
			typedef typename allocator_type::pointer							pointer;
			typedef typename allocator_type::const_pointer						const_pointer;
			typedef ft::iterator<value_type>									iterator;
			typedef ft::iterator<const value_type>								const_iterator;
			typedef ft::reverse_iterator<iterator>								reverse_iterator;
			typedef ft::reverse_iterator<const_iterator>						const_reverse_iterator;
			typedef typename ft::iterator_traits<iterator>::difference_type 	difference_type;
			typedef size_t														size_type;



			// CONSTRUCTORS :

			vector (const allocator_type& alloc = allocator_type())
			{
				_alloc = alloc;
				_size = 0;
				_capacity = 0;
				_data = _alloc.allocate(_capacity);
			}
		
			// DESTRUCTOR :
			
			~vector(){};

			/********************** MEMBER FUNCTIONS ****************************/
			

			//Iterators :

			iterator begin()
			{
				return (iterator(_data));
			}
			
			const_iterator begin() const
			{
				return (const_iterator(_data));
			}
			
			iterator end()
			{
				return (iterator(_data + _size));
			}
			
			const_iterator end() const
			{
				return (const_iterator(_data + _size));
			}

			reverse_iterator rbegin()
			{
				return reverse_iterator(end());	
			}
			
			const_reverse_iterator rbegin() const
			{
				return const_reverse_iterator(end());
			}

			reverse_iterator rend()
			{
				return reverse_iterator(begin());
			}			
			
			const_reverse_iterator rend() const
			{
				return const_reverse_iterator(begin());
			}

			//Capacity :
			
			size_type size() const { return _size; }
			
			size_type max_size() const{return _alloc.max_size();}
			
			size_type capacity() const{ return _capacity; }
			
			bool empty() const { return _size == 0; }
			
			void resize (size_type n, value_type val = value_type())
			{
				iterator it;
			
				if (n < _size)
				{
					for (it = begin() + n; it != end(); ++it)
						pop_back();
				}
			 	else if (n > _size)
				{
					for (size_type i = _size; i != n; ++i)
						push_back(val);
				}
				_size = n;
			}

			void reserve (size_type n)
			{
				if (n > max_size())
					throw std::length_error("n is greater than max_size");
				if (n > _capacity)
					realloc(n);
				return ;
			}
	
			
			//Element access
		
			reference operator[](size_type n){ return(_data[n]); }
			const_reference operator[] (size_type n) const { return(_data[n]); }

			
			reference at(size_type n)
			{
				if (n > _size - 1)
					throw std::out_of_range("index OUT of range\n");  
				return(_data[n]);
			}
			const_reference at(size_type n) const
			{	
				if (n > _size - 1)
					throw std::out_of_range("index OUT of range\n"); 
				return(_data[n]);
			}
			
			reference front(){return(_data[0]);}
			const_reference front() const {return(_data[0]);}

			reference back(){return(_data[_size - 1]);}
			const_reference back() const {return(_data[_size - 1]);}

	
			// Modifiers
			
			void	push_back(const T& value )
			{
				if (_capacity == 0)
					_capacity = 1;
				if (_size >= _capacity)
					realloc(_capacity * 2);
				_alloc.construct(_data + _size++, value);
			}

			void	pop_back()
			{
				_alloc.destroy(_data + --_size); 
			}

			void clear()
			{
				size_type tmp = _size;
			
				for (size_type i = 0; i < tmp; i++)
					pop_back();
			}

			template <class InputIterator>
			void assign (InputIterator first, InputIterator last,
					typename ft::enable_if<!ft::is_integral<InputIterator>::value>::type* = 0)
			{
				clear();
				while(first != last)
				{
					push_back(*first);
					first++;
				}
			}

			void assign (size_type n, const value_type& val)
			{
				clear();
				while(n--)
					push_back(val);
			}

			iterator erase (iterator position);
			iterator erase (iterator first, iterator last);

			void swap (vector& x)
			{
				std::swap(_data, x._data);
				std::swap(_size, x._size);
				std::swap(_capacity, x._capacity);
				std::swap(_alloc, x._alloc);
			}

			// ALLOCATOR :
			allocator_type get_allocator() const { return _alloc;};
		
		private :

			void	realloc(size_type newCapacity)
			{
				value_type* newdata = _alloc.allocate(newCapacity);
				if (newCapacity < _size)
					_size = newCapacity;

				for (size_type i = 0; i < _size; i++)
				{
					_alloc.construct(newdata + i, _data[i]);
					_alloc.destroy(_data + i);
				}

				_alloc.deallocate(_data, _capacity);
				_data = newdata;
				_capacity =	newCapacity;
			}

		private :
			value_type		*_data;
			size_type		_size;
			size_type		_capacity;
			allocator_type	_alloc;
	 };

	 //Non-member function overloads :

	template <class T, class Alloc>
  	bool operator== (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
	{
		if (lhs.size() != rhs.size())
			return false;
		return ft::equal(lhs.begin(), lhs.end(), rhs.begin());
	}

	template <class T, class Alloc>
	bool operator!= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
	{
		return !operator==(lhs, rhs);
	}

	template <class T, class Alloc>
  	bool operator<  (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
	{
		return ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end());
	}

	template <class T, class Alloc>
  	bool operator<= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
	{
		return operator<(lhs, rhs) || operator==(lhs, rhs);
	}

	template <class T, class Alloc>
  	bool operator>  (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
	{
		return !operator<(lhs, rhs) && !operator==(lhs, rhs);
	}

	template <class T, class Alloc>
  	bool operator>= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
	{
			return !operator< (lhs, rhs);
	}
	template <class T, class Alloc>
  	void swap (vector<T,Alloc>& x, vector<T,Alloc>& y)
	{
		x.swap(y);
	}

}

#endif
