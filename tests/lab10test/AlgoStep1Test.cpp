//
// Created by mwypych on 11.05.17.
//


#include <gtest/gtest.h>
#include <array>
#include <memory>
#include <MemLeakTest.h>
#include <Algo.h>

using algo::CopyInto;
using TestParam = std::tuple<std::vector<int>, int, std::vector<int>>;

class AlgoStep1 : public ::testing::TestWithParam<TestParam>, MemLeakTest {
 public:

};

TEST_P(AlgoStep1, DefineMethod_CopyInto) {
  std::vector<int> arg;
  std::vector<int> buffer;
  std::vector<int> expected;
  int elements;
  std::tie(arg,elements,expected) = GetParam();
  CopyInto(arg, elements, &buffer);
  EXPECT_EQ(expected, buffer);
}

std::vector<TestParam> algo1TestData
    {{{4, 89891},2,{4, 89891}}, {{4, 89891},1,{4}}};

INSTANTIATE_TEST_CASE_P(AlgoStep1Fixture,
                        AlgoStep1,
                        ::testing::ValuesIn(algo1TestData));