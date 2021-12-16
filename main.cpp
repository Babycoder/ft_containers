


//#include <iterator>

#include <vector>
#include <iostream>

#include "vector/vector.hpp"

#include "stack/stack.hpp"




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
  myvector.erase(myvector.begin()+6);

  // erase the first 3 elements:
  myvector.erase (myvector.begin(),myvector.begin()+3);

  std::cout << "myvector contains:";
  for (unsigned i=0; i<myvector.size(); ++i)
    std::cout << ' ' << myvector[i];
  std::cout << "\nSize = " << myvector.size() << " Capacity = "<< myvector.capacity() << '\n';

  return 0;
}*/

int main ()
{
  ft::vector<int> vector(5, 42);

  ft::vector<int>::iterator it = vector.begin();
  ft::vector<int>::const_iterator it2(it);
  

  std::cout << *it2 << std::endl;


  return 0;
}