//
// Created by mwypych on 21.02.17.
//


#include <gtest/gtest.h>
#include <MemLeakTest.h>
#include <sstream>
#include <memory>
#include <SmartTree.h>

using ::std::unique_ptr;
using ::std::stringstream;
using ::std::move;
using ::datastructures::SmartTree;
using ::datastructures::CreateLeaf;
using ::datastructures::InsertLeftChild;
using ::datastructures::InsertRightChild;
using ::datastructures::PrintTreeInOrder;

class SmartTreeStep3Tests : public ::testing::Test, MemLeakTest {
 public:
  unique_ptr<SmartTree> root;
  void SetUp() override {
    root = CreateLeaf(99);
    root = InsertLeftChild(move(root), CreateLeaf(100));
    root = InsertRightChild(move(root), CreateLeaf(88));
    root->left = InsertLeftChild(move(root->left), CreateLeaf(1234));
    root->left = InsertRightChild(move(root->left), CreateLeaf(4321));
    root->right = InsertLeftChild(move(root->right), CreateLeaf(897));
    root->right = InsertRightChild(move(root->right), CreateLeaf(761));
  }
};

TEST_F(SmartTreeStep3Tests, Define_PrintTreeInOrder_Method) {
  stringstream ss;
  PrintTreeInOrder(root, &ss);
  EXPECT_NE(nullptr, root);
  EXPECT_EQ("1234, 100, 4321, 99, 897, 88, 761, ", ss.str());
}

TEST_F(SmartTreeStep3Tests, WorksProperlyWithInbalancedTree) {
  stringstream ss;
  root->left->left = InsertLeftChild(move(root->left->left), CreateLeaf(888));
  root->left->left->left = InsertLeftChild(move(root->left->left->left), CreateLeaf(901));
  PrintTreeInOrder(root, &ss);
  EXPECT_EQ("901, 888, 1234, 100, 4321, 99, 897, 88, 761, ", ss.str());
}

TEST_F(SmartTreeStep3Tests, WorksProperlyWithRightlyInbalancedTree) {
  stringstream ss;
  root->right->right = InsertRightChild(move(root->right->right), CreateLeaf(-90));
  root->right->right->right = InsertRightChild(move(root->right->right->right), CreateLeaf(-700));
  PrintTreeInOrder(root, &ss);
  EXPECT_EQ("1234, 100, 4321, 99, 897, 88, 761, -90, -700, ", ss.str());
}