#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>

namespace ft
{
	template <typename T, size_t len>
	class Array
	{
		private :
		T     _data[len];

		public :
		int	size() const{return len;}
		T &operator[](int index) {return _data[index];}
	
	};
}

#endif