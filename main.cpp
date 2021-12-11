


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

int main ()
{
  ft::vector<int>::size_type sz;

  ft::vector<int> foo;
  sz = foo.capacity();
  std::cout << "making foo grow:\n";
  for (int i=0; i<100; ++i) {
    foo.push_back(i);
    if (sz!=foo.capacity()) {
      sz = foo.capacity();
      std::cout << "capacity changed: " << sz << '\n';
    }
  }

  ft::vector<int> bar;
  sz = bar.capacity();
  bar.reserve(100);   // this is the only difference with foo above
  std::cout << "making bar grow:\n";
  for (int i=0; i<100; ++i) {
    bar.push_back(i);
    if (sz!=bar.capacity()) {
      sz = bar.capacity();
      std::cout << "capacity changed: " << sz << '\n';
    }
  }
  return 0;
}

/*int 	main()
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

	ft::vector<int> test;
	std::vector<int> vector;
	for (int i = 0; i < 10 ; i++)
		test.push_back(i);

	for (int i = 0; i < 10 ; i++)
		vector.push_back(i);

	ft::vector<int>::iterator it1_begin, it1_end;
	std::vector<int>::iterator it2_begin, it2_end;

	it1_begin = test.begin();
	it1_end = test.end();
	it2_begin = vector.begin();
	it2_end = vector.end();


	
	std::cout << "test capacity = " << test.capacity() << std::endl;
	std::cout << "test size     = " << test.size() << std::endl;
	std::cout << "test front    = " << *(++test.begin()) << std::endl;
	try{
		std::cout << "test random   = " << test.at(50) << std::endl;
	}
	catch(std::out_of_range& e)
	{
		std::cerr << e.what() << std::endl;
	}
	while(it1_begin != it1_end)
	{
		std::cout << *it1_begin++ << ", ";
	}
	std::cout << std::endl;
	std::cout << "================================\n";

	std::cout << "vector capacity = " << vector.capacity() << std::endl;
	std::cout << "vector size     = " << vector.size() << std::endl;
	std::cout << "vector front    = " << *(++vector.begin()) << std::endl;
	try
	{
		std::cout << "vector random   = " << vector.at(50) << std::endl;
	}
	catch(std::out_of_range& e)
	{
		std::cerr << e.what() << std::endl;
	}
	
	
	while(it2_begin != it2_end)
	{
		std::cout << *it2_begin++ << ", ";
	}
	std::cout << std::endl;


	return 0;
}*/
