//
// Created by mwypych on 31.05.17.
//
#include <string>
#include <vector>
#include <gtest/gtest.h>
#include <MemLeakTest.h>
#include "TreeIterators.h"

using ::std::vector;

using ::tree::Tree;
using ::tree::PreOrder;
using ::tree::PreOrderTreeIterator;
using ::tree::PreOrderTreeView;

class TreePreorderTest : public ::testing::Test, MemLeakTest {
 public:
  TreePreorderTest() : ::testing::Test(), MemLeakTest(), simple_tree(0) {
    simple_tree.Insert(-20);
    simple_tree.Insert(80);
    simple_tree.Insert(10078);
    simple_tree.Insert(98341);
    simple_tree.Insert(198341);
    simple_tree.Insert(-90);
    simple_tree.Insert(-10);
  }
  Tree<int> simple_tree;
};

TEST_F(TreePreorderTest,CanCreatePreOrderIterator) {
  auto root = simple_tree.Root();
  PreOrderTreeIterator<int> iterator = PreOrderTreeIterator<int>(root);
}

TEST_F(TreePreorderTest,PreOrderIteratorIsMovable) {
  auto root = simple_tree.Root();
  PreOrderTreeIterator<int> iterator = PreOrderTreeIterator<int>(root);
  ++iterator;
  ++iterator;
}

TEST_F(TreePreorderTest,PreOrderIteratorIsDereferencable) {
  auto root = simple_tree.Root();
  PreOrderTreeIterator<int> iterator = PreOrderTreeIterator<int>(root);
  int value1 = *iterator;
  EXPECT_EQ(0, value1);
  ++iterator;
  int value2 = *iterator;
  //no tests EXPECT_EQ(0, value1);
}

TEST_F(TreePreorderTest,PreOrderIteratorComparableByNotEqualOperator) {
  auto root = simple_tree.Root();
  PreOrderTreeIterator<int> iterator1 = PreOrderTreeIterator<int>(root);
  PreOrderTreeIterator<int> iterator2 = PreOrderTreeIterator<int>(root);
  bool are_equal = iterator1 != iterator2;
  EXPECT_FALSE(are_equal);
  ++iterator1;
  EXPECT_NE(iterator1, iterator2);
}

TEST_F(TreePreorderTest,PreOrderIteratorJumpsOverTreePreorder) {
  auto root = simple_tree.Root();
  PreOrderTreeIterator<int> iterator = PreOrderTreeIterator<int>(root);
  EXPECT_EQ(*iterator, 0);
  ++iterator;
  EXPECT_EQ(*iterator, -20 );
  ++iterator;
  EXPECT_EQ(*iterator, -10);
  ++iterator;
  EXPECT_EQ(*iterator, -90);
  ++iterator;
  EXPECT_EQ(*iterator, 80);
  ++iterator;
  EXPECT_EQ(*iterator, 10078);
  ++iterator;
  EXPECT_EQ(*iterator, 98341);
  ++iterator;
  EXPECT_EQ(*iterator, 198341);
}

TEST_F(TreePreorderTest, CanCreatePreOrderTreeView) {
  PreOrderTreeView<int> preorder_view = PreOrderTreeView<int>(&simple_tree);
}

TEST_F(TreePreorderTest, PreOrderTreeViewHasBeginAndEndMethods) {
  PreOrderTreeView<int> preorder_view = PreOrderTreeView<int>(&simple_tree);
  PreOrderTreeIterator<int> b = preorder_view.begin();
  PreOrderTreeIterator<int> e = preorder_view.end();
  EXPECT_NE(b,e);
}

TEST_F(TreePreorderTest, ThereIsGlobalPreOrderMethodThatCreatesPreOrderTreeView) {
  PreOrderTreeView<int> preorder_view = PreOrder(&simple_tree);
  PreOrderTreeIterator<int> b = preorder_view.begin();
  PreOrderTreeIterator<int> e = preorder_view.end();
  EXPECT_NE(b,e);
}

TEST_F(TreePreorderTest, PreOrderMethodMaybeUsedInContextOfFor) {
  for (const int &value_in_tree : PreOrder(&simple_tree)) {
    //see test below
  }
}

TEST_F(TreePreorderTest, PreOrderMethodProvidesProperOrderOfValues) {
  vector<int> expected_values_preorder {0, -20, -90, -10, 80, 10078, 98341, 198341};
  auto expected_it = expected_values_preorder.begin();
  for (const int &value_in_tree : PreOrder(&simple_tree)) {
    EXPECT_EQ(*expected_it, value_in_tree);
    ++expected_it;
  }
}
