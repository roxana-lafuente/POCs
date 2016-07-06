#include "bst.h"

using namespace std;
template class node<int>;
int
main(void)
{
    node<int>* root = new node<int>(12, NULL, NULL, RECURSIVE);
    list<int> nodesToInsert = {10, 9, 11, 30, 25, 40, 24, 26, 35, 41};
    list<int>::iterator it = nodesToInsert.begin();
    while(it != nodesToInsert.end())
    {
        (*root).insertNode(*it);
        it++;
    }
    (*root).print();
    (*root).deleteNode(10);
    (*root).print();
    delete root;
    // todo: delete de un node que no existe no anda
    return 0;
}