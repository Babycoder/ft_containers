
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
				return (iterator(_data));
			}
			
			iterator end()
			{
				return (iterator(_data + _size));
			}
			
			const_iterator end() const
			{
				return (iterator(_data + _size));
			}

			reverse_iterator rbegin()
			{
				
			}
			
			const_reverse_iterator rbegin() const
			{

			}

			reverse_iterator rend()
			{

			}
			
			const_reverse_iterator rend() const
			{

			}

			//Capacity :
			
			size_type size() const { return _size; }
			
			size_type max_size() const;
			
			void resize (size_type n, value_type val = value_type());
			
			size_type capacity() const{ return _capacity; }
			
			bool empty() const { return !_size; }

			void reserve (size_type n);			
	
			



			
			//Element access
		
			reference operator[](size_type n){ return(_data[n]); }
			const_reference operator[] (size_type n) const { return(_data[n]); }

			reference at(size_type n)
			{	
				if (n > _size - 1)
					throw std::out_of_range("OUT\n"); 
				return(_data[n]);
			}
			const_reference at(size_type n) const { return(_data[n]);}
			
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
				_data[_size] = value;
				_size++;
			}

			// ALLOCATOR :
			allocator_type get_allocator() const { return _alloc;};
		
		private :

			void	realloc(size_t newCapacity)
			{
				value_type* newdata = _alloc.allocate(newCapacity);
				if (newCapacity < _size)
					_size = newCapacity;

				for (size_t i = 0; i < _size; i++)
					newdata[i] = _data[i];

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
}


#endif
