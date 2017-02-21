//
// Created by mwypych on 21.02.17.
//

#include <Array2D.h>
#include <gtest/gtest.h>
#include "MemLeakTest.h"

class Array2DStep3Tests : public ::testing::Test, MemLeakTest {

};

TEST_F(Array2DStep3Tests,
       Refactor_Array2D_FunctionWithExtractMethodAndDefine_NewArray2D_FunctionToJustAllocateMemory) {
  int **output = NewArray2D(5, 7);
  DeleteArray2D(output, 5, 7);
}
