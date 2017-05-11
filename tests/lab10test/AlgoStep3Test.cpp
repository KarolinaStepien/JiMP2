//
// Created by mwypych on 11.05.17.
//


#include <gtest/gtest.h>
#include <array>
#include <memory>
#include <MemLeakTest.h>
#include <Algo.h>

using algo::InitializeWith;
using algo::InitializedVectorOfLength;
using algo::MapToString;


class AlgoStep3 : public ::testing::Test, MemLeakTest {
 public:
};

TEST_F(AlgoStep3, DefineMethod_InitializeWith) {
  std::vector<int> arg {0,0,0,0};
  std::vector<int> expected {77,77,77,77};
  int value = 77;
  InitializeWith(value, &arg);
  EXPECT_EQ(expected, arg);
}

TEST_F(AlgoStep3, DefineMethod_InitializedVectorOfLength) {
  std::vector<int> expected {77,77};
  EXPECT_EQ(expected, InitializedVectorOfLength(2,77));
}

TEST_F(AlgoStep3, DefineMethod_MapToString) {
  std::vector<std::string> expected {"77.980000","-13.912000"};
  EXPECT_EQ(expected, MapToString({77.98,-13.912}));
}



