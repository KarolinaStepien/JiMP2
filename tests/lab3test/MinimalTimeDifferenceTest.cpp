//
// Created by mwypych on 21.02.17.
//

#include <gtest/gtest.h>
#include <memory>
#include <MemLeakTest.h>
#include <MinimalTimeDifference.h>

using ::std::string;
using ::std::unique_ptr;
using ::std::map;
using ::std::pair;
using ::std::vector;

using minimaltimedifference::ToMinutes;
using minimaltimedifference::MinimalTimeDifference;


using TestParam = pair<vector<string>, int>;

class MinimalTimeDifferenceTest : public ::testing::TestWithParam<TestParam>, MemLeakTest {};

TEST_P(MinimalTimeDifferenceTest, DefineMethod_Init_Encode_Decode) {
  const auto arg = GetParam();
  const auto times = arg.first;
  const auto expected = arg.second;
  EXPECT_EQ(expected, MinimalTimeDifference(times));
}

std::vector<TestParam> timesTestData
    {{{"23:59", "00:00"}, 1}, {{"17:33", "18:00"}, 27}, {{"01:24", "10:22"}, 538},
     {{"01:24", "10:22", "7:33", "4:22", "9:13", "17:23", "18:55", "17:34"}, 11},
     {{"1:00", "23:59", "17:56", "14:13", "15:40"}, 61}};

INSTANTIATE_TEST_CASE_P(MinimalTimeDifferenceTestFixture,
                        MinimalTimeDifferenceTest,
                        ::testing::ValuesIn(timesTestData));
