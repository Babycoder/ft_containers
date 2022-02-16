#pragma once

#include <iostream>
#include <../utils/utility.hpp>




namespace ft
{

	template <typename T, class Alloc>
	class AvlNode
	{
		public:
			
			AvlNode		*parent;
			AvlNode		*right;
			AvlNode     *left;
			
			T			*data;
			int			height;
			
			Alloc		_alloc;
			
			
			AvlNode()
			{
				left = NULL;
				right = NULL;
				parent = NULL;
				data = NULL;
				height = 0;
			}
			
			AvlNode(const T &val)
			{
				left = NULL;
				right = NULL;
				parent = NULL;
				data = _alloc.allocate(1);
				_alloc.construct(data, val);
				height = 1;
			}
			
			AvlNode &operator=(AvlNode const &src)
			{
				if (this == &src)
					return (*this);
				if(data)
					_alloc.deallocate(data, 1);
				left = src.left;
				right = src.right;
				parent = src.parent;
				height = src.height;
				data = _alloc.allocate(1);
				_alloc.construct(data, *src.data);
				return (*this);
			}
			
			~AvlNode() {}
		};


		template <typename T, class Compare, class Alloc>
		class AVL
		{
			public:
				
				typedef T									value_type;
				typedef Alloc								myAllocator;
				typedef Compare 							key_compare;
				typename myAllocator::template rebind<AvlNode<value_type, Alloc> >::other	n_alloc; 

				AvlNode<value_type, Alloc>					*root;



		};















}

















