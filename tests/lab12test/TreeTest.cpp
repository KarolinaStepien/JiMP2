//
// Created by mwypych on 25.05.17.
//

#include <vector>
#include <gtest/gtest.h>
#include <MemLeakTest.h>
#include "Tree.h"

using ::tree::Tree;

class DummyTreeDataType {
 public:
  bool operator<(const DummyTreeDataType &other) const {
    return true;
  }
};

class TreeTest : public ::testing::Test, MemLeakTest {
 public:
};

TEST_F(TreeTest, CanCreateTreeOfInts) {
  Tree<int> tree;
}

TEST_F(TreeTest, CanCreateTreeOfDoubles) {
  Tree<double> tree;
}

TEST_F(TreeTest, CanCreateTreeOfArbitraryType) {
  Tree<DummyTreeDataType> tree;
}

