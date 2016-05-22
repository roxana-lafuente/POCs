/*
BST - Binary Search Tree
Author: Roxana Anabel Lafuente.
Date: 22-05-2016
*/

#include <iostream>
#include <stack>
#include <list>

using namespace std;

/* Enumeration to decide which implementation to use */
enum algorithmType
{
    RECURSIVE,
    ITERATIVE
};

/* BST node */
template <typename T>
struct node
{
    T value; // value of the node
    node<T>* left; // left tree
    node<T>* right; // right tree
    algorithmType mode; // iterative or recursive

    node(T v, node<T>* l, node<T>* r, algorithmType m) : value(v),
                                                         left(l),
                                                         right(r),
                                                         mode(m) {}
    ~node()
    {
        if (left)
            delete left;
        if (right)
            delete right;
    }

    node<T> getGreatestNode();
    node<T> recursiveGetGreatestNode(node<T>* n);
    node<T> iterativeGetGreatestNode(node<T>* n);

    void insertNode(T v);
    void recursiveInsertNode(T v, node<T>* n);
    void iterativeInsertNode(T v);

    void deleteNode(T v);
    void recursiveDeleteNode(T v, node<T>* n);
    void iterativeDeleteNode(T v);

    node<T> search(T v);
    void recursiveSearch(T v, node<T>* n);
    void iterativeSearch(T v);

    void print();
    void recursivePrint(node<T>* n);
    void iterativePrint();

};

/* Returns the greatest node in the BST */
template <typename T>
node<T> node<T>::getGreatestNode()
{
    switch (mode)
    {
        default:
        case(RECURSIVE):
        {
            return recursiveGetGreatestNode(this);
        }
        case(ITERATIVE):
        {
            return iterativeGetGreatestNode(this);
        }
    }
}

/* Recursively returns the greatest node in the BST */
template <typename T>
node<T> node<T>::recursiveGetGreatestNode(node<T>* n)
{
    if(n->right != NULL)
    {
        return recursiveGetGreatestNode(n->right);
    }
    else
    {
        return n->value;
    }
}

/* Iteratively returns the greatest node in the BST */
template <typename T>
node<T> node<T>::iterativeGetGreatestNode(node<T>* n)
{
    node<T> it = n;
    while(it->right != NULL)
    {
        it = it->right;
    }
    return it->value;
}

/* Inserts a new node to the BST */
template <typename T>
void node<T>::insertNode(T v)
{
    switch (mode)
    {
        default:
        case(RECURSIVE):
        {
            recursiveInsertNode(v, this);
        }
        case(ITERATIVE):
        {
            iterativeInsertNode(v);
        }
    }
}

/* Recursively inserts a node */
template <typename T>
void node<T>::recursiveInsertNode(T v, node<T>* n)
{
    if(v>value)
    {
        if(n->right!=NULL)
        {
            recursiveInsertNode(v, right);
        }
        else
        {
            n->right = new node<T>(v, NULL, NULL, mode);
            cout << "Alloc memory for " << v << endl;
        }
    }
    else if(v<value)
    {
        if (n->left!=NULL)
        {
            recursiveInsertNode(v, left);
        }
        else
        {
            n->left = new node<T>(v, NULL, NULL, mode);
            cout << "Alloc memory for " << v << endl;
        }
    }
}

/* Iteratively inserts a node */
template <typename T>
void node<T>::iterativeInsertNode(T v)
{
    // TODO
}

/* Deletes a specific node from the BST */
template <typename T>
void node<T>::deleteNode(T v)
{
    switch (mode)
    {
        default:
        case(RECURSIVE):
        {
            recursiveDeleteNode(v, this);
        }
        case(ITERATIVE):
        {
            iterativeDeleteNode(v, this);
        }
    }
}

/* Recursively deletes a node */
template <typename T>
void node<T>::recursiveDeleteNode(T v, node<T>* n)
{
    if(n->value == v)
    {
        node<T>* toDelete;
        if(n->left==NULL && n->right==NULL)
        {
            toDelete = n;
        }
        else if(n->left==NULL && n->right!=NULL)
        {
            toDelete = n->right;
            n->value = toDelete->value;
            n->right = toDelete->right;
            n->left = toDelete->left;
        }
        else if(n->left!=NULL && n->right==NULL)
        {
            toDelete = n->left;
            n->value = toDelete->value;
            n->right = toDelete->right;
            n->left = toDelete->left;
        }
        else
        {
            toDelete = getGreatestNode(n->left);
            n->value = toDelete->value;
            n->right = toDelete->right;
            n->left = toDelete->left;
        }
        delete toDelete;
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

/* Iteratively deletes a node */
template <typename T>
void node<T>::iterativeDeleteNode(T v)
{
    // TODO
}

/* Searches for a specific node and returns it */
template <typename T>
node<T> node<T>::search(T v)
{
    switch (mode)
    {
        default:
        case(RECURSIVE):
        {
            recursiveSearch(v, this);
        }
        case(ITERATIVE):
        {
            iterativeSearch(v, this);
        }
    }
}

/* Recursively searches for a specific node */
template <typename T>
void node<T>::recursiveSearch(T v, node<T>* n)
{
    if(n->value == v)
    {
        return n;
    }
    else if(v>value)
    {
        recursiveSearch(v, right);
    }
    else
    {
        recursiveSearch(v, left);
    }
}

/* Iteratively searches for a specific node */
template <typename T>
void node<T>::iterativeSearch(T v)
{
    // TODO
}

/* Prints the BST */
template <typename T>
void node<T>::print()
{
    switch (mode)
    {
        default:
        case(RECURSIVE):
        {
            recursivePrint(this);
        }
        case(ITERATIVE):
        {
            iterativePrint();
        }
    }
    cout << endl;
}

/* Recursively prints a BST */
template <typename T>
void node<T>::recursivePrint(node<T>* n)
{
    if(n != NULL)
    {
        cout << "( ";
        if (n->left != NULL)
        {
            recursivePrint(n->left);
        }
        else
        {
            cout << " LEAF ";
        }
        cout << n->value;
        if(n->right != NULL)
        {
            recursivePrint(n->right);
        }
        else
        {
            cout << " LEAF ";
        }
        cout << " )";
    }
}

/* Iteratively prints a BST */
template <typename T>
void node<T>::iterativePrint()
{
    // TODO
}

int
main(void)
{
    node<int> root(12, NULL, NULL, RECURSIVE);
    list<int> nodesToInsert = {10, 9};//, 11, 30, 25, 40, 24, 26, 35, 41};
    list<int>::iterator it = nodesToInsert.begin();
    while(it != nodesToInsert.end())
    {
        root.insertNode(*it);
        it++;
    }
    root.print();
    return 0;
}