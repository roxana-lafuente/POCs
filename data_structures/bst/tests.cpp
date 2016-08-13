/**
 * @file   tests.cpp
 * @Author Me (roxana.lafuente@gmail.com)
 * @date   July, 2016
 * @brief  BST Tests.
 *
 * BST - C++ Tests with Google Code.
 */
#include <gtest/gtest.h>
#include <algorithm> // for random_shuffle
#include <cstdlib>   // srand, rand
#include <vector>
#include <ctime>     // time
#include "bst.h"

static const int N = 500; // BST nodes size
static const int T = 150; // Times to repeat tests

/**
 * @name    BST Recursive Tests
 * @brief   Binary Search Tree Recursive Tests
 *
 * This tests the recursive implementation of a BST.
 */
class BSTTEST : public ::testing::Test
{ 
public: 

	node<int>* recursiveBST;
    node<int>* iterativeBST;

	void SetUp( )
    { 
		// Create node with root -1
		recursiveBST = new node<int>(-1, NULL, NULL, RECURSIVE);
        iterativeBST = new node<int>(-1, NULL, NULL, ITERATIVE);
	}

	void TearDown( )
    { 
		delete recursiveBST;
        delete iterativeBST;
	}

};

void InsertAndDeleteOneNode(node<int>* bst)
{
    bst->insertNode(12);
    // We should be able to find both the root and the node we have just inserted.
    ASSERT_EQ(-1, bst->search(-1)->value);
    ASSERT_EQ(12, bst->search(12)->value);
    bst->deleteNode(12);
    // We should not find the node we have just added and deleted.
    ASSERT_EQ(NULL, bst->search(12));
    // The root should be intact.
    ASSERT_EQ(-1, bst->search(-1)->value);
}

TEST_F(BSTTEST, TestInsertAndDeleteOneNode)
{
    InsertAndDeleteOneNode(recursiveBST);
    InsertAndDeleteOneNode(iterativeBST);
}

void DeleteLeaf(node<int>* bst)
{
    vector<int> nodes = {12, -12, -112, -5};
    for (int i=0; i<nodes.size(); i++)
    {
        bst->insertNode(nodes[i]);
        // Check if it was correctly added.
        ASSERT_EQ(nodes[i], bst->search(nodes[i])->value);
    }
    // Delete one LEAF.
    bst->deleteNode(-5);
    // We should not find the node we have just deleted.
    ASSERT_EQ(NULL, bst->search(-5));
    // The root should be intact.
    ASSERT_EQ(-1, bst->search(-1)->value);
}

TEST_F(BSTTEST, TestDeleteLeaf)
{
    DeleteLeaf(recursiveBST);
    DeleteLeaf(iterativeBST);
}

void DeleteDoesNotExist(node<int>* bst)
{
    vector<int> nodes = {12, -12, -112, -5};
    for (int i=0; i<nodes.size(); i++)
    {
        bst->insertNode(nodes[i]);
        // Check if it was correctly added.
        ASSERT_EQ(nodes[i], bst->search(nodes[i])->value);
    }
    // Delete a node that does not exist.
    bst->deleteNode(-7);
    // Check everything is as it was.
    for (int i=0; i<nodes.size(); i++)
    {
        ASSERT_EQ(nodes[i], bst->search(nodes[i])->value);
    }
    // The root should be intact.
    ASSERT_EQ(-1, bst->search(-1)->value);
}

TEST_F(BSTTEST, TestDeleteDoesNotExist) {
    DeleteDoesNotExist(recursiveBST);
    DeleteDoesNotExist(iterativeBST);
}

void InsertAndDeleteSeveralNodes(node<int>* bst)
{
    vector<int> nodes; // Nodes to keep track of.
    int j=0, element;

    for(int times = 0; times < T; times++)
    {
        nodes = {10, 9, 11, 30, 25, 40, 24, 26, 35, 41};
        // Add the nodes.
        for(int i=0; i < nodes.size(); i++)
        {
            bst->insertNode(nodes[i]);
            // Check if it was correctly added.
            ASSERT_EQ(nodes[i], bst->search(nodes[i])->value);
        }
        // Start deleting nodes at random.
        random_shuffle(nodes.begin(), nodes.end());
        int i = 0;
        while(i < nodes.size())
        {
            element = nodes.back();
            bst->deleteNode(element);
            nodes.pop_back();
            // Check if it was correctly deleted.
            ASSERT_EQ(NULL, bst->search(element));
            // All other nodes should still be on the BST.
            for (j = 0; j < nodes.size(); j++)
            {
                ASSERT_EQ(nodes[j], bst->search(nodes[j])->value);
            }
        }

        // The root should be intact.
        ASSERT_EQ(-1, bst->search(-1)->value);

        nodes.clear();
    }
}

TEST_F(BSTTEST, TestInsertAndDeleteSeveralNodes)
{
    InsertAndDeleteSeveralNodes(recursiveBST);
    InsertAndDeleteSeveralNodes(iterativeBST);
}

void DeleteRoot(node<int>* bst)
{
    vector<int> nodes = {12, -12, -112, -5};
    for (int i=0; i<nodes.size(); i++)
    {
        bst->insertNode(nodes[i]);
        // Check if it was correctly added.
        ASSERT_EQ(nodes[i], bst->search(nodes[i])->value);
    }
    // Delete the root.
    bst->deleteNode(-1);
    // The root should be not be found.
    ASSERT_EQ(NULL, bst->search(-1));
    // Check everything else is as it was.
    for (int i=0; i<nodes.size(); i++)
    {
        ASSERT_EQ(nodes[i], bst->search(nodes[i])->value);
    }
}

TEST_F(BSTTEST, TestDeleteRoot)
{
    DeleteRoot(recursiveBST);
    DeleteRoot(iterativeBST);
}

void SearchOneNode(node<int>* bst)
{
    vector<int> nodes = {12, -12, 12, -112, -5};
    for (int i=0; i<nodes.size(); i++)
    {
        bst->insertNode(nodes[i]);
        // Check if it was correctly added.
        ASSERT_EQ(nodes[i], bst->search(nodes[i])->value);
    }
    // All nodes should be found.
    for (int i=0; i<nodes.size(); i++)
    {
        ASSERT_EQ(nodes[i], bst->search(nodes[i])->value);
    }
}

TEST_F(BSTTEST, TestSearchOneNode)
{
    SearchOneNode(recursiveBST);
    SearchOneNode(iterativeBST);
}

void SearchAll(node<int>* bst)
{
    vector<int> nodes = {7, -770, 12, 7, 43, 7, -12, 7, 43, 7, -112, 7, -5, 43, 7, 59, -110, 55, 909};
    vector<node<int>*> foundNodes;

    for (int i=0; i<nodes.size(); i++)
    {
        bst->insertNode(nodes[i]);
        // Check if it was correctly added.
        ASSERT_EQ(nodes[i], bst->search(nodes[i])->value);
    }
    // Search all should find zero nodes.
    bst->searchAll(14, foundNodes);
    ASSERT_EQ(0, foundNodes.size());
    // Search all should find one node.
    foundNodes.clear();
    bst->searchAll(12, foundNodes);
    ASSERT_EQ(1, foundNodes.size());
    ASSERT_EQ(12, foundNodes[0]->value);
    // Search all should find three nodes.
    foundNodes.clear();
    bst->searchAll(43, foundNodes);
    ASSERT_EQ(3, foundNodes.size());
    for(int i=0; i<3; i++)
    {
        ASSERT_EQ(43, foundNodes[i]->value);
    }
    // Search all should find seven nodes.
    foundNodes.clear();
    bst->searchAll(7, foundNodes);
    ASSERT_EQ(7, foundNodes.size());
    for(int i=0; i<7; i++)
    {
        ASSERT_EQ(7, foundNodes[i]->value);
    }
}

TEST_F(BSTTEST, TestSearchAllZeroNode)
{
    SearchAll(recursiveBST);
    SearchAll(iterativeBST);
}

void RandomizedTest(node<int>* bst)
{
    vector<int> nodes;
    vector<node<int>*> foundNodes;
    // Generate N random nodes to insert.
    for(int times=0; times<T; times++)
    {
        srand(time(NULL));
        for (int i=0; i<N; i++)
        {
            nodes.push_back((int)(rand() * pow(-1, (rand() % 3) + 1)) % 25);
        }
        // Insert them.
        for (int i=0; i<nodes.size(); i++)
        {
            bst->insertNode(nodes[i]);
            // Check if it was correctly added.
            ASSERT_EQ(nodes[i], bst->search(nodes[i])->value);
        }
        // Delete the nodes in random order.
        random_shuffle(nodes.begin(), nodes.end());
        int i=0, j=0, element, sizeBefore, sizeAfter;
        while(i < nodes.size())
        {
            element = nodes.back();
            foundNodes.clear();
            bst->searchAll(element, foundNodes);
            sizeBefore = foundNodes.size();
            bst->deleteNode(element);
            foundNodes.clear();
            bst->searchAll(element, foundNodes);
            sizeAfter = foundNodes.size();
            nodes.pop_back();
            // Check if it was correctly deleted.
            ASSERT_TRUE(sizeBefore > sizeAfter || (sizeBefore == sizeAfter && sizeAfter == 0));
            // All other nodes should still be on the BST.
            for (j = 0; j < nodes.size(); j++)
            {
                ASSERT_EQ(nodes[j], bst->search(nodes[j])->value);
            }
        }
        // Check everything else is as it was.
        for (int i=0; i<nodes.size(); i++)
        {
            ASSERT_EQ(nodes[i], bst->search(nodes[i])->value);
        }
    }
}

TEST_F(BSTTEST, TestRandomizedTest)
{
    RandomizedTest(recursiveBST);
    RandomizedTest(iterativeBST);
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest( &argc, argv );
    return RUN_ALL_TESTS();
}