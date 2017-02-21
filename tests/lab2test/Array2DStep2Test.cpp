//
// Created by mwypych on 21.02.17.
//

#include <Array2D.h>
#include <gtest/gtest.h>
#include <MemLeakTest.h>

class Array2DStep2Tests : public ::testing::Test, MemLeakTest {

};

TEST_F(Array2DStep2Tests, Define_DeleteArray2D_Function) {
  constexpr int k_rows = 3;
  constexpr int k_cols = 1;
  int expected[k_rows][k_cols] =
      {{1},
       {2},
       {3}};
  int **output = Array2D(k_rows, k_cols);
  for (int x = 0; x < k_rows; ++x) {
    for (int y = 0; y < k_cols; ++y) {
      EXPECT_EQ(expected[x][y], output[x][y]) << "element (" << x << ", " << y << ")\n";
    }
  }
  DeleteArray2D(output, k_rows, k_cols);
}
