//
// Created by mwypych on 09.02.17.
//

#include <palindrome/Palindrome.h>
#include <gtest/gtest.h>
#include <boost/format.hpp>

using TestParam = std::pair<std::string, bool>;

class DataDrivenTests : public ::testing::TestWithParam<TestParam> {

};

TEST_P(DataDrivenTests, shouldXxxx) {
  const TestParam &p = GetParam();
  auto expected = p.second;
  auto arg = p.first;
  EXPECT_EQ(expected, is_palindrome(arg)) << boost::format("Was called is_palindrome(%1%)") % arg;
}

std::vector<TestParam> data{{"", true}, {"abc", false}, {"g", true}, {"8h", false},
                            {"palindromemordnilap", true}, {"@@@@", true}};

INSTANTIATE_TEST_CASE_P(PositiveResults,
                        DataDrivenTests,
                        ::testing::ValuesIn(data));