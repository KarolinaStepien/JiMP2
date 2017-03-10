//
// Created by mwypych on 21.02.17.
//

#include <gtest/gtest.h>
#include <MemLeakTest.h>
#include <SmartTree.h>

using ::datastructures::SmartTree;
using ::datastructures::CreateLeaf;

class SmartTreeStep2Tests : public ::testing::Test, MemLeakTest {};

TEST_F(SmartTreeStep2Tests, Define_CreateLeaf_And_DestroyTree_MethodsTogetherWith_struct_SmartTree) {
  auto leaf = CreateLeaf(33);
}

TEST_F(SmartTreeTests, DestructionOfNullTreeShouldBeOk) {
//  DestroyTree(nullptr);
}
