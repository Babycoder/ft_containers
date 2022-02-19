#include "avltree.hpp"

#include <functional>




int main()
{

   // ft::AVL<value_type, Compare, Alloc> _avl;

    ft::AVL<ft::pair<const int, char>, std::less<int>, std::allocator<ft::pair<const int, char>>>    _tree;
   
    _tree.insert({1, 'a'});
    _tree.insert({2, 'b'});
    _tree.insert({0, 'z'});
    //_tree.insert({3, 'c'});
   // std::cout << _tree.root->data->first << std::endl;
    _tree.remove({0, 'x'});
    _tree.display();
    //ft::AVL < {'a', 1}, std::less<char, std::allocator<ft::pair<const char,int>> tree;

    
    
    return 0;
}