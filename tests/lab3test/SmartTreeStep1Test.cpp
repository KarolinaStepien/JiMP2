//
// Created by mwypych on 21.02.17.
//

#include <gtest/gtest.h>
#include <memory>
#include <MemLeakTest.h>
#include <SmartTree.h>

using ::datastructures::SmartTree;
using ::datastructures::CreateLeaf;
using ::std::unique_ptr;

class SmartTreeTests : public ::testing::Test, MemLeakTest {};

TEST_F(SmartTreeTests, Define_CreateLeaf_And_DestroyTree_MethodsTogetherWith_struct_SmartTree) {
  unique_ptr<SmartTree> leaf = CreateLeaf(27);
  EXPECT_NE(nullptr, leaf) << "After allocation of memory by CreateLeaf pointer shouldn't be null";
  EXPECT_EQ(nullptr, leaf->left) << "left subtree of the leaf should be nullptr";
  EXPECT_EQ(nullptr, leaf->right) << "right subtree of the leaf should be nullptr";
  EXPECT_EQ(27, leaf->value) << "Value stored in the node should be one provided in the method argument";
}

TEST_F(SmartTreeTests, DestructionOfNullTreeShouldBeOk) {
//  DestroyTree(nullptr);
}
