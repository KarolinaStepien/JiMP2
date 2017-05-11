//
// Created by mwypych on 11.05.17.
//


#include <gtest/gtest.h>
#include <vector>
#include <tuple>
#include <MemLeakTest.h>
#include <Algo.h>

using algo::Contains;
using TestParam = std::tuple<std::vector<int>, int, bool>;

class AlgoStep2 : public ::testing::TestWithParam<TestParam>, MemLeakTest {
 public:

};

TEST_P(AlgoStep2, DefineMethod_CopyInto) {
  std::vector<int> arg;
  bool expected;
  int element;
  std::tie(arg, element, expected) = GetParam();
  EXPECT_EQ(expected, Contains(arg, element));
}

std::vector<TestParam> algo2TestData {TestParam{std::vector<int>{4, 89891},2,false}, TestParam{std::vector<int>{4, 89891},4,true}};

INSTANTIATE_TEST_CASE_P(AlgoStep2Fixture,
                        AlgoStep2,
                        ::testing::ValuesIn(algo2TestData));