


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

#include <iostream>
#include <vector>

int main ()
{
  ft::vector<int> myvector (1,100);
  ft::vector<int>::iterator it;

  it = myvector.begin() + 1;
  myvector.insert(it, 5, 42);

  ///it = myvector.begin();
  //it = myvector.insert ( it , 200 );

  /*myvector.insert (it,2,300);

  // "it" no longer valid, get a new one:
  it = myvector.begin();

  ft::vector<int> anothervector (2,400);
  myvector.insert (it+2,anothervector.begin(),anothervector.end());

  int myarray [] = { 501,502,503 };
  myvector.insert (myvector.begin(), myarray, myarray+3);*/

  // std::cout << "myvector contains:";
  // for (it=myvector.begin(); it<myvector.end(); it++)
  //   std::cout << ' ' << *it;
std::string str, ft_str;
/*
  * var to store the size and the capacity
  */
ft::vector<std::string>::size_type s, ft_s;
ft::vector<std::string>::size_type c, ft_c;
std::vector<std::string> v(20, "string");
ft::vector<std::string> ft_v(20, "string");
ft::vector<std::string>::iterator valid_it;

  v.reserve(100);
  ft_v.reserve(100);
  valid_it = ft_v.begin();
  v.insert(v.begin() + 15, 70, "hello");
  ft_v.insert(ft_v.begin() + 15, 70, "hello");

  str.clear();
  ft_str.clear();
  s = v.size();
  ft_s = ft_v.size();
  c = v.capacity();
  ft_c = ft_v.capacity();
  for (size_t i = 0; i < v.size(); ++i)
      str += v[i];
  for (size_t i = 0; i < ft_v.size(); ++i)
      ft_str += ft_v[i];
  std::cout << ft_str;
  return 0;
}


// std::cout << '\n' << "Size = " << myvector.size() << " Capacity = " << myvector.capacity() << std::endl;