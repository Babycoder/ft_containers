#ifndef REVERSE_ITERATOR_HPP
#define REVERSE_ITERATOR_HPP


#include "iterators.hpp"
#include "iterators_traits.hpp"

namespace ft
{

	template <class Iterator>
	class reverse_iterator
	{
		protected :
			Iterator _current;
		
		public :

			typedef	Iterator												iterator_type;
			typedef typename iterator_traits<Iterator>::value_type			value_type;
			typedef typename iterator_traits<Iterator>::difference_type		difference_type;
			typedef typename iterator_traits<Iterator>::pointer				pointer;
			typedef typename iterator_traits<Iterator>::reference			reference;
			typedef typename iterator_traits<Iterator>::iterator_category	iterator_category;

		public :

			//constructors :
			
			reverse_iterator() : _current() {};
			explicit reverse_iterator (iterator_type it) : _current(it) {};
			template <class Iter>
  			reverse_iterator (const reverse_iterator<Iter>& rev_it) : _current(rev_it._current) {};

			//member functions :

			iterator_type base() const { return _current; };


	};
}


#endif