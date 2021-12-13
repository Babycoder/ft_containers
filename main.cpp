


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

/*int main ()
{
  ft::vector<int> myvector;

  // set some values (from 1 to 10)
  for (int i=1; i<=10; i++) myvector.push_back(i);

  // erase the 6th element
  myvector.erase (myvector.begin()+5);

  // erase the first 3 elements:
  //myvector.erase (myvector.begin(),myvector.begin()+3);

  std::cout << "myvector contains:";
  for (unsigned i=0; i<myvector.size(); ++i)
    std::cout << ' ' << myvector[i];
  std::cout << '\n';

  return 0;
}*/

int 	main()
{
	// ft::vector<int> vector(100, 5);
	// std::cout << "Size = " << vector.size() << " Capacity = " << vector.capacity() << std::endl;
	
	
	std::vector<int> first (1013,100);
  	std::vector<int> second (first.begin(),first.end());
	std::vector<int> third (second);
	second.push_back(10);

	third.push_back(5);

	std::cout << "Size = " << first.size() << " Capacity = " << first.capacity() << std::endl;
	std::cout << "Size = " << second.size() << " Capacity = " << second.capacity() << std::endl;
	std::cout << "Size = " << third.size() << " Capacity = " << third.capacity() << std::endl;


	return 0;
}
