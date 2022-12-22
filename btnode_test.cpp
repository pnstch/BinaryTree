#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include <btnode.cpp>


using namespace std;


TEST(NodeTestGroup, NodeTest) {
    // Arange
    const int data = 4;

    // Act
    btnode* node = new btnode(data);

    // Assert
    ASSERT_TRUE(node->data == data);
}

int main(int argc, char **argv)
{
  ::testing::InitGoogleTest(&argc, argv);

  return RUN_ALL_TESTS();
}