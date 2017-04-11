//
// Created by mwypych on 10.04.17.
//

#include <gtest/gtest.h>
#include <vector>
#include <MemLeakTest.h>
#include <ArrayFill.h>

using ::arrays::UniformFill;
using ::arrays::FillArray;

class ArrayFillUniformTests : public ::testing::Test, MemLeakTest {
};

TEST_F(ArrayFillUniformTests, FillsArrayUniformly) {
  std::vector<int> vs;
  UniformFill uniform {67};
  FillArray(35, uniform, &vs);
  for (int i = 0; i < 35; i++) {
    EXPECT_EQ(67, vs.at(i));
  }
}

TEST_F(ArrayFillUniformTests, FillsArrayWithZerosByDefault) {
  std::vector<int> vs;
  UniformFill uniform {};
  FillArray(341, uniform, &vs);
  for (int i = 0; i < 341; i++) {
    EXPECT_EQ(0, vs.at(i));
  }
}

TEST_F(ArrayFillUniformTests, FillArrayErasesPreviousValues) {
  std::vector<int> vs {56, 14, 78, 5, 14, 98};
  UniformFill uniform {333};
  FillArray(2, uniform, &vs);
  EXPECT_EQ(2, vs.size());
  for (int i = 0; i < 2; i++) {
    EXPECT_EQ(333, vs.at(i));
  }
}