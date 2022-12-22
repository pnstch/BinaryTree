#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include <BinaryTree.cpp>


using namespace std;


TEST(BinaryTreeTestGroup, BinaryTree) {
    // Arange
    const int expected_data = 10;
    BinaryTree* myTree = new BinaryTree();

    // Act
    myTree->root->data = expected_data;

    // Assert
    ASSERT_TRUE(myTree->root->data == expected_data);
}

TEST(BinaryTreeTestGroup, BinaryTreeInsertKey) {
    // Arange
    const int expected_data = 3;
    BinaryTree* myTree = new BinaryTree();

    // Act
    myTree->insert(expected_data);

    // Assert
    ASSERT_TRUE(myTree->root->data == expected_data);
}

TEST(BinaryTreeTestGroup, BinaryTreeInsertNode) {
    // Arange
    const int expected_key = 3;
    BinaryTree* myTree = new BinaryTree();
    btnode* myNode = new btnode(4);

    // Act
    myTree->insert(expected_key, myNode);
    btnode* treeNode = myTree->root->right;

    // Assert
    ASSERT_TRUE(treeNode->data == expected_key);
}

TEST(BinaryTreeTestGroup, BinaryTreeDelete) {
    // Arange
    BinaryTree* myTree = new BinaryTree();

    // Act
    myTree->deleteTree();

    // Assert
    ASSERT_TRUE(myTree->root == nullptr);
}

TEST(BinaryTreeTestGroup, BinaryTreeEmpty) {
    // Arange
    const int expected_data = 3;
    BinaryTree* myTree = new BinaryTree();

    // Act
    myTree->insert(expected_data);
    bool isEmpty = myTree->IsEmpty();

    // Assert
    ASSERT_FALSE(isEmpty == true);
}

int main(int argc, char **argv)
{
  ::testing::InitGoogleTest(&argc, argv);

  return RUN_ALL_TESTS();
}