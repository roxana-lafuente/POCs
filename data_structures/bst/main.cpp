/**
 * @file   main.cpp
 * @Author Me (roxana.lafuente@gmail.com)
 * @date   July, 2016
 * @brief  Simple main example of how to use this library.
 *
 * BST - Example of use.
 */
#include "bst.h"

using namespace std;

template class node<int>;

int
main(void)
{
    // Create a new BST with root 12.
    node<int>* root = new node<int>(12, NULL, NULL, RECURSIVE);

    // Create which values will be inserted.
    list<int> nodesToInsert = {10, 9, 11, 30, 25, 40, 24, 26, 35, 41};

    // Add the nodes.
    list<int>::iterator it = nodesToInsert.begin();
    while(it != nodesToInsert.end())
    {
        (*root).insertNode(*it);
        it++;
    }

    // Print the BST.
    (*root).print();

    // Delete one node.
    (*root).deleteNode(10);

    // Print the BST.
    (*root).print();
    delete root;

    return 0;
}