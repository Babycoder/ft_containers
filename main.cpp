


//#include <iterator>

#include <vector>
#include <iostream>

#include "vector/vector.hpp"
#include "iterators.hpp"
#include "iterators_traits.hpp"
#include "reverse_iterator.hpp"
#include "type_traits.hpp"


template<typename T>
T max(T a, T b)
{
	if (a > b)
		return a;
	else
		return b;
}


int 	main()
{
	/*int data[] = {10, 2, 3, 4, 5};
	ft::iterator<int> it(data);
	ft::iterator<int> it2(data);

	it++;
	bool res = (it == it2);
	//ft::iterator<int> it2(it);
	//it2 = it;
	//it += 0;
	std::cout << (it == it2) << std::endl;*/

	ft::vector<int> test;
	std::vector<int> vector;
//	for (int i = 0; i < 10 ; i++)
		test.push_back(1);
		test.push_back(0);
		test.push_back(0);
		test.push_back(0);
		test.push_back(9);
//	for (int i = 0; i < 10 ; i++)
		vector.push_back(1);
		vector.push_back(0);
		vector.push_back(0);
		vector.push_back(0);
		vector.push_back(9);
	
	//test.at(6) = 69;
	//test.clear();
	std::cout << "test capacity = " << test.capacity() << std::endl;
	std::cout << "test size     = " << test.size() << std::endl;
	std::cout << "test front     = " << test.back() << std::endl;
	std::cout << "vector capacity = " << vector.capacity() << std::endl;
	std::cout << "vector size     = " << vector.size() << std::endl;
	std::cout << "vector front     = " << vector.back() << std::endl;
	//std::cout << test.max_size() << std::endl;
	//std::cout << "test[0] = " << test.at(6)<< std::endl;
	//std::cout << "front = " << test.front()<< std::endl;
	//std::cout << "back = " << test.back()<< std::endl;

	//std::cout << ft::is_integral<char>::value << std::endl;

	return 0;
}
