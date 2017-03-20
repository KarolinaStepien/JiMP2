//
// Created by mwypych on 21.02.17.
//


#include <gtest/gtest.h>
#include <MemLeakTest.h>
#include <memory>
#include <SmartTree.h>

using ::std::unique_ptr;
using ::std::move;
using ::datastructures::SmartTree;
using ::datastructures::CreateLeaf;
using ::datastructures::InsertLeftChild;
using ::datastructures::InsertRightChild;
using ::datastructures::PrintTreeInOrder;
using ::datastructures::DumpTree;

class SmartTreeStep4Tests : public ::testing::Test, MemLeakTest {
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

TEST_F(SmartTreeStep4Tests, Define_DumpTree_Method) {
  auto tree = DumpTree(root);
  EXPECT_EQ("[99 [100 [1234 [none] [none]] [4321 [none] [none]]] [88 [897 [none] [none]] [761 [none] [none]]]]", tree);
}

TEST_F(SmartTreeStep4Tests, WorksProperlyWithInbalancedTree) {
  root->left->left = InsertLeftChild(move(root->left->left), CreateLeaf(888));
  root->left->left->left = InsertLeftChild(move(root->left->left->left), CreateLeaf(901));
  auto tree = DumpTree(root);
  EXPECT_EQ(
      "[99 [100 [1234 [888 [901 [none] [none]] [none]] [none]] [4321 [none] [none]]] [88 [897 [none] [none]] [761 [none] [none]]]]",
      tree);
}

TEST_F(SmartTreeStep4Tests, WorksProperlyWithRightlyInbalancedTree) {
  root->right->right = InsertRightChild(move(root->right->right), CreateLeaf(888));
  root->right->right->right = InsertRightChild(move(root->right->right->right), CreateLeaf(901));
  auto tree = DumpTree(root);
  EXPECT_EQ(
      "[99 [100 [1234 [none] [none]] [4321 [none] [none]]] [88 [897 [none] [none]] [761 [none] [888 [none] [901 [none] [none]]]]]]",
      tree);
}