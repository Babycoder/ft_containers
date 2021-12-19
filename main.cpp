


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
  std::vector<int> first;
  std::vector<int> second;
  std::vector<int> third;

  for(int i = 0; i < 10; i++)
    first.push_back(i);
  first.assign (100,100);          // 7 ints with a value of 100

  std::vector<int>::iterator it;
  it=first.begin()+1;

  second.assign (it,first.end()-1); // the 5 central values of first

  int myints[] = {1776,7,4};
  third.assign (myints,myints+3);   // assigning from array.

  std::cout << "Size of first: " << int (first.size()) << " Capacity = " << int(first.capacity()) <<'\n';
  std::cout << "Size of second: " << int (second.size())<< " Capacity = "<< int(second.capacity()) << '\n';
  std::cout << "Size of third: " << int (third.size())<< " Capacity = "<< int(third.capacity()) << '\n';
  
 // std::cout << '\n' << "Size = " << myvector.size() << " Capacity = " << myvector.capacity() << std::endl;
  
  return 0;
}


// std::cout << '\n' << "Size = " << myvector.size() << " Capacity = " << myvector.capacity() << std::endl;