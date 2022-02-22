
#pragma once

#include <iostream>
#include <functional>
#include "../utils/utility.hpp"
#include "../utils/algorithm.hpp"




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

				//=========================== Rotations ==============================//

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
					if (!node)
						return (node);
					if (node->data && node->data->first == key.first)
						return (node);
					if (_cmp(key.first, node->data->first))
						return (find(node->left, key));
					else if (_cmp(node->data->first, key.first))
						return (find(node->right, key));
					return (node);
				}

				//========================================== Insert ================================================//:
				
				AvlNode<value_type, Alloc>* insert(value_type key)
				{
					this->root = this->insert(this->root, key);
					return (root);
				}
				
				AvlNode<value_type, Alloc> *newNode(value_type const &key)
				{
					AvlNode<value_type, Alloc>* node = n_alloc.allocate(1);
					n_alloc.construct(node, key);
					return (node);
				}
	
				AvlNode<value_type, Alloc> *rebalance(AvlNode<value_type, Alloc> *node, value_type const &key)
				{
					// calculate the balance factor
					int BalanceFactor = getHeight(node->left) - getHeight(node->right);
					// bf > 1 && key < node->data->first RightRotae
					if (BalanceFactor > 1)
					{
						if (_cmp(key.first, node->left->data->first))
							return (RightRotate(node));
						else
						{
							node->left = LeftRotate(node->left);
							return (RightRotate(node));
						}
					}
					if (BalanceFactor < -1)
					{
						if (_cmp(node->right->data->first, key.first))
							return (LeftRotate(node));
						else
						{
							node->right = RightRotate(node->right);
							return (LeftRotate(node));
						}
					}
					return (node);
				}

				AvlNode<value_type, Alloc> *insert(AvlNode<value_type, Alloc> *node, value_type const &key)
				{
					if (!node)
						return (newNode(key));
					if (_cmp(key.first, node->data->first))
					{
						node->left = insert(node->left, key);
						node->left->parent = node;
					}
					else if (_cmp(node->data->first, key.first))
					{
						node->right = insert(node->right, key);
						node->right->parent = node;
					}
					else 
						return (node);
					
					node->height = std::max(getHeight(node->left), getHeight(node->right)) + 1;
					
					return (rebalance(node, key));
					//return (node);
				}

				/**********************************************************************************************/
				
				
				
				/*************************************** remove ***********************************************/

				bool remove(value_type key)
				{
					if (find(root, key))
					{
						this->root = this->remove(this->root, key);
						return (true);
					}
					return (false);
				}

				AvlNode<value_type, Alloc> *remove(AvlNode<value_type, Alloc> *node, value_type const &key)
				{
					if (!node)
						return (node);
					if (_cmp(key.first, node->data->first))
						node->left = remove(node->left, key);
					else if (_cmp(node->data->first, key.first))
						node->right = remove(node->right, key);
					
					else if (node->data->first == key.first)
					{
						if (node->left == NULL || node->right == NULL)
						{
							AvlNode<value_type, Alloc> *tmp = node->left ? node->left : node->right;
							if (!tmp)
							{
								tmp = node;
								node = NULL;
							}
							else
							{
								AvlNode<value_type, Alloc> *new_parent = node->parent;
								*node = *tmp;
								node->parent = new_parent;
							}
							_alloc.deallocate(tmp->data , 1);
							n_alloc.deallocate(tmp, 1);
						}
						else
						{
							AvlNode<value_type, Alloc> *tmp = findMin(node->right);
							_alloc.construct(node->data, *tmp->data);
							node->right = remove(node->right, *tmp->data);
						}
					}
					if (!node)
						return (node);
					node->height = std::max(getHeight(node->left), getHeight(node->right)) + 1;
					return (rebalance(node, key));

				}



				/**********************************************************************************************/
				
				
				/************************************** utils functions *************************************/
				
				AvlNode<value_type, Alloc> *findMin(AvlNode<value_type, Alloc> *node) const
				{
					if (!node)
						return (NULL);
					AvlNode<value_type, Alloc> *min = node;
					while (min->left)
						min = min->left;
					return (min);
				}
				
				AvlNode<value_type, Alloc> *findMax(AvlNode<value_type, Alloc> *node) const
				{
					if (!node)
						return (NULL);
					AvlNode<value_type, Alloc> *max = node;
						while (max->right)
						max = max->right;
					return (max);
				}
				
				AvlNode<value_type, Alloc> * successor(const value_type &ref) const
				{
					AvlNode<value_type, Alloc> *node = find(root, ref);
					if (!node)
						return (NULL);
					if (node->right != NULL)
						return (findMin(node->right));
					
					AvlNode<value_type, Alloc> *succ = node->parent;
					
					while (succ != NULL && node == succ->right)
					{
						node = succ;
						succ = succ->parent;
					}
					node = succ;
					return (node);
				}
				
				AvlNode<value_type, Alloc> * predecessor(const value_type &ref) const
				{
					AvlNode<value_type, Alloc> *node = find(root, ref);
					if (!node)
						return (NULL);

					if (node->left != NULL)
						return (findMax(node->left));
					AvlNode<value_type, Alloc> *succ = node->parent;
					while (succ != NULL && node == succ->left)
					{
						node = succ;
						succ = succ->parent;
					}
					node = succ;
					return (node);
				}

				void assign(const AvlNode<value_type, Alloc> *node)
				{
					if (!node)
						return ;
					assign(node->left);
					if (node->data)
						insert(*(node->data));
					assign(node->right);
				}

				void inorder(AvlNode<value_type, Alloc>* root)
    			{
        			if(root == NULL)
            			return;
        			inorder(root->left);
        			std::cout << root->data->second << " ";
        			inorder(root->right);
    			}

				void preorder_clear(AvlNode<value_type, Alloc> *node)
				{
					if (node == NULL)
						return;
					preorder_clear(node->left);
					_alloc.deallocate(node->data, 1);
					preorder_clear(node->right);
					n_alloc.deallocate(node, 1);
					node = NULL;
				}

				void display()
    			{
        			inorder(root);
        			std::cout << std::endl;
    			}


			private :

				key_compare																	_cmp;
				myAllocator																	_alloc;
				typename myAllocator::template rebind<AvlNode<value_type, Alloc> >::other	n_alloc; 


		};





}

