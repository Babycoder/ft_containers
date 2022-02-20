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

			operator bidirectional_iterator<const T, Compare, Alloc> () const
			{
				return bidirectional_iterator<const T, Compare, Alloc>(_ptr, _avl);
			}

			bidirectional_iterator&  operator=(const bidirectional_iterator& it)
			{
				_ptr = it._ptr;
				_avl = it._avl;
				return (*this);
			}

			bidirectional_iterator& operator++()
			{
				AvlNode<value_type, Alloc> *node = _avl->find(_avl->root, *_ptr);
				if (node)
				{
				AvlNode<value_type, Alloc> *succ = _avl->successor(*_ptr);
				if (succ)
					_ptr = succ->data;
				else
					_ptr = NULL;
				}
				return (*this);
			}
			
			bidirectional_iterator operator++(int)
			{
				bidirectional_iterator tmp = *this;
				++(*this);
				return tmp;
			}

			bidirectional_iterator& operator--()
			{
				AvlNode<value_type, Alloc> *node = NULL;
				if (!_ptr)
				{
					node = _avl->findMax(_avl->root);
					if (node)
						_ptr = node->data;
					return (*this);
				}
				node = _avl->find(_avl->root, *_ptr);
				if (node)
				{
					AvlNode<value_type, Alloc> *pred = _avl->predecessor(*_ptr);
					if (pred)
						_ptr = pred->data;
					else
						_ptr = NULL;
				}
				return (*this);
			}
			bidirectional_iterator operator--(int)
			{
				bidirectional_iterator tmp = *this;
				--(*this);
				return tmp;
			}

			difference_type operator-(bidirectional_iterator src) const
			{
				return (_ptr - src._ptr);
			}
			
			reference	operator*() const { return *_ptr;}
			pointer		operator->() const { return _ptr;}

			friend bool operator== (const bidirectional_iterator& lhs, const bidirectional_iterator& rhs)
			{
				return (lhs._ptr == rhs._ptr);
			}
			friend bool operator!= (const bidirectional_iterator& lhs, const bidirectional_iterator& rhs)
			{
				return (lhs._ptr != rhs._ptr);
			}

		
		public :
			pointer									_ptr;
			const AVL<value_type, Compare, Alloc>*	_avl;
	};
}