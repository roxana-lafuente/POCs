/**
 * @file   bst.h
 * @Author Me (roxana.lafuente@gmail.com)
 * @date   July, 2016
 * @brief  C++ Binary Search Tree (BST) implementation.
 *
 * BST - Binary Search Tree
 */

#ifndef BST_H
#define BST_H

#include <iostream>
#include <stack>
#include <list>

using namespace std;


/* Enumeration to decide which implementation to use */
enum algorithmType
{
    RECURSIVE, // Recursive implementation
    ITERATIVE  // Iterative implementation
};


enum DIRECTION
{
    LEFT, // Should go to the left sub-tree.
    RIGHT // Should go to the right sub-tree.
};

/**
 * @name    BST
 * @brief   Binary Search Tree
 *
 * This API provides an implementation of a BST.
 *
 * Example Usage:
 * @code
 *   node<int>* root = new node<int>(12, NULL, NULL, RECURSIVE);
 *   list<int> nodesToInsert = {10, 9, 11, 30, 25, 40, 24, 26, 35, 41};
 *   list<int>::iterator it = nodesToInsert.begin();
 *   while(it != nodesToInsert.end())
 *   {
 *       (*root).insertNode(*it);
 *       it++;
 *   }
 *   (*root).print();
 *   (*root).deleteNode(10);
 *   (*root).print();
 *   delete root;
 * @endcode
 */
template <typename T>
struct node
{
    /* Attributes */
    T value; // value of the node
    node<T>* left; // left tree
    node<T>* right; // right tree
    algorithmType mode; // iterative or recursive

    /* Constructor */
    node(T v, node<T>* l, node<T>* r, algorithmType m) : value(v),
                                                         left(l),
                                                         right(r),
                                                         mode(m) {}

    /* Copy constructor */
    node(const node<T>& n);

    /* Public methods */
    node<T>* getGreatestNode(node<T>* n);
    void insertNode(T v);
    void deleteNode(T v);
    node<T>* search(T v);
    void print();

private:
    /* Private methods */
    node<T>* recursiveGetGreatestNode(node<T>* n);
    node<T>* iterativeGetGreatestNode(node<T>* n);

    void recursiveInsertNode(T v, node<T>* n);
    void iterativeInsertNode(T v);

    node<T>* recursiveDeleteNode(T v, node<T>* n);
    void iterativeDeleteNode(T v);

    node<T>* recursiveSearch(T v, node<T>* n);
    node<T>* iterativeSearch(T v, node<T>* n);

    void recursivePrint(node<T>* n);
    void iterativePrint();

};


/**
 * @name    getGreatestNode
 * @brief   Returns the greatest node in the given BST.
 *
 * @param [n] Root of the BST.
 *
 * @retval Greatest node in the tree.
 */
template <typename T>
node<T>* node<T>::getGreatestNode(node<T>* n)
{
    switch (mode)
    {
        default:
        case(RECURSIVE):
        {
            return recursiveGetGreatestNode(n);
            break;
        }
        case(ITERATIVE):
        {
            return iterativeGetGreatestNode(n);
            break;
        }
    }
}


/**
 * @name    recursiveGetGreatestNode
 * @brief   Recursively returns the greatest node in the given BST
 *
 * @param [n] Root of the BST.
 *
 * @retval Greatest node in the tree.
 */
template <typename T>
node<T>* node<T>::recursiveGetGreatestNode(node<T>* n)
{
    // Return NULL if the root is NULL.
    if (!n)
    {
        return NULL;
    }

    if(n->right != NULL)
    {
        return recursiveGetGreatestNode(n->right);
    }
    else
    {
        return n;
    }
}


/**
 * @name    iterativeGetGreatestNode
 * @brief   Iteratively returns the greatest node in the given BST
 *
 * @param [n] Root of the BST.
 *
 * @retval Greatest node in the tree.
 */
template <typename T>
node<T>* node<T>::iterativeGetGreatestNode(node<T>* n)
{
    node<T>* it = n;

    // Return NULL if the root is NULL.
    if (!n)
    {
        return NULL;
    }


    while(it->right != NULL)
    {
        it = it->right;
    }

    return it;
}


/**
 * @name    insertNode
 * @brief   Inserts a new node to the BST
 *
 * @param [v] Value to insert.
 */
template <typename T>
void node<T>::insertNode(T v)
{
    switch (mode)
    {
        default:
        case(RECURSIVE):
        {
            recursiveInsertNode(v, this);
            break;
        }
        case(ITERATIVE):
        {
            iterativeInsertNode(v);
            break;
        }
    }
}


/**
 * @name    recursiveInsertNode
 * @brief   Recursively inserts a node
 *
 * @param [v] Value to insert.
 */
template <typename T>
void node<T>::recursiveInsertNode(T v, node<T>* n)
{
    // Return NULL if the root is NULL.
    if (n)
    {
        if(v > n->value)
        {
            if(n->right != NULL)
            {
                recursiveInsertNode(v, n->right);
            }
            else
            {
                n->right = new node<T>(v, NULL, NULL, mode);
            }
        }
        else if(v < n->value)
        {
            if (n->left != NULL)
            {
                recursiveInsertNode(v, n->left);
            }
            else
            {
                n->left = new node<T>(v, NULL, NULL, mode);
            }
        }
    }
}


/**
 * @name    iterativeInsertNode
 * @brief   Iteratively inserts a node
 *
 * @param [v] Value to insert.
 */
template <typename T>
void node<T>::iterativeInsertNode(T v)
{
    node<T>* n = this;
    bool inserted = false;
    while (!inserted)
    {
        if(v > n->value)
        {
            if(n->right != NULL)
            {
                n = n->right;
            }
            else
            {
                n->right = new node<T>(v, NULL, NULL, mode);
                inserted = true;
            }
        }
        else if(v < n->value)
        {
            if (n->left != NULL)
            {
                n = n->left;
            }
            else
            {
                n->left = new node<T>(v, NULL, NULL, mode);
                inserted = true;
            }
        }
    }
}


/**
 * @name    deleteNode
 * @brief   Deletes a specific node from the BST
 *
 * @param [v] Value to delete.
 */
template <typename T>
void node<T>::deleteNode(T v)
{
    switch (mode)
    {
        default:
        case(RECURSIVE):
        {
            recursiveDeleteNode(v, this);
            break;
        }
        case(ITERATIVE):
        {
            iterativeDeleteNode(v);
            break;
        }
    }
}


/**
 * @name    recursiveDeleteNode
 * @brief   Recursively deletes a node
 *
 * @param [v] Value to delete.
 */
template <typename T>
node<T>* node<T>::recursiveDeleteNode(T v, node<T>* n)
{
    node<T>* toDelete;
    if(n == NULL)
    {
        // We did not find the value. Everything stays as it was.
        return n;
    }
    else if(v > n->value)
    {
        // The node to delete is in the right tree.
        n->right = recursiveDeleteNode(v, n->right);
    }
    else if(v < n->value)
    {
        // The node to delete is in the left tree.
        n->left = recursiveDeleteNode(v, n->left);
    }
    else // (n->value == v)
    {
        // Case I: Leaf.
        if(n->left == NULL && n->right == NULL)
        {
            delete n;
            n = NULL;
        }
        // Case II A: Has a right child.
        else if(n->left==NULL && n->right!=NULL)
        {
            toDelete = n->right;
            n->value = toDelete->value;
            n->right = toDelete->right;
            n->left = toDelete->left;
            delete toDelete;
        }
        // Case II B: Has a left child.
        else if(n->left!=NULL && n->right==NULL)
        {
            toDelete = n->left;
            n->value = toDelete->value;
            n->right = toDelete->right;
            n->left = toDelete->left;
            delete toDelete;
        }
        // Case III: Has two childs.
        else
        {
            toDelete = recursiveGetGreatestNode(n->left);
            n->value = toDelete->value;
            n->right = recursiveDeleteNode(toDelete->value, n->right);
        }
    }
    return n;
}


/**
 * @name    iterativeDeleteNode
 * @brief   Iteratively deletes a node
 *
 * @param [v] Value to delete.
 */
template <typename T>
void node<T>::iterativeDeleteNode(T v)
{
    node<T>* toDelete;
    node<T>* parent = this;
    node<T>* n = this;
    DIRECTION dir;
    bool deleted = false;
    while(n != NULL and !deleted)
    {
        if(v > n->value)
        {
            // The node to delete is in the right tree.
            parent = n;
            n = n->right;
            dir = RIGHT;
        }
        else if(v < n->value)
        {
            // The node to delete is in the left tree.
            parent = n;
            n = n->left;
            dir = LEFT;
        }
        else // (n->value == v)
        {
            // Case I: Leaf.
            if(n->left == NULL && n->right == NULL)
            {
                if (dir)
                    parent->right = NULL;
                else
                    parent->left = NULL;
                delete n;
            }
            // Case II A: Has a right child.
            else if(n->left==NULL && n->right!=NULL)
            {
                toDelete = n->right;
                n->value = toDelete->value;
                n->right = toDelete->right;
                n->left = toDelete->left;
                delete toDelete;
            }
            // Case II B: Has a left child.
            else if(n->left!=NULL && n->right==NULL)
            {
                toDelete = n->left;
                n->value = toDelete->value;
                n->right = toDelete->right;
                n->left = toDelete->left;
                delete toDelete;
            }
            // Case III: Has two childs.
            else
            {
                toDelete = iterativeGetGreatestNode(n->left);
                n->value = toDelete->value;
                if (n->left == toDelete)
                    n->left = NULL;
            }
            deleted = true;
        }
    }
}


/**
 * @name    search
 * @brief   Searches for a specific node and returns it
 *
 * @param [v] Searches for a value and returns the corresponding node.
 *
 * @retparam Node with value v.
 */
template <typename T>
node<T>* node<T>::search(T v)
{
    switch (mode)
    {
        default:
        case(RECURSIVE):
        {
            return recursiveSearch(v, this);
            break;
        }
        case(ITERATIVE):
        {
            return iterativeSearch(v, this);
            break;
        }
    }
}


/**
 * @name    recursiveSearch
 * @brief   Recursively searches for a specific node
 *
 * @param [v] Searches for a value and returns the corresponding node.
 *
 * @retparam Node with value v.
 */
template <typename T>
node<T>* node<T>::recursiveSearch(T v, node<T>* n)
{
    if(n == NULL)
    {
        return NULL;
    }
    else if(n->value == v)
    {
        return n;
    }
    else if(v > n->value)
    {
        recursiveSearch(v, n->right);
    }
    else if(v < n->value)
    {
        recursiveSearch(v, n->left);
    }
}


/**
 * @name    iterativeSearch
 * @brief   Iteratively searches for a specific node
 *
 * @param [v] Searches for a value and returns the corresponding node.
 *
 * @retparam Node with value v.
 */
template <typename T>
node<T>* node<T>::iterativeSearch(T v, node<T>* n)
{
    bool found = false;
    while(n != NULL and !found)
    {
        if(n->value == v)
        {
            found = true;
        }
        else if(v > n->value)
        {
            n = n->right;
        }
        else if(v < n->value)
        {
            n = n->left;
        }
    }
    return n;
}


/**
 * @name    print
 * @brief   Prints the BST
 */
template <typename T>
void node<T>::print()
{
    switch (mode)
    {
        default:
        case(RECURSIVE):
        {
            recursivePrint(this);
            break;
        }
        case(ITERATIVE):
        {
            iterativePrint();
            break;
        }
    }
    cout << endl;
}


/**
 * @name    recursivePrint
 * @brief   Recursively prints a BST
 */
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


/**
 * @name    iterativePrint
 * @brief   Iteratively prints a BST
 */
template <typename T>
void node<T>::iterativePrint()
{
    // TODO
    cout << "NOT IMPLEMENTED, momentarily using recursive implementation" << endl;
    recursivePrint(this);
}

#endif // BST_H