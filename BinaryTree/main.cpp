#include "BinaryTree.hpp"






int main()
{
    Node *root = createNode(10);
    root->left = createNode(5);

    std::cout << root->key << std::endl;
    std::cout << root->left->key << std::endl;
    
    return 0;
}