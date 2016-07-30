/**
 * @file   tests.cpp
 * @Author Me (roxana.lafuente@gmail.com)
 * @date   July, 2016
 * @brief  BST Tests.
 *
 * BST - C++ Tests with Google Code.
 */
#include <gtest/gtest.h>
#include "bst.h"


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
    (*bst).insertNode(12);
    // We should be able to find both the root and the node we have just inserted.
    ASSERT_EQ(-1, (*bst).search(-1)->value);
    ASSERT_EQ(12, (*bst).search(12)->value);
    (*bst).deleteNode(12);
    // We should not find the node we have just added and deleted.
    ASSERT_EQ(NULL, (*bst).search(12));
    // The root should be intact.
    ASSERT_EQ(-1, (*bst).search(-1)->value);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest( &argc, argv );
    return RUN_ALL_TESTS();
}