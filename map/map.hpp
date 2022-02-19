#ifndef MAP_HPP
#define MAP_HPP

#include "../utils/bidirectional_iterator.hpp"
#include "../utils/type_traits.hpp"
#include "../utils/algorithm.hpp"
#include "../utils/utility.hpp"
#include "../utils/reverse_iterator.hpp"
#include "avltree.hpp"

#include <functional>
#include <iostream>


namespace ft {
	
	template < class Key,
		   class T,                                       
		   class Compare = std::less<Key>,
		   class Alloc = std::allocator<pair<const Key,T> >
		   > 
	class map
	{
		public :
			/**************** Member Types ************/

			typedef Key										key_type;
			typedef T										mapped_type;
			typedef Compare									key_compare;
			typedef ft::pair<const key_type, mapped_type> 	value_type;
			typedef Alloc									allocator_type;

			
			
			typedef ptrdiff_t								difference_type;
			typedef size_t									size_type;
		
			/******************************************/
		
		
		
		
		private :

			key_compare						_cmp;
			allocator_type					_alloc;
			size_t							_size;
			AVL<value_type, Compare, Alloc>	_avl;
	};
}


#endif