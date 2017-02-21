//
// Created by mwypych on 02.02.17.
//

#include <gtest/gtest.h>
#include <Factorial.h>
#include <utility>
#include <vector>

TEST(factorial_test, factorial_of_0_is_1) {
  EXPECT_EQ(1, factorial(0));
}

TEST(factorial_test, factorial_of_5_is_120) {
  EXPECT_EQ(120, factorial(5));
}


// Data drive tests:
// https://github.com/google/googletest/blob/master/googletest/docs/AdvancedGuide.md#how-to-write-value-parameterized-tests

using TestParam = std::pair<int, int>;

class FactorialDataDrivenTests : public ::testing::TestWithParam<TestParam> {

};

TEST_P(FactorialDataDrivenTests, FactorialShouldReturnExpectedResult) {
  const TestParam &p = GetParam();
  EXPECT_EQ(p.second, factorial(p.first)) << "Did call factorial (" << p.first << ")\n";
}

std::vector<TestParam> positiveNumbers{{0, 1}, {1, 1}, {3, 6}, {5, 120}, {10, 3628800}, {12, 479001600}};
std::vector<TestParam> negativeNumbers{{-1, -1}, {-2, 2}, {-3, -6}, {-10, 3628800}};
std::vector<TestParam> overflowingNumbers{{13, 0}, {17, 0}, {-100, 0}, {189201, 0}};

INSTANTIATE_TEST_CASE_P(PositiveResults,
                        FactorialDataDrivenTests,
                        ::testing::ValuesIn(positiveNumbers));

INSTANTIATE_TEST_CASE_P(NegativeResults,
                        FactorialDataDrivenTests,
                        ::testing::ValuesIn(negativeNumbers));

INSTANTIATE_TEST_CASE_P(OverflowingResults,
                        FactorialDataDrivenTests,
                        ::testing::ValuesIn(overflowingNumbers));
