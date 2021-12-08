
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
			
			typedef T												value_type;
			typedef Allocator										allocator_type;
			typedef typename allocator_type::reference				reference;
			typedef typename allocator_type::const_reference		const_reference;
			typedef typename allocator_type::pointer				pointer;
			typedef typename allocator_type::const_pointer			const_pointer;
			typedef ft::iterator<value_type>						iterator;
			typedef ft::iterator<const value_type>					const_iterator;
			typedef ft::reverse_iterator<iterator>					reverse_iterator;
			typedef ft::reverse_iterator<const_iterator>			const_reverse_iterator;
			typedef typename ft::iterator_traits::difference_type 	difference_type;
			typedef size_t											size_type;



			// CONSTRUCTORS :

			vector (const allocator_type& alloc = allocator_type())
			{
				_alloc = alloc;
				_size = 0;
				_capacity = 2;
				_data = _alloc.allocate(_capacity);	
			}
		
			// DESTRUCTOR :
			
			~vector(){};

			/********************** MEMBER FUNCTIONS ****************************/
			
			//Element access
		
			reference operator[](size_type pos){return(_data[pos]);}

			reference at(size_type pos){return (_data[pos]);}
			
			reference front(){return(_data[0]);}

			reference back(){return(_data[_size - 1]);}

			
			
			//Capacity
			size_type size() const {return _size;}
			
			bool empty() const {return !_size; }
			
			size_type capacity() const{return _capacity;}

			
			
			
			
			
			// Modifiers
			void	push_back(const T& value )
			{
				if (_size >= _capacity)
					realloc(_capacity + _capacity / 2);
				_data[_size] = value;
				_size++;	
			}

		private :

		void	realloc(size_t newCapacity)
		{
			T* newdata = _alloc.allocate(newCapacity);
			if (newCapacity < _size)
				_size = newCapacity;

			for (size_t i = 0; i < _size; i++)
				newdata[i] = _data[i];

			_alloc.deallocate(_data, _capacity);
			_data = newdata;
			_capacity =	newCapacity;
		}

		private :
			T* _data;
			size_t _size;
			size_t _capacity;
			allocator_type _alloc;

	 };
}


#endif
