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
				

				// memeber Types

				typedef T																	value_type;
				typedef Alloc																myAllocator;
				typedef Compare 															key_compare;
				typename myAllocator::template rebind<AvlNode<value_type, Alloc> >::other	n_alloc; 

				AvlNode<value_type, Alloc>													*root;


				// constructors ans destructors

				AVL(): root(NULL){};

				AVL(const AVL &src)
				{
					*this = src;
				}
				AVL &operator=(AVL const &src)
				{
					if (this == &src)
						return (*this);
					root = src.root;
					_cmp = src._cmp;
					return (*this);
				}
				~AVL(){}


				// Height of a node :

				int getHeight(AvlNode<value_type, Alloc> *node)
				{
					if (!node)
						return (0);
					return (node->height);
				}

				// Rotations :

				AvlNode<value_type, Alloc> *RightRotate(AvlNode<value_type, Alloc> *z)
				{
					AvlNode<value_type, Alloc> *y = z->left; // point at y
					if (!y)
						return (z);
					AvlNode<value_type, Alloc> *T3 = y->right;
					if (y->right != NULL)
						y->right->parent = z; // update the parent of y->right
					y->right = z; // now lets set in the right of y the z node
					z->left = T3;
					y->parent = z->parent;
					z->parent = y;
					z->height = std::max(getHeight(z->left), getHeight(z->right)) + 1;
					y->height = std::max(getHeight(y->left), getHeight(y->right)) + 1;
					return (y);
				}
				AvlNode<value_type, Alloc> *LeftRotate(AvlNode<value_type, Alloc> *z)
				{
					AvlNode<value_type, Alloc> *y = z->right; // point at y
					AvlNode<value_type, Alloc> *T2 = y->left;
					if (y->left != NULL)
						y->left->parent = z; // update the parent of y->right
					y->left = z; // now lets set in the right of y the z node
					z->right = T2;
					y->parent = z->parent;
					z->parent = y;
					z->height = std::max(getHeight(z->left), getHeight(z->right)) + 1;
					y->height = std::max(getHeight(y->left), getHeight(y->right)) + 1;
					return (y);
				}

				AvlNode<value_type, Alloc> *find(AvlNode<value_type, Alloc> *node, const value_type &key) const
				{
					if (!node )
						return (node);
					if (node->data && node->data->first == key.first)
						return (node);
					if (_cmp(key.first, node->data->first))
						return (find(node->left, key));
					else if (_cmp(node->data->first, key.first))
						return (find(node->right, key));
					return (node);
				}




			private :

				key_compare _cmp;
				myAllocator _alloc;


		};















}

















