//
// Created by mwypych on 10.04.17.
//

#include <gtest/gtest.h>
#include <vector>
#include <MemLeakTest.h>
#include <ArrayFill.h>

using ::arrays::IncrementalFill;
using ::arrays::FillArray;

class ArrayFillIncrementalTests : public ::testing::Test, MemLeakTest {
};

TEST_F(ArrayFillIncrementalTests, FillsArrayByConsequentIntegersStartingFromThree) {
  std::vector<int> vs;
  IncrementalFill uniform {3};
  FillArray(35, uniform, &vs);
  for (int i = 0, expected = 3; i < 35; i++, expected++) {
    EXPECT_EQ(expected, vs.at(i));
  }
}

TEST_F(ArrayFillIncrementalTests, FillsArrayWithIntegersStartingFromMinusNineStepFive) {
  std::vector<int> vs;
  IncrementalFill uniform {-9, 5};
  FillArray(35, uniform, &vs);
  for (int i = 0, expected = -9; i < 35; i++, expected+=5) {
    EXPECT_EQ(expected, vs.at(i));
  }
}