#include <iostream>     // std::cout
//#include <iterator>     // std::iterator_traits
#include "iterators.hpp"
#include "iterators_traits.hpp"
#include <typeinfo>     // typeid

int main() {
  typedef ft::iterator_traits<int*> traits;
  if (typeid(traits::iterator_category)==typeid(std::random_access_iterator_tag))
    std::cout << "int* is a random-access iterator";
  return 0;
}