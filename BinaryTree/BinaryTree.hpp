#pragma once

#include <string>
#include <iostream>

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