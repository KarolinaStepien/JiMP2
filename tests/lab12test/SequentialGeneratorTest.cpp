//
// Created by mwypych on 29.05.17.
//
#include <string>
#include <gtest/gtest.h>
#include <MemLeakTest.h>
#include "SequentialGenerator.h"

class SequentialIdGeneratorTest : public ::testing::Test, MemLeakTest {
 public:
};

class TestId {
 public:
  TestId(int id) : id_{id} {}

  operator int() {
    return id_;
  }
 private:
  int id_;
};

class AnotherTestId {
 public:
  AnotherTestId(int id) : id_{id} {}

  operator int() {
    return id_;
  }
 private:
  int id_;
};

class BaseValue {
 public:
  BaseValue(int initial_value=0) : value_{initial_value} {}
  BaseValue operator++() {
    ++value_;
  }
  operator int() {
    return value_;
  }
 private:
  int value_;
};

TEST_F(SequentialIdGeneratorTest, CanCreateSequentialIdGeneratorGenertingTestIdsUsingInternallyInt) {
  SequentialIdGenerator<TestId, int> seq;
  TestId id0 = seq.NextValue();
  EXPECT_EQ(0, static_cast<int>(id0));
  TestId id1 = seq.NextValue();
  EXPECT_EQ(1, static_cast<int>(id1));
  TestId id2 = seq.NextValue();
  EXPECT_EQ(2, static_cast<int>(id2));
  TestId id3 = seq.NextValue();
  EXPECT_EQ(3, static_cast<int>(id3));
}

TEST_F(SequentialIdGeneratorTest, CanCreateSequentialIdGeneratorGenertingTestIdsUsingInternallyBaseValue) {
  SequentialIdGenerator<TestId, BaseValue> seq;
  TestId id0 = seq.NextValue();
  EXPECT_EQ(0, static_cast<int>(id0));
  TestId id1 = seq.NextValue();
  EXPECT_EQ(1, static_cast<int>(id1));
  TestId id2 = seq.NextValue();
  EXPECT_EQ(2, static_cast<int>(id2));
  TestId id3 = seq.NextValue();
  EXPECT_EQ(3, static_cast<int>(id3));
}

TEST_F(SequentialIdGeneratorTest, CanCreateSequentialIdGeneratorGenertingTestIdsUsingInternallyIntStartingFrom17) {
  SequentialIdGenerator<TestId, int> seq (17);
  TestId id0 = seq.NextValue();
  EXPECT_EQ(17, static_cast<int>(id0));
  TestId id1 = seq.NextValue();
  EXPECT_EQ(18, static_cast<int>(id1));
  TestId id2 = seq.NextValue();
  EXPECT_EQ(19, static_cast<int>(id2));
  TestId id3 = seq.NextValue();
  EXPECT_EQ(20, static_cast<int>(id3));
}

TEST_F(SequentialIdGeneratorTest, CanCreateSequentialIdGeneratorGenertingTestIdsUsingInternallyBaseValueStartingFromBaseValue98) {
  SequentialIdGenerator<TestId, BaseValue> seq (BaseValue {98});
  TestId id0 = seq.NextValue();
  EXPECT_EQ(98, static_cast<int>(id0));
  TestId id1 = seq.NextValue();
  EXPECT_EQ(99, static_cast<int>(id1));
  TestId id2 = seq.NextValue();
  EXPECT_EQ(100, static_cast<int>(id2));
  TestId id3 = seq.NextValue();
  EXPECT_EQ(101, static_cast<int>(id3));
}

TEST_F(SequentialIdGeneratorTest, CanCreateSequentialIdGeneratorGenertingAnotherTestIdsUsingInternallyBaseValueStartingFromBaseValue98) {
  SequentialIdGenerator<AnotherTestId, BaseValue> seq (BaseValue {98});
  AnotherTestId id0 = seq.NextValue();
  EXPECT_EQ(98, static_cast<int>(id0));
  AnotherTestId id1 = seq.NextValue();
  EXPECT_EQ(99, static_cast<int>(id1));
  AnotherTestId id2 = seq.NextValue();
  EXPECT_EQ(100, static_cast<int>(id2));
  AnotherTestId id3 = seq.NextValue();
  EXPECT_EQ(101, static_cast<int>(id3));
}
