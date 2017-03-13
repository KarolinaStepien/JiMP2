//
// Created by mwypych on 21.02.17.
//

#include <gtest/gtest.h>
#include <MemLeakTest.h>
#include <SmartTree.h>

using ::datastructures::SmartTree;
using ::datastructures::CreateLeaf;
using ::datastructures::InsertLeftChild;
using ::datastructures::InsertRightChild;

class SmartTreeStep2Tests : public ::testing::Test, MemLeakTest {
};

TEST_F(SmartTreeStep2Tests, Define_InsertLeftChild_Method) {
  auto root = CreateLeaf(33);
  auto child = CreateLeaf(55);
  auto new_root = InsertLeftChild(std::move(root), std::move(child));
  EXPECT_EQ(nullptr, root);
  EXPECT_EQ(nullptr, child);
  EXPECT_NE(nullptr, new_root);
  EXPECT_EQ(33, new_root->value);
  EXPECT_EQ(55, new_root->left->value);
  EXPECT_EQ(nullptr, new_root->right);
  EXPECT_EQ(nullptr, new_root->left->left);
  EXPECT_EQ(nullptr, new_root->left->right);
}

TEST_F(SmartTreeStep2Tests, Define_InsertRightChild_Method) {
  auto root = CreateLeaf(100);
  auto child = CreateLeaf(77);
  auto new_root = InsertRightChild(std::move(root), std::move(child));
  EXPECT_EQ(nullptr, root);
  EXPECT_EQ(nullptr, child);
  EXPECT_NE(nullptr, new_root);
  EXPECT_EQ(100, new_root->value);
  EXPECT_EQ(77, new_root->right->value);
  EXPECT_EQ(nullptr, new_root->left);
  EXPECT_EQ(nullptr, new_root->right->left);
  EXPECT_EQ(nullptr, new_root->right->right);
}

TEST_F(SmartTreeStep2Tests, Depth2LongTree) {
  auto root = CreateLeaf(99);
  root = InsertLeftChild(std::move(root), CreateLeaf(100));
  root = InsertRightChild(std::move(root), CreateLeaf(88));
  root->left = InsertLeftChild(std::move(root->left), CreateLeaf(1234));
  root->left = InsertRightChild(std::move(root->left), CreateLeaf(4321));
  root->right = InsertLeftChild(std::move(root->right), CreateLeaf(897));
  root->right = InsertRightChild(std::move(root->right), CreateLeaf(761));
  EXPECT_EQ(99, root->value);
  EXPECT_EQ(100, root->left->value);
  EXPECT_EQ(88, root->right->value);
  EXPECT_EQ(1234, root->left->left->value);
  EXPECT_EQ(4321, root->left->right->value);
  EXPECT_EQ(897, root->right->left->value);
  EXPECT_EQ(761, root->right->right->value);
}