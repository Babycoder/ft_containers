#pragma once

#include <iostream>
#include "../BinaryTree/avltree.hpp"

namespace ft {


	template <typename T, class Compare, class Alloc>
	class bidirectional_iterator
	{
		public:
			
			typedef T                               	value_type;
			typedef std::ptrdiff_t						difference_type;
			typedef T*									pointer;
			typedef T&									reference;
			typedef std::bidirectional_iterator_tag 	iterator_category;
			
			bidirectional_iterator(pointer ptr, const AVL<value_type, Compare, Alloc>* avl = NULL)
			: _ptr(ptr), _avl(avl){};
			
			bidirectional_iterator(): _ptr(NULL) {}
			
			~bidirectional_iterator(){}

			operator bidirectional_iterator<const T, Compare, Alloc> () const; // for const

			bidirectional_iterator&  operator=(const bidirectional_iterator& it);

			bidirectional_iterator& operator++();
			bidirectional_iterator operator++(int);

			bidirectional_iterator& operator--();
			bidirectional_iterator operator--(int);

			difference_type operator-(bidirectional_iterator src)const;
			
			reference operator*()const;
			pointer operator->() const;

			friend bool operator== (const bidirectional_iterator& lhs, const bidirectional_iterator& rhs);
			friend bool operator!= (const bidirectional_iterator& lhs, const bidirectional_iterator& rhs);



		
		public :
			pointer _ptr;
			const AVL<value_type, Compare, Alloc>* _avl;
	};
}