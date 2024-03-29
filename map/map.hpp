#ifndef MAP_HPP
#define MAP_HPP

#include "../vector/vector.hpp"
#include "../utils/bidirectional_iterator.hpp"
#include "../utils/type_traits.hpp"
#include "../utils/algorithm.hpp"
#include "../utils/utility.hpp"
#include "../utils/reverse_iterator.hpp"
#include "../BinaryTree/avltree.hpp"

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
			/********************** Member Types ***************************/

			typedef Key																key_type;
			typedef T																mapped_type;
			typedef Compare															key_compare;
			typedef ft::pair<const key_type, mapped_type> 							value_type;
			typedef Alloc															allocator_type;

			typedef typename allocator_type::reference								reference;
			typedef typename allocator_type::const_reference						const_reference;
			typedef typename allocator_type::pointer								pointer;
			typedef typename allocator_type::const_pointer							const_pointer;
			typedef typename ft::bidirectional_iterator<value_type, Compare, Alloc> iterator;
			typedef typename ft::bidirectional_iterator<value_type, Compare, Alloc> const_iterator;
			typedef typename ft::reverse_iterator<iterator>							reverse_iterator;
			typedef typename ft::reverse_iterator<const_iterator>					const_reverse_iterator;
			
			typedef ptrdiff_t														difference_type;
			typedef size_t															size_type;

			class value_compare : std::binary_function<value_type, value_type, bool>
			{
				friend class map;
				protected:
					Compare comp;
					value_compare(Compare c) : comp(c) {}
				public:
					typedef bool result_type;
					typedef value_type first_argument_type;
					typedef value_type second_argument_type;
					bool operator()(const value_type &x, const value_type &y) const { return comp(x.first, y.first); }
			};
		
			/*************************************************************************/

			/*************************** constructor & destructor *******************/

			explicit map (const key_compare& comp = key_compare(),const allocator_type& alloc = allocator_type()) :
			_cmp(comp), _alloc(alloc), _size(0){}

			template <class InputIterator>
  			map (InputIterator first, InputIterator last,
       			const key_compare& comp = key_compare(),
       			const allocator_type& alloc = allocator_type())
			{
				_size = 0;
				_cmp = comp;
				_alloc = alloc;
				while (first != last)
					insert(*first++);
			}

			map (const map& x)
			{
				_size = 0;
				*this = x;
			}

			map &operator=(const map &x)
			{
				clear();
				_avl.assign(x._avl.root);
				_size = x.size();
				return (*this);
			}
		
			~map()
			{
				clear();
			}

			/************************************************************************/
		
			/***************** iterators methods ***********************************/
			
			iterator begin()
			{
				return iterator(_avl.findMin(_avl.root) ? _avl.findMin(_avl.root)->data : NULL, &_avl);
			}
			const_iterator begin() const
			{
				return iterator(_avl.findMin(_avl.root) ? _avl.findMin(_avl.root)->data : NULL, &_avl); 
			}
			iterator end()
			{
				return iterator(NULL, &_avl);
			}
			const_iterator end() const
			{
				return iterator(NULL, &_avl);
			}

			reverse_iterator rbegin() {return (reverse_iterator(end()));}
			const_reverse_iterator rbegin() const {return (const_reverse_iterator(end()));}

			reverse_iterator rend() {return (reverse_iterator(begin()));}
			const_reverse_iterator rend() const {return (const_reverse_iterator(begin()));}

			/**********************************************************************/
			
			/************************ Element access and capacity methods ***************************/
			
			bool empty() const { return (_size == 0 ? true : false); }
			size_type size() const { return (_size); }
			size_type max_size() const {return (_alloc.max_size() ); }

			mapped_type& operator[] (const key_type& k)
			{
				value_type val = ft::make_pair<const key_type, mapped_type> (k, mapped_type());
				AvlNode<value_type, Alloc> *node = _avl.find(_avl.root, val);
				if (!node)
				{
					_size++;
					_avl.insert(val);
					return (_avl.find(_avl.root, val)->data->second);
				}
				return (node->data->second);
			}


			/**************************************************************************************/

			/**************** modifiers *******************************************************/

			ft::pair<iterator,bool> insert (const value_type& val)
			{
				AvlNode<value_type, Alloc> *node = _avl.find(_avl.root, val);
				
				bool not_found = false;
				if (!node)
				{
					node = _avl.insert(val);
					not_found = true;
					_size++;
				}
				return (ft::make_pair<iterator, bool>(iterator(node->data, &_avl), not_found));
			}

			iterator insert (iterator position, const value_type& val)
			{
				(void)position;
				return (insert(val).first);
			}

			template <class InputIterator>
  			void insert (InputIterator first, InputIterator last)
			{
				while (first != last)
				{
					insert(*first);
					first++;
				}
			}

			void erase (iterator position)
			{
				_avl.remove(*position);
				_size--;
			}

			size_type erase(const key_type &k)
			{
				_size--;
				return _avl.remove(ft::make_pair(k, mapped_type()));
			}

			void erase (iterator first, iterator last)
			{
				ft::vector<key_type> tmp;

				while (first != last)
				{
					tmp.push_back(first->first);
					first++;
				}
				for(size_type i = 0; i < tmp.size(); i++)
					erase(tmp[i]);
				tmp.clear();
			}

			void swap (map& x)
			{
				map tmp;

				tmp.swap_content(*this);
				this->swap_content(x);
				x.swap_content(tmp);
				tmp._avl.root = NULL;
			}

			void clear()
			{
				_avl.preorder_clear(_avl.root);
				_avl.root = NULL;
				_size = 0;
			}

			/**********************************************************************/

			/********************** Observers and allocator **************************************/

			key_compare key_comp() const
			{
				 return (_cmp);
			}

			value_compare value_comp() const
			{
				return (value_compare(_cmp));
			}

			allocator_type get_allocator() const
			{
				return (_alloc);
			}


			/************************************************************************/

			/************************** Operation methods ****************************/

		    iterator find (const key_type& k)
			{
				AvlNode<value_type, Alloc> *node = _avl.find(_avl.root, ft::make_pair(k, mapped_type()));
				
				return iterator(node ? node->data : NULL, &_avl);
			}
			const_iterator find (const key_type& k) const
			{
				AvlNode<value_type, Alloc> *node = _avl.find(_avl.root, ft::make_pair(k, mapped_type()));

				return iterator(node ? node->data : NULL, &_avl);	
			}

			size_type count (const key_type& k) const
			{
				AvlNode<value_type, Alloc> *node = _avl.find(_avl.root, ft::make_pair(k, mapped_type()));
				
				return (node ? 1 : 0);
			}

			iterator lower_bound (const key_type& k)
			{
				AvlNode<value_type, Alloc> *node = _avl.root;
				AvlNode<value_type, Alloc> *tmp = node;

				while (node != NULL)
				{
					if (!_cmp(node->data->first, k))
					{

						tmp = node;
						if(tmp->data->first == k)
							break;
						node = node->left;
					}
					else
						node = node->right;
				}
				return(iterator(tmp ? tmp->data : NULL, &_avl));
			}
				
			const_iterator lower_bound (const key_type& k) const
			{
				AvlNode<value_type, Alloc> *node = _avl.root;
				AvlNode<value_type, Alloc> *tmp = node;

				while (node != NULL)
				{
					if (!_cmp(node->data->first, k))
					{
						tmp = node;
						if(tmp->data->first == k)
							break;
						node = node->left;
					}
					else
						node = node->right;
				}
				return(iterator(tmp ? tmp->data : NULL, &_avl));
			}

			
			iterator upper_bound (const key_type& k)
			{
				AvlNode<value_type, Alloc> *node = _avl.root;
				AvlNode<value_type, Alloc> *tmp = node;

				while (node != NULL)
				{
					if (_cmp(k, node->data->first))
					{
						tmp = node;
						node = node->left;
					}
					else
						node = node->right;
				}
				return(iterator(tmp ? tmp->data : NULL, &_avl));
			}
			
			const_iterator upper_bound (const key_type& k) const
			{
				AvlNode<value_type, Alloc> *node = _avl.root;
				AvlNode<value_type, Alloc> *tmp = node;

				while (node != NULL)
				{
					if (_cmp(k, node->data->first))
					{
						tmp = node;
						node = node->left;
					}
					else
						node = node->right;
				}
				return(iterator(tmp ? tmp->data : NULL, &_avl));
			}
			
	
			ft::pair<iterator,iterator>             equal_range (const key_type& k)
			{
				return (ft::make_pair(lower_bound(k), upper_bound(k)));
			}
			
			ft::pair<const_iterator,const_iterator> equal_range (const key_type& k) const
			{
				return (ft::make_pair(lower_bound(k), upper_bound(k)));
			}

			/*************************************************************************/
		
		private :

			key_compare										_cmp;
			allocator_type									_alloc;
			size_t											_size;
			AVL<value_type, key_compare, allocator_type>	_avl;

			void swap_content(const map &src)
			{
				_avl = src._avl;
				_alloc = src._alloc;
				_size = src._size;
			}
	};

	/********************* relational operators and swap ************************/
	
	template <class Key, class T, class Compare, class Alloc>
	bool operator==(const map<Key, T, Compare, Alloc> &lhs,
					const map<Key, T, Compare, Alloc> &rhs)
	{
		if (lhs.size() != rhs.size())
			return (false);
		return (ft::equal(lhs.begin(), lhs.end(), rhs.begin()));
	}
	
	template <class Key, class T, class Compare, class Alloc>
	bool operator!=(const map<Key, T, Compare, Alloc> &lhs,
					const map<Key, T, Compare, Alloc> &rhs)
	{
		return (!(lhs == rhs));
	}
	
	template <class Key, class T, class Compare, class Alloc>
	bool operator<(const map<Key, T, Compare, Alloc> &lhs,
				   const map<Key, T, Compare, Alloc> &rhs)
	{
		return (ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()));
	}
	
	template <class Key, class T, class Compare, class Alloc>
	bool operator>(const map<Key, T, Compare, Alloc> &lhs,
				   const map<Key, T, Compare, Alloc> &rhs)
	{
		return (ft::lexicographical_compare(rhs.begin(), rhs.end(), lhs.begin(), lhs.end()));
	}
	
	template <class Key, class T, class Compare, class Alloc>
	bool operator<=(const map<Key, T, Compare, Alloc> &lhs,
					const map<Key, T, Compare, Alloc> &rhs)
	{
		if (lhs < rhs || lhs == rhs)
			return (true);
		return (false);
	}
	
	template <class Key, class T, class Compare, class Alloc>
	bool operator>=(const map<Key, T, Compare, Alloc> &lhs,
					const map<Key, T, Compare, Alloc> &rhs)
	{
		if (lhs > rhs || lhs == rhs)
			return (true);
		return (false);
	}
	
	template <class Key, class T, class Compare, class Alloc>
	void swap(map<Key, T, Compare, Alloc> &x, map<Key, T, Compare, Alloc> &y)
	{
		x.swap(y);
	}
	
	/***************************************************************************/

}


#endif