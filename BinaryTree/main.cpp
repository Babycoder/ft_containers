#include "BinaryTree.hpp"



struct Node
{
    int key;
    Node *left;
    Node *right;
};

 
Node    *createNode(int key)
{
    Node *node = new Node();

    node->key = key;
    node->left = NULL;
    node->right = NULL;
    return node;
}



int main()
{
    Node *root = createNode(10);
    root->left = createNode(5);

    std::cout << root->key << std::endl;
    std::cout << root->left->key << std::endl;
    
    return 0;
}