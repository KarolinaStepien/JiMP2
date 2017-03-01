//
// Created by mwypych on 21.02.17.
//

#include <gtest/gtest.h>
#include <MemLeakTest.h>
#include <SimpleForwardList.h>

class SimpleForwardListStep3Tests : public ::testing::Test, MemLeakTest {
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

TEST_F(SimpleForwardListStep3Tests, Define_Append_Method) {
  ForwardList *old_head = head;
  ForwardList *new_node = CreateNode(101);
  Append(head, new_node);
  EXPECT_EQ(old_head, head);
  EXPECT_EQ(k_head_value, head->value);
  EXPECT_EQ(new_node, head->next);
  EXPECT_EQ(101, head->next->value);
  EXPECT_EQ(nullptr, head->next->next);
}

TEST_F(SimpleForwardListStep3Tests, AppendingNullTailShouldBeAllowed) {
  Append(head, nullptr);
  EXPECT_EQ(nullptr, head->next);
}

TEST_F(SimpleForwardListStep3Tests, AppendingToNullListShouldNotCrush) {
  auto *old_head = head;
  Append(nullptr, head);
  EXPECT_EQ(old_head, head);
  EXPECT_EQ(nullptr, head->next);
  EXPECT_EQ(k_head_value, head->value);
}

TEST_F(SimpleForwardListStep3Tests, AppendingToLen3ListShouldReturnCorrectResult) {
  auto *old_head = head;
  ForwardList *first = CreateNode(1717);
  ForwardList *second = CreateNode(804);
  head->next = first;
  first->next = second;
  auto *another_tail = CreateNode(651);
  auto *another_first = PushFront(another_tail, 111);
  Append(head, another_first);
  EXPECT_EQ(old_head, head);
  EXPECT_EQ(k_head_value, head->value);
  EXPECT_EQ(first, head->next);
  EXPECT_EQ(second, head->next->next);
  EXPECT_EQ(another_first, head->next->next->next);
  EXPECT_EQ(another_tail, head->next->next->next->next);
  EXPECT_EQ(111, head->next->next->next->value);
  EXPECT_EQ(nullptr, head->next->next->next->next->next);
}


