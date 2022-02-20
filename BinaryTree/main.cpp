
#include "../map/map.hpp"
#include "avltree.hpp"
#include <functional>




int main()
{

   // ft::AVL<value_type, Compare, Alloc> _avl;

    ft::AVL<ft::pair<const int, char>, std::less<int>, std::allocator<ft::pair<const int, char>>>    _tree;
    ft::map<int, char> mm;


    mm.insert({1, 'a'});
    //_tree.insert({1, 'a'});
   // _tree.insert({2, 'b'});
    //_tree.insert({0, 'z'});
    //_tree.insert({3, 'c'});
   // std::cout << _tree.root->data->first << std::endl;
   // _tree.remove({0, 'x'});
   // _tree.remove({2, 'x'});
    mm.erase(1);
   mm[10] = 'z';
    std::cout << mm[10] << std::endl;

    std::cout << mm[1] << std::endl;

    //_tree.display();
    //ft::AVL < {'a', 1}, std::less<char, std::allocator<ft::pair<const char,int>> tree;

    
    
    return 0;
}