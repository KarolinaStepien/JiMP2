//
// Created by mwypych on 16.02.17.
//
#include <gtest/gtest.h>
#include <DoubleBasePalindromes.h>
#include <vector>

using TestParam = std::pair<int, uint64_t>;

class DoubleBasePalindromeDataDrivenTests : public ::testing::TestWithParam<TestParam> {

};

TEST_P(DoubleBasePalindromeDataDrivenTests, PalindromeShouldReturnExpectedResult) {
  const TestParam &p = GetParam();
  auto expected = p.second;
  auto arg = p.first;
  EXPECT_EQ(expected, DoubleBasePalindromes(arg)) << "Did call DoubleBasePalindrome(" << arg << ")\n";
}

std::vector<TestParam> doubleBasePalindromeTestData
    {{1'000'000, 872'187}, {14'560, 18228}, {8'989'812, 25'846'868}, {-1, 0}, {300'000, 286'602}};

INSTANTIATE_TEST_CASE_P(DoubleBasePalindromeTestFixture,
                        DoubleBasePalindromeDataDrivenTests,
                        ::testing::ValuesIn(doubleBasePalindromeTestData));
