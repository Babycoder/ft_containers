


//#include <iterator>
//#include "vector/vector.hpp"

#include <vector>
#include <iostream>

#include "iterators.hpp"
#include "iterators_traits.hpp"
#include "reverse_iterator.hpp"
#include "type_traits.hpp"


int 	main()
{
	int data[] = {10, 2, 3, 4, 5};
	ft::iterator<int> it(data);
	ft::iterator<int> it2(data);

	it++;
	bool res = (it == it2);
	//ft::iterator<int> it2(it);
	//it2 = it;
	//it += 0;
	std::cout << (it == it2) << std::endl;

	/*ft::vector<int> test;
	std::cout << test.empty() << std::endl;
	test.push_back(9);
	test.push_back(9);
	test.push_back(9);
	test.push_back(9);
	test.push_back(690);
	test.push_back(6900);
	test.push_back(690000);
	//test.at(6) = 69;
	//test.clear();
	std::cout << test.empty() << std::endl;
	std::cout << test.capacity() << std::endl;
	std::cout << test.size() << std::endl;
	//std::cout << test.max_size() << std::endl;
	//std::cout << "test[0] = " << test.at(6)<< std::endl;
	std::cout << "front = " << test.front()<< std::endl;
	std::cout << "back = " << test.back()<< std::endl;*/

	std::cout << ft::is_integral<float>::value << std::endl;
	return 0;
}
