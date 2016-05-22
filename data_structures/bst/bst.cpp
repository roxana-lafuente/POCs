/*
BST - Binary Search Tree
Author: Roxana Anabel Lafuente.
Date: 22-05-2016
*/

#include <iostream>

using namespace std;

template <typename T>
struct node
{
    T value;
    node<T>* left;
    node<T>* right;

    node(T v, node<T>* l, node<T>* r) : value(v), left(l), right(r) {}
    ~node()
    {
        // for every node in the BST, delete it
    }
    void insertNode(T v);
    void recursiveInsertNode(T v, node<T>* n);
    void deleteNode(T v);
    void recursiveDeleteNode(T v, node<T>* n);
    node<T> search(T v);
    void print();

};

/* Inserts a new node to the BST */
template <typename T>
void node<T>::insertNode(T v)
{
    recursiveInsertNode(v, this);
}

/* Recursively insert a node */
template <typename T>
void node<T>::recursiveInsertNode(T v, node<T>* n)
{
    if(n->left==NULL && n->right==NULL)
    {
        // Add new node to the left tree.
        left = new node<T>(v, NULL, NULL);
    }
    else if(v>value)
    {
        // Insert node to the right tree.
        recursiveInsertNode(v, right);
    }
    else
    {
        // Insert node to the left tree.
        recursiveInsertNode(v, left);
    }
}

/* Deletes a specific node from the BST */
template <typename T>
void node<T>::deleteNode(T v)
{
    recursiveDeleteNode(v, this);
}

/* Recursively delete a node */
template <typename T>
void node<T>::recursiveDeleteNode(T v, node<T>* n)
{
    if(n->value == v)
    {
        if(n->left==NULL && n->right==NULL)
        {
            //left = new node<T>(v, NULL, NULL);
        }
    }
    else if(v>value)
    {
        // The node to delete is in the right tree.
        recursiveDeleteNode(v, right);
    }
    else
    {
        // The node to delete is in the left tree.
        recursiveDeleteNode(v, left);
    }
}

/* Searches for a specific node and returns it */
template <typename T>
node<T> node<T>::search(T v)
{
    // TODO
}

/* Prints the BST */
template <typename T>
void node<T>::print()
{
    // TODO
}

int
main(void)
{
    node<int> root(2, NULL, NULL);
    root.insertNode(3);
    return 0;
}