//
// Created by mwypych on 21.02.17.
//

#include <gtest/gtest.h>
#include <MemLeakTest.h>
#include <SimpleForwardList.h>

class SimpleForwardListStep2Tests : public ::testing::Test, MemLeakTest {
 public:
  void SetUp() override {
    head = CreateNode(k_head_value);
  }

  void TearDown() override {
    DestroyList(head);
  }

  const int k_head_value = 89;
  ForwardList *head;
};

TEST_F(SimpleForwardListStep2Tests, Define_PushFront_Method) {
  ForwardList *old_head = head;
  ForwardList *new_node = PushFront(head, 103);
  EXPECT_NE(new_node, head);
  EXPECT_EQ(103, new_node->value);
  EXPECT_EQ(old_head, new_node->next);
  EXPECT_EQ(k_head_value, new_node->next->value);
  EXPECT_EQ(nullptr, new_node->next->next);
  head = new_node;
}

TEST_F(SimpleForwardListStep2Tests, PushingIntoNullListShouldReturnNullPtr) {
  ForwardList *new_node = PushFront(nullptr, 103);
  EXPECT_EQ(nullptr, new_node);
}

