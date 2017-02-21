//
// Created by mwypych on 09.02.17.
//

#include <Palindrome.h>
#include <gtest/gtest.h>
#include <string>
#include <utility>
#include <vector>

using TestParam = std::pair<std::string, bool>;

class PalindromeDataDrivenTests : public ::testing::TestWithParam<TestParam> {
};

TEST_P(PalindromeDataDrivenTests, PalindromeShouldReturnExpectedResult) {
  const TestParam &p = GetParam();
  auto expected = p.second;
  auto arg = p.first;
  EXPECT_EQ(expected, is_palindrome(arg)) << "Did call is_palindrome(" << arg << ")\n";
}

std::vector<TestParam> palindromeTestData{{"", true}, {"abc", false}, {"g", true}, {"8h", false},
                                          {"palindromemordnilap", true}, {"@@@@", true}};

INSTANTIATE_TEST_CASE_P(PalindromeTestFixture,
                        PalindromeDataDrivenTests,
                        ::testing::ValuesIn(palindromeTestData));
