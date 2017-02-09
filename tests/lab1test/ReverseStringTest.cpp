//
// Created by mwypych on 09.02.17.
//

#include <reversestring/ReverseString.h>
#include <gtest/gtest.h>
#include <boost/format.hpp>

using TestParam = std::pair<std::string, std::string>;

class DataDrivenTests : public ::testing::TestWithParam<TestParam> {

};

TEST_P(DataDrivenTests, shouldXxxx) {
  const TestParam &p = GetParam();
  auto expected = p.second;
  auto arg = p.first;
  EXPECT_EQ(expected, reverse(arg)) << boost::format("Was called reverse(%1%)") % arg;
}

std::vector<TestParam> positiveNumbers{{"", ""}, {"abc", "cba"}, {"g", "g"}, {"8h", "h8"},
                                       {"palindromemordnilap", "palindromemordnilap"}, {"@@@@", "@@@@"}};

INSTANTIATE_TEST_CASE_P(PositiveResults,
                        DataDrivenTests,
                        ::testing::ValuesIn(positiveNumbers));

