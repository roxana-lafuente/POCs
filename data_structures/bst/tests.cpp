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

static const int N = 5;

/**
 * @name    BST Recursive Tests
 * @brief   Binary Search Tree Recursive Tests
 *
 * This tests the recursive implementation of a BST.
 */
class BSTRecursiveTEST : public ::testing::Test { 
public: 

	node<int>* bst;

	void SetUp( ) { 
		// Create node with root -1
		bst = new node<int>(-1, NULL, NULL, RECURSIVE);
	}

	void TearDown( ) { 
		delete bst;
	}

};

TEST_F(BSTRecursiveTEST, InsertAndDeleteOneNode) {
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

TEST_F(BSTRecursiveTEST, DeleteLeaf) {
	vector<int> nodes = {12, -12, -112, -5};
	for (int i=0; i<nodes.size(); i++){
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

TEST_F(BSTRecursiveTEST, DeleteDoesNotExist) {
	vector<int> nodes = {12, -12, -112, -5};
	for (int i=0; i<nodes.size(); i++){
    	bst->insertNode(nodes[i]);
        // Check if it was correctly added.
        ASSERT_EQ(nodes[i], bst->search(nodes[i])->value);
	}
    // Delete a node that does not exist.
    bst->deleteNode(-7);
    // Check everything is as it was.
    for (int i=0; i<nodes.size(); i++){
    	ASSERT_EQ(nodes[i], bst->search(nodes[i])->value);
	}
    // The root should be intact.
    ASSERT_EQ(-1, bst->search(-1)->value);
}

TEST_F(BSTRecursiveTEST, InsertAndDeleteSeveralNodes) {
	// Nodes to keep track of.
	vector<int> nodes = {10, 9, 11, 30, 25, 40, 24, 26, 35, 41};

    // Add the nodes.
    int i=0, j=0, element;
    while(i < nodes.size())
    {
        bst->insertNode(nodes[i]);
        // Check if it was correctly added.
        ASSERT_EQ(nodes[i], bst->search(nodes[i])->value);
        i++;
    }
    // Start deleting nodes at random.
    random_shuffle(nodes.begin(), nodes.end());
    i = 0;
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
}

TEST_F(BSTRecursiveTEST, DeleteRoot) {
	vector<int> nodes = {12, -12, -112, -5};
	for (int i=0; i<nodes.size(); i++){
    	bst->insertNode(nodes[i]);
        // Check if it was correctly added.
        ASSERT_EQ(nodes[i], bst->search(nodes[i])->value);
	}
    // Delete the root.
    bst->deleteNode(-1);
	// The root should be not be found.
    ASSERT_EQ(NULL, bst->search(-1));
    // Check everything else is as it was.
    for (int i=0; i<nodes.size(); i++){
    	ASSERT_EQ(nodes[i], bst->search(nodes[i])->value);
	}
}

TEST_F(BSTRecursiveTEST, RandomizedTest) {
    vector<int> nodes;
    vector<node<int>*> foundNodes;
    // Generate N random nodes to insert.
    srand(time(NULL));
    for (int i=0; i<N; i++){
        nodes.push_back(rand() * pow(-1, (rand() % 3) + 1));
    }
    // Insert them.
    for (int i=0; i<nodes.size(); i++){
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
        bst->searchAll(element, foundNodes);
        sizeBefore = foundNodes.size();
        bst->deleteNode(element);
        foundNodes.clear();
        bst->searchAll(element, foundNodes);
        sizeAfter = foundNodes.size();
        if (sizeAfter == 0)
            nodes.pop_back();
        // Check if it was correctly deleted.
        ASSERT_TRUE(sizeBefore > sizeAfter || (sizeBefore == sizeAfter && sizeAfter == 0));
        // All other nodes should still be on the BST.
        for (j = 0; j < nodes.size(); j++)
        {
            ASSERT_EQ(nodes[j], bst->search(nodes[j])->value);
        }
        foundNodes.clear();
    }
    // Check everything else is as it was.
    for (int i=0; i<nodes.size(); i++){
        ASSERT_EQ(nodes[i], bst->search(nodes[i])->value);
    }
}

/**
 * @name    BST Recursive Tests
 * @brief   Binary Search Tree Recursive Tests
 *
 * This tests the recursive implementation of a BST.
 */
class BSTIterativeTEST : public ::testing::Test { 
public: 

    node<int>* bst;

    void SetUp( ) { 
        // Create node with root -1
        bst = new node<int>(-1, NULL, NULL, ITERATIVE);
    }

    void TearDown( ) { 
        delete bst;
    }

};

TEST_F(BSTIterativeTEST, InsertAndDeleteOneNode) {
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

TEST_F(BSTIterativeTEST, DeleteLeaf) {
    vector<int> nodes = {12, -12, -112, -5};
    for (int i=0; i<nodes.size(); i++){
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

TEST_F(BSTIterativeTEST, DeleteDoesNotExist) {
    vector<int> nodes = {12, -12, -112, -5};
    for (int i=0; i<nodes.size(); i++){
        bst->insertNode(nodes[i]);
        // Check if it was correctly added.
        ASSERT_EQ(nodes[i], bst->search(nodes[i])->value);
    }
    // Delete a node that does not exist.
    bst->deleteNode(-7);
    // Check everything is as it was.
    for (int i=0; i<nodes.size(); i++){
        ASSERT_EQ(nodes[i], bst->search(nodes[i])->value);
    }
    // The root should be intact.
    ASSERT_EQ(-1, bst->search(-1)->value);
}

TEST_F(BSTIterativeTEST, InsertAndDeleteSeveralNodes) {
    // Nodes to keep track of.
    vector<int> nodes = {10, 9, 11, 30, 25, 40, 24, 26, 35, 41};

    // Add the nodes.
    int i=0, j=0, element;
    while(i < nodes.size())
    {
        bst->insertNode(nodes[i]);
        // Check if it was correctly added.
        ASSERT_EQ(nodes[i], bst->search(nodes[i])->value);
        i++;
    }
    // Start deleting nodes at random.
    random_shuffle(nodes.begin(), nodes.end());
    i = 0;
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
}

TEST_F(BSTIterativeTEST, DeleteRoot) {
    vector<int> nodes = {12, -12, -112, -5};
    for (int i=0; i<nodes.size(); i++){
        bst->insertNode(nodes[i]);
        // Check if it was correctly added.
        ASSERT_EQ(nodes[i], bst->search(nodes[i])->value);
    }
    // Delete the root.
    bst->deleteNode(-1);
    // The root should be not be found.
    ASSERT_EQ(NULL, bst->search(-1));
    // Check everything is as it was.
    for (int i=0; i<nodes.size(); i++){
        ASSERT_EQ(nodes[i], bst->search(nodes[i])->value);
    }

}

TEST_F(BSTIterativeTEST, RandomizedTest) {
    vector<int> nodes;
    vector<node<int>*> foundNodes;
    // Generate N random nodes to insert.
    srand(time(NULL));
    for (int i=0; i<N; i++){
        nodes.push_back((int)(rand() * pow(-1, (rand() % 3) + 1)) % 25);
    }
    // Insert them.
    for (int i=0; i<nodes.size(); i++){
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
        foundNodes.clear();
    }
    // Check everything else is as it was.
    for (int i=0; i<nodes.size(); i++){
        ASSERT_EQ(nodes[i], bst->search(nodes[i])->value);
    }
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest( &argc, argv );
    return RUN_ALL_TESTS();
}