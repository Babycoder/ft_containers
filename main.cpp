


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
    ft::stack<int> stack;
    ft::stack<int> s;
    
    stack.push(5);
    stack.pop();

    std::cout << stack.empty() << '\n' << (stack == s) <<std::endl;
    /*std::vector<int> myvector (3, 5);
    std::vector<int>::iterator it;

    it = myvector.begin() + 2;
    //std::cout << "\n *it = " << *it << std::endl;
    it =  myvector.insert( it , 42);
    //std::cout << "\n *it = " << *it << std::endl;


   //it = myvector.insert ( it + 1 , 420 );
    //it = myvector.insert ( it + 1 , 420 );

   myvector.insert (it,2,300);

    // "it" no longer valid, get a new one:
    it = myvector.begin();

    std::vector<int> anothervector (2,400);
    myvector.insert (it+2,anothervector.begin(),anothervector.end());

    int myarray [] = { 501,502,503 };
    myvector.insert (myvector.begin(), myarray, myarray+3);

    std::cout << "myvector contains:";
    for (it=myvector.begin(); it<myvector.end(); it++)
      std::cout << ' ' << *it;
    //std::cout<<'\n';
    std::cout << "\nSize = " << myvector.size() << " Capacity = " << myvector.capacity() << '\n';
    //std::cout << myvector[2] << std::endl;

    return 0;*/
}