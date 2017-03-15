//
// Created by mwypych on 21.02.17.
//

#include <Array2D.h>
#include <gtest/gtest.h>
#include "MemLeakTest.h"

class Array2DStep4Tests : public ::testing::Test, MemLeakTest {

};

TEST_F(Array2DStep4Tests,
       Refactor_Array2D_FunctionWithExtractMethodAndDefine_FillArray2D_FunctionToJustFillArrayCellsWithNumbers) {
  constexpr int k_rows = 2;
  constexpr int k_cols = 3;
  int first_row[] = {0, 0, 0};
  int second_row[] = {0, 0, 0};
  int third_row[] = {0, 0, 0};
  int *to_fill[] = {first_row, second_row, third_row};

  int expected[k_rows][k_cols] =
      {{1, 2, 3},
       {4, 5, 6}};

  FillArray2D(k_rows, k_cols, to_fill);
  for (int x = 0; x < k_rows; ++x) {
    for (int y = 0; y < k_cols; ++y) {
      EXPECT_EQ(expected[x][y], to_fill[x][y]) << "element (" << x << ", " << y << ")\n";
    }
  }
}

