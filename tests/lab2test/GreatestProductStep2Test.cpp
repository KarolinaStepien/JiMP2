//
// Created by mwypych on 21.02.17.
//

#include <GreatestProduct.h>
#include <gtest/gtest.h>
#include <MemLeakTest.h>
#include <StringUtility.h>

using TestParam = std::pair<std::pair<std::vector<int>, int>, int>;

class GreatestProductOfStep2Tests : public ::testing::TestWithParam<TestParam>, MemLeakTest {

};

TEST_P(GreatestProductOfStep2Tests, GreatestProductOfPositiveNumbersArbitraryNShouldReturnExpectedResult) {
  const TestParam &p = GetParam();
  int expected = p.second;
  const std::vector<int> &numbers = p.first.first;
  int N = p.first.second;
  EXPECT_EQ(expected, GreatestProduct(numbers, N))
            << "Did call GreatestProductOf(" << utility::ToString<int>(numbers) << ", " << N << ")\n";
}

std::vector<TestParam> greatest_product_arbitrary_n_test_data{
    {{{0, 1, 2, 3, 4}, 3}, 24},
    {{{0, 1, 2, 3, 4}, 4}, 24},
    {{{9, 8, 3, 5, 8, 1, 3, 5, 10}, 2}, 90},
    {{{10, 7, 7, 5, 8, 8}, 3}, 640},
    {{{-11, 8, 2, 9, 9, 8, 5, -1}, 2}, 81},
    {{{-11, 8, 2, 9, -9, 8, 5, -1}, 2}, 99},
    {{{-11, -9, -1}, 2}, 99},
    {{{-11, 8, 2, 9, -9, 8, 5, -1}, 3}, 11 * 9 * 9},
    {{{-11, -90, -4, -5, -9, -1, -3, 1}, 3}, 11 * 90},
    {{{-11, -90, -4, -5, -9, -1, -3, -1}, 3}, -3}};

INSTANTIATE_TEST_CASE_P(GreatestProductOfStep2Tests,
                        GreatestProductOfStep2Tests,
                        ::testing::ValuesIn(greatest_product_arbitrary_n_test_data));

