//
// Created by mwypych on 10.04.17.
//

#include <gtest/gtest.h>
#include <vector>
#include <MemLeakTest.h>
#include <ArrayFill.h>

using ::arrays::SquaredFill;
using ::arrays::FillArray;

class ArrayFillSquaredTests : public ::testing::Test, MemLeakTest {

};

TEST_F(ArrayFillSquaredTests, FillsArrayWithSquaresOfIndices) {
  std::vector<int> vs;
  SquaredFill filler {};
  FillArray(35, filler, &vs);
  for (int i = 0; i < 35; i++) {
    EXPECT_EQ(i*i, vs.at(i));
  }
}

TEST_F(ArrayFillSquaredTests, FillsArrayWithSquaresMutipliedByConstant) {
  std::vector<int> vs;
  SquaredFill filler {4};
  FillArray(14, filler, &vs);
  for (int i = 0; i < 14; i++) {
    EXPECT_EQ(4*i*i, vs.at(i));
  }
}

TEST_F(ArrayFillSquaredTests, FillsArrayWithSquaresMultipliedByConstantAndAddedOffset) {
  std::vector<int> vs;
  SquaredFill filler {1,4};
  FillArray(100, filler, &vs);
  for (int i = 0; i < 100; i++) {
    EXPECT_EQ(i*i+4, vs.at(i));
  }
}