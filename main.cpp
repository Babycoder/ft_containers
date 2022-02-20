


//#include <iterator>

#include <vector>
#include <iostream>
#include  "map/map.hpp"
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

#include <iostream>
#include <vector>
#include "utils/utility.hpp"

int main () {
  ft::map<int, char> m;

  m.insert(ft::make_pair(1, 'a'));
  m.insert(ft::make_pair(2, 'a'));
  m.insert(ft::make_pair(3, 'a'));
  m.insert(ft::make_pair(4, 'a'));
  m.insert(ft::make_pair(5, 'a'));

  ft::map<int, char>::iterator it;


  for (it = m.begin(); it != m.end(); it++)
    std::cout << it->first << std::endl;

 /* m.erase(1);
  m.erase(2);
  m.erase(3);
  m.erase(4);
  m.erase(5);*/

   for (it = m.begin(); it != m.end(); it++)
    std::cout << it->first << std::endl;


  return 0;
}