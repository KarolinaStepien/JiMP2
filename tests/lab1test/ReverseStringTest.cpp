//
// Created by mwypych on 09.02.17.
//

#include <ReverseString.h>
#include <gtest/gtest.h>
#include <string>
#include <utility>
#include <vector>

using TestParam = std::pair<std::string, std::string>;

class ReverseStringDataDrivenTests : public ::testing::TestWithParam<TestParam> {

};

TEST_P(ReverseStringDataDrivenTests, ReverseStringShouldReturnExpectedResult) {
  const TestParam &p = GetParam();
  auto expected = p.second;
  auto arg = p.first;
  EXPECT_EQ(expected, reverse(arg)) << "Did call reverse(" << arg << ")\n";
}

std::vector<TestParam> reverseTestData{{"", ""}, {"abc", "cba"}, {"g", "g"}, {"8h", "h8"},
                                       {"palindromemordnilap", "palindromemordnilap"}, {"@@@@", "@@@@"}};

INSTANTIATE_TEST_CASE_P(ReverseTestFixture,
                        ReverseStringDataDrivenTests,
                        ::testing::ValuesIn(reverseTestData));

