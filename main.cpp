//#include "vector/vector.hpp"
#include "iterators.hpp"
#include <iostream>
//#include <iterator>


int 	main()
{
	int data[] = {10, 2, 3, 4, 5};
	ft::iterator<int> it(data);
	//it++;
	//ft::iterator<int> it2(it);
	//it2 = it;
	it += 0;
	std::cout << *it << std::endl;


	return 0;
}
