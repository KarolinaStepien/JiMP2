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
using ::tree::InOrder;
using ::tree::InOrderTreeIterator;
using ::tree::InOrderTreeView;

class TreeInorderTest : public ::testing::Test, MemLeakTest {
 public:
  TreeInorderTest() : ::testing::Test(), MemLeakTest(), simple_tree(0) {
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

TEST_F(TreeInorderTest,CanCreateInOrderIterator) {
  auto root = simple_tree.Root();
  InOrderTreeIterator<int> iterator = InOrderTreeIterator<int>(root);
}

TEST_F(TreeInorderTest,InOrderIteratorIsMovable) {
  auto root = simple_tree.Root();
  InOrderTreeIterator<int> iterator = InOrderTreeIterator<int>(root);
  ++iterator;
  ++iterator;
}

TEST_F(TreeInorderTest,InOrderIteratorIsDereferencable) {
  auto root = simple_tree.Root();
  InOrderTreeIterator<int> iterator = InOrderTreeIterator<int>(root);
  int value1 = *iterator;
  EXPECT_EQ(-90, value1);
  ++iterator;
  int value2 = *iterator;
  //no tests EXPECT_EQ(0, value1);
}

TEST_F(TreeInorderTest,InOrderIteratorComparableByNotEqualOperator) {
  auto root = simple_tree.Root();
  InOrderTreeIterator<int> iterator1 = InOrderTreeIterator<int>(root);
  InOrderTreeIterator<int> iterator2 = InOrderTreeIterator<int>(root);
  bool are_equal = iterator1 != iterator2;
  EXPECT_FALSE(are_equal);
  ++iterator1;
  EXPECT_NE(iterator1, iterator2);
}

TEST_F(TreeInorderTest,InOrderIteratorJumpsOverTreeInorder) {
  auto root = simple_tree.Root();
  InOrderTreeIterator<int> iterator = InOrderTreeIterator<int>(root);
  EXPECT_EQ(-90, *iterator);
  ++iterator;
  EXPECT_EQ(-20, *iterator);
  ++iterator;
  EXPECT_EQ(-10, *iterator);
  ++iterator;
  EXPECT_EQ(0, *iterator);
  ++iterator;
  EXPECT_EQ(80, *iterator);
  ++iterator;
  EXPECT_EQ(10078, *iterator);
  ++iterator;
  EXPECT_EQ(98341, *iterator);
  ++iterator;
  EXPECT_EQ(198341, *iterator);
}

TEST_F(TreeInorderTest, CanCreateInOrderTreeView) {
  InOrderTreeView<int> inorder_view = InOrderTreeView<int>(&simple_tree);
}

TEST_F(TreeInorderTest, InOrderTreeViewHasBeginAndEndMethods) {
  InOrderTreeView<int> inorder_view = InOrderTreeView<int>(&simple_tree);
  InOrderTreeIterator<int> b = inorder_view.begin();
  InOrderTreeIterator<int> e = inorder_view.end();
  EXPECT_NE(b,e);
}

TEST_F(TreeInorderTest, ThereIsGlobalInOrderMethodThatCreatesInOrderTreeView) {
  InOrderTreeView<int> inorder_view = InOrder(&simple_tree);
  InOrderTreeIterator<int> b = inorder_view.begin();
  InOrderTreeIterator<int> e = inorder_view.end();
  EXPECT_NE(b,e);
}

TEST_F(TreeInorderTest, InOrderMethodMaybeUsedInContextOfFor) {
  for (const int &value_in_tree : InOrder(&simple_tree)) {
    //see test below
  }
}

TEST_F(TreeInorderTest, InOrderMethodProvidesProperOrderOfValues) {
  vector<int> expected_values_inorder {-90, -20, -10, 0, 80, 10078, 98341, 198341};
  auto expected_it = expected_values_inorder.begin();
  for (const int &value_in_tree : InOrder(&simple_tree)) {
    EXPECT_EQ(*expected_it, value_in_tree);
    ++expected_it;
  }
}