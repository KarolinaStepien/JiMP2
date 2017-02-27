//
// Created by mwypych on 21.02.17.
//

#include <GreatestProduct.h>
#include <gtest/gtest.h>
#include <MemLeakTest.h>
#include <StringUtility.h>

using TestParam = std::pair<std::pair<std::vector<int>, int>, int>;

class GreatestProductOfStep3Tests : public ::testing::TestWithParam<TestParam>, MemLeakTest {

};

TEST_P(GreatestProductOfStep3Tests,
       GreatestProductOfBothPositiveAndNegativeNumbersArbitraryNShouldReturnExpectedResult) {
  const TestParam &p = GetParam();
  int expected = p.second;
  const std::vector<int> &numbers = p.first.first;
  int N = p.first.second;
  EXPECT_EQ(expected, GreatestProduct(numbers, N))
            << "Did call GreatestProductOf(" << utility::ToString<int>(numbers) << ", " << N << ")\n";
}

std::vector<TestParam> greatest_product_both_negative_and_positive_test_data{
    {{{-11, 8, 2, 9, 9, 8, 5, -1}, 2}, 81},
    {{{-11, 8, 2, 9, -9, 8, 5, -1}, 2}, 99},
    {{{-11, -9, -1}, 2}, 99},
    {{{-11, 8, 2, 9, -9, 8, 5, -1}, 3}, 11 * 9 * 9},
    {{{-11, -90, -4, -5, -9, -1, -3, 1}, 3}, 11 * 90},
    {{{-17, -1}, 2}, 17},
    {{{-17, 3, -1}, 2}, 17},
    {{{-17, 3, 1}, 2}, 3},
    {{{-17, 19, 1, -1}, 2}, 19},
    {{{-11, -90, -4, -5, -9, -1, -3, -1}, 3}, -3}};

INSTANTIATE_TEST_CASE_P(GreatestProductOfStep3Tests,
                        GreatestProductOfStep3Tests,
                        ::testing::ValuesIn(greatest_product_both_negative_and_positive_test_data));

