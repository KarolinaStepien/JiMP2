//
// Created by mwypych on 21.02.17.
//

#include <Array2D.h>
#include <gtest/gtest.h>

class Array2DStep1Tests : public ::testing::Test {};

TEST_F(Array2DStep1Tests, Define_Array2D_FunctionOf_N_Rows_And_N_Columns_FilledUpWithNumbersFrom1ToNumberOfElements) {
  constexpr int k_rows = 5;
  constexpr int k_cols = 7;
  int expected[k_rows][k_cols] =
      {{1, 2, 3, 4, 5, 6, 7},
       {8, 9, 10, 11, 12, 13, 14},
       {15, 16, 17, 18, 19, 20, 21},
       {22, 23, 24, 25, 26, 27, 28},
       {29, 30, 31, 32, 33, 34, 35}};
  int **output = Array2D(k_rows, k_cols);
  for (int x = 0; x < k_rows; ++x) {
    for (int y = 0; y < k_cols; ++y) {
      EXPECT_EQ(expected[x][y], output[x][y]) << "element (" << x << ", " << y << ")\n";
    }
  }
  // commented see different steps
  // DeleteArray2D(output, k_rows, k_cols);
}

TEST_F(Array2DStep1Tests, InvalidArgumentsShouldResultWithNullptr) {
  EXPECT_EQ(nullptr, Array2D(0, 0));
  EXPECT_EQ(nullptr, Array2D(10, 0));
  EXPECT_EQ(nullptr, Array2D(0, 7));
  EXPECT_EQ(nullptr, Array2D(-9, 18));
  EXPECT_EQ(nullptr, Array2D(-1, -1));
}
