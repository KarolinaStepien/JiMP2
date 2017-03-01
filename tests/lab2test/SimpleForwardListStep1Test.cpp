//
// Created by mwypych on 21.02.17.
//

#include <gtest/gtest.h>
#include <MemLeakTest.h>
#include <SimpleForwardList.h>

class SimpleForwardListStep1Tests : public ::testing::Test, MemLeakTest {};

TEST_F(SimpleForwardListStep1Tests, Define_CreateNode_And_DestroyList_MethodsTogetherWith_struct_ForwardList) {
  ForwardList *head = CreateNode(27);
  EXPECT_NE(nullptr, head) << "After allocation of memory by CreateNode pointer shouldn't be null";
  EXPECT_EQ(nullptr, head->next) << "Tail of the list should be nullptr";
  EXPECT_EQ(27, head->value) << "Value stored in the node should be one provided in the method argument";
  DestroyList(head);
}

TEST_F(SimpleForwardListStep1Tests, DestructionOfNullListShouldBeOk) {
  DestroyList(nullptr);
}
