//
// Created by mwypych on 21.02.17.
//


#include <gtest/gtest.h>
#include <MemLeakTest.h>
#include <memory>
#include <SmartTree.h>

using ::std::unique_ptr;
using ::datastructures::SmartTree;
using ::datastructures::RestoreTree;

class SmartTreeStep5Tests : public ::testing::Test, MemLeakTest {};

TEST_F(SmartTreeStep5Tests, Define_RestoreTree_Method) {
  auto tree = RestoreTree("[99 [100 [1234 [none] [none]] [4321 [none] [none]]] "
                              "[88 [897 [none] [none]] [761 [none] [none]]]]");
  EXPECT_EQ(99, tree->value);
  EXPECT_EQ(100, tree->left->value);
  EXPECT_EQ(1234, tree->left->left->value);
  EXPECT_EQ(nullptr, tree->left->left->left);
  EXPECT_EQ(nullptr, tree->left->left->right);
  EXPECT_EQ(4321, tree->left->right->value);
  EXPECT_EQ(nullptr, tree->left->right->left);
  EXPECT_EQ(nullptr, tree->left->right->right);
  EXPECT_EQ(88, tree->right->value);
  EXPECT_EQ(897, tree->right->left->value);
  EXPECT_EQ(nullptr, tree->right->left->left);
  EXPECT_EQ(nullptr, tree->right->left->right);
  EXPECT_EQ(761, tree->right->right->value);
}

TEST_F(SmartTreeStep5Tests, RestoreEmptyTree) {
  auto tree = RestoreTree("[none]");
  EXPECT_EQ(nullptr, tree);
}

TEST_F(SmartTreeStep5Tests, RestoreTreeWithSingleNegativeValue) {
  auto tree = RestoreTree("[-13 [none] [none]]");
  EXPECT_EQ(-13, tree->value);
  EXPECT_EQ(nullptr, tree->left);
  EXPECT_EQ(nullptr, tree->right);
}

TEST_F(SmartTreeStep5Tests, RestoreTreeWithTwoNegativeValue) {
  auto tree = RestoreTree("[-189 [17 [none] [-90 [none] [none]]] [none]]");
  EXPECT_EQ(-189, tree->value);
  EXPECT_EQ(17, tree->left->value);
  EXPECT_EQ(-90, tree->left->right->value);
  EXPECT_EQ(nullptr, tree->right);
}