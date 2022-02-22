#include <iostream>

#if NS
#define NAMESPACE "FT  : "
#include "vector/vector.hpp"
#include "stack/stack.hpp"
#include "map/map.hpp"
#else
#define NAMESPACE "STD : "
#include <vector>
#include <stack>
#include <map>
namespace ft = std;
#endif

void  vector_test()
{

  ft::vector<int> v1;
  ft::vector<int> v2(10, 1337);
  ft::vector<int> v3(v2);

  ft::vector<int>::iterator it = v2.begin();
  ft::vector<int>::iterator it_end = v2.end();

  ft::vector<int> v4(it, it_end);

  for (int i = 0; i < 10 ; i++)
    std::cout << v4[i] << std::endl;
  
  std::cout << "_size = " << v4.size() << std::endl;
  std::cout << "_capacity = " << v4.capacity() << std::endl;

  v4[0] = 42;
  v4[9] = 21;

  std::cout << "_front = " << v4.front() << std::endl; 
  std::cout << "_back = " << v4.back() << std::endl;

  v4.pop_back();
  std::cout << "_back = " << v4.back() << std::endl;
  
  v4.push_back(2022);

  ft::vector<int> v5;

  v5.insert(v5.begin(), it, it_end);
  v5.push_back(42);

  ft::vector<int>::iterator it_v5 = v5.begin();
  
  for(; it_v5 != v5.end(); it_v5++)
   std::cout << *(it_v5) << std::endl;
  
  v5.erase(v5.begin(), v5.begin() + 5);
  
  std::cout << "******************************************\n";
  
  for(ft::vector<int>::iterator it = v5.begin(); it != v5.end(); it++)
    std::cout << *(it) << std::endl;
  
  std::cout << "*************** Capacity ****************/\n"; 

  std::cout << "_size = " << v5.size() << " _capacity =" << v5.capacity() << " _is_empty =" << v5.empty() << " _max_size = " << v5.max_size() << std::endl; 

  std::cout << "******************************************\n";
  
  v5.clear();
  for(ft::vector<int>::iterator it = v5.begin(); it != v5.end(); it++)
     std::cout << *(it) << std::endl;
  


}

void  stack_test()
{
  ft::stack<int> s1;
  
  std::cout << "stack is_empty = " << s1.empty() << std::endl;


  for (int i = 0; i < 10 ; i++)
    s1.push(i);
  
  std::cout << "stack is_empty = " << s1.empty() << std::endl;
  
  std::cout << "stack size = " << s1.size() << std::endl;

  for (int i = 0; i < 10 ; i++)
  {
    std::cout << s1.top() << std::endl;
    s1.pop();
  }

  ft::stack<int> s2;

  std::cout << "s1 = s2 : " << (s1 == s2) << std::endl;

  s2.push(1337);

  std::cout << "s1 = s2 : " << (s1 == s2) << std::endl;


}

void  map_test()
{

  std::cout << "*************** Constructions ****************" << std::endl;
		{
			ft::map<char,int> first;

			first['a']=10;
			first['b']=30;
			first['c']=50;
			first['d']=70;

			ft::map<char,int> second (first.begin(),first.end());

			ft::map<char,int> third (second);

			std::cout << "Size:" << third.size() << std::endl;
			for(ft::map<char,int>::iterator i = third.begin(); i !=  third.end(); i++)
				std::cout << i->first << " - " <<  i->second << std::endl;
		}
		std::cout << "*************** operator=  ****************" << std::endl;
		{
			ft::map<char,int> first;
			ft::map<char,int> second;

			first['x']=8;
			first['y']=16;
			first['z']=32;

			second=first;
			first = ft::map<char,int>();

			std::cout << "Size of first: " << first.size() << '\n';
			std::cout << "Size of second: " << second.size() << '\n';
		}

		std::cout << "*************** rbegin and rend ****************" << std::endl;
		{
			ft::map<char,int> mymap;

			mymap['x'] = 100;
			mymap['y'] = 200;
			mymap['z'] = 300;

			ft::map<char,int>::reverse_iterator rit;
			for (rit=mymap.rbegin(); rit!=mymap.rend(); ++rit)
				std::cout << rit->first << " => " << rit->second << '\n';
		}

		std::cout << "*************** erase and empty ****************" << std::endl;
		{
			ft::map<char,int> mymap;

			mymap['a']=10;
			mymap['b']=20;
			mymap['c']=30;

			while (!mymap.empty())
			{
				std::cout << mymap.begin()->first << " => " << mymap.begin()->second << '\n';
				mymap.erase(mymap.begin());
			}
		}
		std::cout << "*************** size ****************" << std::endl;
		{
			ft::map<char,int> mymap;
			mymap['a']=101;
			mymap['b']=202;
			mymap['c']=302;
			std::cout << "mymap.size() is " << mymap.size() << '\n';
		}
		
		std::cout << "/*************** operator[] ****************/" << std::endl;
		{
			ft::map<char,std::string> mymap;

			mymap['a']="an element";
			mymap['b']="another element";
			mymap['c']=mymap['b'];

			std::cout << "mymap['a'] is " << mymap['a'] << '\n';
			std::cout << "mymap['b'] is " << mymap['b'] << '\n';
			std::cout << "mymap['c'] is " << mymap['c'] << '\n';
			std::cout << "mymap['d'] is " << mymap['d'] << '\n';

			std::cout << "mymap now contains " << mymap.size() << " elements.\n";
		}
		std::cout << "*************** insert ****************" << std::endl;
		{
			ft::map<char,int> mymap;


			mymap.insert ( ft::pair<char,int>('a',100) );
			mymap.insert ( ft::pair<char,int>('z',200) );

			ft::pair<ft::map<char,int>::iterator,bool> ret;
			ret = mymap.insert ( ft::pair<char,int>('z',500) );
			if (ret.second==false) {
				std::cout << "element 'z' already existed";
				std::cout << " with a value of " << ret.first->second << '\n';
			}


			ft::map<char,int>::iterator it = mymap.begin();
			mymap.insert (it, ft::pair<char,int>('b',300));  
			mymap.insert (it, ft::pair<char,int>('c',400));  


			ft::map<char,int> anothermap;
			anothermap.insert(mymap.begin(),mymap.find('c'));


			std::cout << "mymap contains:\n";
			for (it=mymap.begin(); it!=mymap.end(); ++it)
				std::cout << it->first << " => " << it->second << '\n';

			std::cout << "anothermap contains:\n";
			for (it=anothermap.begin(); it!=anothermap.end(); ++it)
				std::cout << it->first << " => " << it->second << '\n';
		}
		std::cout << "/*************** erase ****************/" << std::endl;
		{
			ft::map<char,int> mymap;
			ft::map<char,int>::iterator it;


			mymap['a']=10;
			mymap['b']=20;
			mymap['c']=30;
			mymap['d']=40;
			mymap['e']=50;
			mymap['f']=60;

			it=mymap.find('b');
			mymap.erase (it);                   

			mymap.erase ('c');                  

			it=mymap.find ('e');
			mymap.erase ( it, mymap.end() );    


			for (it=mymap.begin(); it!=mymap.end(); ++it)
				std::cout << it->first << " => " << it->second << '\n';
		}
		std::cout << "/*************** swap ****************/" << std::endl;
		{
			ft::map<char,int> foo,bar;
			foo['x']=100;
			foo['y']=200;

			bar['a']=11;
			bar['b']=22;
			bar['c']=33;

			foo.swap(bar);

			std::cout << "foo contains:\n";
			for (ft::map<char,int>::iterator it=foo.begin(); it!=foo.end(); ++it)
				std::cout << it->first << " => " << it->second << '\n';

			std::cout << "bar contains:\n";
			for (ft::map<char,int>::iterator it=bar.begin(); it!=bar.end(); ++it)
				std::cout << it->first << " => " << it->second << '\n';

		}
		std::cout << "*************** clear ****************" << std::endl;
		{
			ft::map<char,int> mymap;

			mymap['x']=100;
			mymap['y']=200;
			mymap['z']=300;

			std::cout << "mymap contains:\n";
			for (ft::map<char,int>::iterator it=mymap.begin(); it!=mymap.end(); ++it)
				std::cout << it->first << " => " << it->second << '\n';

			mymap.clear();
			mymap['a']=1101;
			mymap['b']=2202;

			std::cout << "mymap contains:\n";
			for (ft::map<char,int>::iterator it=mymap.begin(); it!=mymap.end(); ++it)
				std::cout << it->first << " => " << it->second << '\n';
		}
	
		std::cout << "*************** find ****************" << std::endl;
		{
			ft::map<char,int> mymap;
			ft::map<char,int>::iterator it;

			mymap['a']=50;
			mymap['b']=100;
			mymap['c']=150;
			mymap['d']=200;

			it = mymap.find('b');
			if (it != mymap.end())
				mymap.erase (it);

			// print content:
			std::cout << "elements in mymap:" << '\n';
			std::cout << "a => " << mymap.find('a')->second << '\n';
			std::cout << "c => " << mymap.find('c')->second << '\n';
			std::cout << "d => " << mymap.find('d')->second << '\n';
		}
    std::cout << "************** lower_and_upper_bound ***********/" << std::endl;
    {
      ft::map<char,int> mymap;
      ft::map<char,int>::iterator itlow,itup;

      mymap['a']=20;
      mymap['b']=40;
      mymap['c']=60;
      mymap['d']=80;
      mymap['e']=100;

      itlow=mymap.lower_bound ('b');
      itup=mymap.upper_bound ('d');

      mymap.erase(itlow,itup);


      for (ft::map<char,int>::iterator it=mymap.begin(); it!=mymap.end(); ++it)
        std::cout << it->first << " => " << it->second << '\n';
    }

     std::cout << "************** Equal range ***********/" << std::endl;
     {
         ft::map<char,int> mymap;

        mymap['a']=10;
        mymap['b']=20;
        mymap['c']=30;

        ft::pair<ft::map<char,int>::iterator,ft::map<char,int>::iterator> ret;
        ret = mymap.equal_range('b');

        std::cout << "lower bound points to: ";
        std::cout << ret.first->first << " => " << ret.first->second << '\n';

        std::cout << "upper bound points to: ";
        std::cout << ret.second->first << " => " << ret.second->second << '\n';
     }

}

int   main()
{
  vector_test();
  stack_test();
  map_test();
  return 0;
}