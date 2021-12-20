
#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <iostream>

// my headers :

#include "../utils/iterators.hpp"
#include "../utils/reverse_iterator.hpp"
#include "../utils/iterators_traits.hpp"
#include "../utils/type_traits.hpp"
#include "../utils/algorithm.hpp"

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
			explicit vector (const allocator_type& alloc = allocator_type())
			{
				_alloc = alloc;
				_size = 0;
				_capacity = 0;
				_data = _alloc.allocate(_capacity);
			}

			explicit vector (size_type n, const value_type& val = value_type(),
										const allocator_type& alloc = allocator_type())
			{
				_alloc = alloc;
				_size = 0;
				_capacity = n;
				_data = _alloc.allocate(_capacity);
				while (n--)
					push_back(val);
			}

			template <class InputIterator>
			vector (InputIterator first, InputIterator last,const allocator_type& alloc = allocator_type(),
										typename ft::enable_if<!ft::is_integral<InputIterator>::value>::type* = 0)
			{
				_alloc = alloc;
				_size = 0;
				_capacity = std::distance(first, last);
				_data = _alloc.allocate(_capacity);
				
				while(first != last) 
				{
					push_back(*first);
					first++;
				}
			}

			vector (const vector& x)
			{
				const_iterator first = x.begin();
				const_iterator last = x.end();

				_alloc = x.get_allocator();
				_size = 0;
				_capacity = x.capacity();
				_data = _alloc.allocate(_capacity);
				
				while(first != last)
				{
					push_back(*first);
					first++;
				}
			}
			
			// Operator :

			 vector& operator= (const vector& x)
			 {
				if (this != &x)
				 	assign(x.begin(), x.end());
				return *this;
			 }
		
			// DESTRUCTOR :
			
			~vector()
			{
				clear();
				_alloc.deallocate(_data, _capacity);
			}

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
				if (n > _capacity)
					realloc(n);

				if (n < _size)
				{
					for (iterator it = begin() + n; it != end(); ++it)
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
				if (_size + 1 > _capacity)
				{
					if (_capacity == 0)
						realloc(1);
					else
						realloc(_capacity * 2);
				}
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
				size_type n = std::distance(first, last);

				if (n < _size)
				{
					clear();
					while(first != last)
						push_back(*first++);
				}
				else
				{
					clear();
					realloc(n);
					while(first != last)
						push_back(*first++);

				}
			}

			void assign (size_type n, const value_type& val)
			{
				if (n < _size)
				{
					clear();
					while(n--)
						push_back(val);
				}
				else
				{
					clear();
					realloc(n);
					while(n--)
						push_back(val);

				}
			}

			iterator erase (iterator position)
			{
				_alloc.destroy(&(*position));
			
				for (size_type i = &(*position) - _data; i < _size; ++i)
				{
					_alloc.construct(_data + i, *(_data + i + 1));
					_alloc.destroy(_data + i + 1);
				}
				--_size;
				return position;
			}
			
			iterator erase (iterator first, iterator last)
			{
				size_type			n = std::distance(first, last);
				iterator tmp = first;
				
				for(iterator it_last = last; it_last != end(); it_last++)
					*(tmp++) = *it_last;
				while(n--)
					pop_back();
				return first;
			}

			void swap (vector& x)
			{
				std::swap(_data, x._data);
				std::swap(_size, x._size);
				std::swap(_capacity, x._capacity);
				std::swap(_alloc, x._alloc);
			}

			iterator insert (iterator position, const value_type& val)
			{
				size_type dis = std::distance(begin(), position);

				insert(position, 1, val);
				return (iterator(_data + dis));
			}
			
			void insert (iterator position, size_type n, const value_type& val)
			{
				vector tmp(position, end());


				iterator it_end = end();
				
				while(it_end != position)
				{
					pop_back();
					--it_end;
				}	
				
				while (n) {
					push_back(val);
					--n;
				}
				
				iterator it = tmp.begin();
				while (it != tmp.end()) {
					push_back(*it);
					++it;
				}
				/*size_type v = n;
				
				if (n + _size > _capacity)
				{
					size_type i = 0;
					value_type *newdata = _alloc.allocate(n + _size);
					iterator it_new = begin();
					while(it_new != position)
					{
						_alloc.construct(newdata + i++, *it_new);
						_alloc.destroy(&(*it_new));
						it_new++;
					}
					for(size_type j = 0; j < n; j++)
					{
						_alloc.construct(newdata + i++, val);
					}
					while(it_new != end())
					{
						_alloc.construct(newdata + i++, *it_new);
						_alloc.destroy(&(*it_new));
						it_new++;
					}
					_alloc.deallocate(_data, _capacity);
					_data = newdata;
					_capacity = _size + n;
				}
				else
				{
					size_type tmp = n;
					reverse_iterator r_it = rbegin();
					while(&(*r_it) != &(*position))
					{
						_alloc.construct(_data + _size + tmp--, *r_it);
						_alloc.destroy(&(*r_it));
						r_it++;
					}
					for(size_type i = 0; i < n; i++)
					{
						_alloc.construct(&(*position), val);
						position++;
					}
				}
				_size += v;*/
			}

			template <class InputIterator>
			void insert (iterator position, InputIterator first, InputIterator last,
							typename ft::enable_if<!ft::is_integral<InputIterator>::value>::type* = 0)
			{
				vector tmp(position, end());

				iterator it_end = end();
				
				while(it_end != position)
				{
					pop_back();
					--it_end;
				}	
				
				while(first != last)
					push_back(*first++);

				iterator it = tmp.begin();
				while (it != tmp.end()) {
					push_back(*it);
					++it;
				}
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
