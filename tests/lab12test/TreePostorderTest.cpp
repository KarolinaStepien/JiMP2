//
// Created by mwypych on 31.05.17.
//
#include <string>
#include <vector>
#include <gtest/gtest.h>
#include <MemLeakTest.h>
#include "TreeIterators.h"

using ::std::vector;
using ::std::string;

using ::tree::Tree;
using ::tree::PostOrder;
using ::tree::PostOrderTreeIterator;
using ::tree::PostOrderTreeView;

class TreePostorderTest : public ::testing::Test, MemLeakTest {
 public:
  TreePostorderTest() : ::testing::Test(), MemLeakTest(), simple_tree(0), test_tree("Opochtli") {
    simple_tree.Insert(-20);
    simple_tree.Insert(80);
    simple_tree.Insert(10078);
    simple_tree.Insert(98341);
    simple_tree.Insert(198341);
    simple_tree.Insert(-90);
    simple_tree.Insert(-10);

    test_tree.Insert("Quetzalcoatl");
    test_tree.Insert("Tezcatlipoca");
    test_tree.Insert("Tlaloc");
    test_tree.Insert("Xantico");
    test_tree.Insert("Meztli");
    test_tree.Insert("Centeotl");
    test_tree.Insert("Xolotl");
    test_tree.Insert("Citlalicue");
    test_tree.Insert("Toci");
    test_tree.Insert("Xiuhtecuhtli");
  }
  Tree<int> simple_tree;
  Tree<string> test_tree;
};

TEST_F(TreePostorderTest,CanCreatePostOrderIterator) {
  auto root = simple_tree.Root();
  PostOrderTreeIterator<int> iterator = PostOrderTreeIterator<int>(root);
}

TEST_F(TreePostorderTest,PostOrderIteratorIsMovable) {
  auto root = simple_tree.Root();
  PostOrderTreeIterator<int> iterator = PostOrderTreeIterator<int>(root);
  ++iterator;
  ++iterator;
}

TEST_F(TreePostorderTest,PostOrderIteratorIsDereferencable) {
  auto root = simple_tree.Root();
  PostOrderTreeIterator<int> iterator = PostOrderTreeIterator<int>(root);
  int value1 = *iterator;
  EXPECT_EQ(-90, value1);
  ++iterator;
  int value2 = *iterator;
  //no tests EXPECT_EQ(0, value1);
}

TEST_F(TreePostorderTest,PostOrderIteratorComparableByNotEqualOperator) {
  auto root = simple_tree.Root();
  PostOrderTreeIterator<int> iterator1 = PostOrderTreeIterator<int>(root);
  PostOrderTreeIterator<int> iterator2 = PostOrderTreeIterator<int>(root);
  bool are_equal = iterator1 != iterator2;
  EXPECT_FALSE(are_equal);
  ++iterator1;
  EXPECT_NE(iterator1, iterator2);
}

TEST_F(TreePostorderTest,PostOrderIteratorJumpsOverTreePostorder) {
  auto root = simple_tree.Root();
  PostOrderTreeIterator<int> iterator = PostOrderTreeIterator<int>(root);
  EXPECT_EQ(-90, *iterator);
  ++iterator;
  EXPECT_EQ(-10, *iterator);
  ++iterator;
  EXPECT_EQ(-20, *iterator);
  ++iterator;
  EXPECT_EQ(198341, *iterator);
  ++iterator;
  EXPECT_EQ(98341, *iterator);
  ++iterator;
  EXPECT_EQ(10078, *iterator);
  ++iterator;
  EXPECT_EQ(80, *iterator);
  ++iterator;
  EXPECT_EQ(0, *iterator);
}

TEST_F(TreePostorderTest, CanCreatePostOrderTreeView) {
  PostOrderTreeView<int> postorder_view = PostOrderTreeView<int>(&simple_tree);
}

TEST_F(TreePostorderTest, PostOrderTreeViewHasBeginAndEndMethods) {
  PostOrderTreeView<int> postorder_view = PostOrderTreeView<int>(&simple_tree);
  PostOrderTreeIterator<int> b = postorder_view.begin();
  PostOrderTreeIterator<int> e = postorder_view.end();
  EXPECT_NE(b,e);
}

TEST_F(TreePostorderTest, ThereIsGlobalPostOrderMethodThatCreatesPostOrderTreeView) {
  PostOrderTreeView<int> postorder_view = PostOrder(&simple_tree);
  PostOrderTreeIterator<int> b = postorder_view.begin();
  PostOrderTreeIterator<int> e = postorder_view.end();
  EXPECT_NE(b,e);
}

TEST_F(TreePostorderTest, PostOrderMethodMaybeUsedInContextOfFor) {
  for (const int &value_in_tree : PostOrder(&simple_tree)) {
    //see test below
  }
}

TEST_F(TreePostorderTest, PostOrderMethodProvidesProperOrderOfValues) {
  vector<int> expected_values_postorder {-90, -10, -20, 198341, 98341, 10078, 80, 0};
  auto expected_it = expected_values_postorder.begin();
  for (const int &value_in_tree : PostOrder(&simple_tree)) {
    EXPECT_EQ(*expected_it, value_in_tree);
    ++expected_it;
  }
}

TEST_F(TreePostorderTest, PostOrderMethodProvidesProperOrderOfAtecPantheon) {
  vector<string> expected_values_postorder {"Citlalicue", "Centeotl", "Meztli", "Toci", "Xiuhtecuhtli", "Xolotl", "Xantico", "Tlaloc", "Tezcatlipoca", "Quetzalcoatl", "Opochtli"};
  auto expected_it = expected_values_postorder.begin();
  for (const string &value_in_tree : PostOrder(&test_tree)) {
    EXPECT_EQ(*expected_it, value_in_tree);
    ++expected_it;
  }
}
