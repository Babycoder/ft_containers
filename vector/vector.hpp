#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <iostream>


namespace ft
{	
	template < class T, class Allocator = std::allocator<T> >
	class vector{
		 
		public	:
			typedef T value_type;
			//typedef Allocator allocator_type;
			typedef std::size_t size_type;
			typedef std::ptrdiff_t difference_type;
			typedef value_type& reference;
			typedef	const value_type& const_reference;
			//typedef Allocator::pointer pointer; 
			//typedef Allocator::const_pointer const_pointer;

			vector(){
				Allocator aloc;
				_size = 0;
				_capacity = 2;
				_data = aloc.allocate(_capacity);
			};
			~vector(){};

			//Element access
		
			reference operator[](size_type pos)
			{
				return(_data[pos]);
			}

			reference at(size_type pos)
			{
				return (_data[pos]);
			}
			reference front()
			{
				return(_data[0]);
			}

			reference back()
			{
				return(_data[_size - 1]);
			}

			//Capacity

			bool empty() const
			{
				if (_size == 0)
					return true;
				else
					return false;
			}
			size_type size() const
			{
				return _size;
			}

			size_type capacity() const
			{
				return _capacity;
			}
			
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
			Allocator aloc;
			//T* newdata = new T[newCapacity];
			T* newdata = aloc.allocate(newCapacity);
			if (newCapacity < _size)
				_size = newCapacity;

			for (size_t i = 0; i < _size; i++)
				newdata[i] = _data[i];
			//delete [] _data;
			aloc.deallocate(_data, _capacity);
			_data = newdata;
			_capacity = newCapacity;
		}

		private :
			T* _data;
			size_t _size;
			size_t _capacity;

	 };
}


#endif
