#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <iostream>


namespace ft
{	
	//template < class T, class Alloc = std::allocator<T> >
	class vector{
		private	:
		 
		public	:
			void	msg(){std::cout << "Hello from FUNC\n";};
			//vector (const allocator_type& alloc = allocator_type())
			vector();
			~vector();
	 };
}

/*template < class T, class Alloc>
class ft::vector
{
	private:

	public:
	void    msg(){std::cout << "Hello from FUNC\n";};
	//vector (const allocator_type& alloc = allocator_type())
	vector();
	~vector();
};
template <class Iterator> class reverse_iterator
{
	Iterator t;
	operator++()
	{
		t--;
	}
}*/

#endif
