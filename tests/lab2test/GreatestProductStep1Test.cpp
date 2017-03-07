//
// Created by mwypych on 21.02.17.
//

#include <GreatestProduct.h>
#include <gtest/gtest.h>
#include <MemLeakTest.h>
#include <StringUtility.h>

using TestParam = std::pair<std::pair<std::vector<int>, int>, int>;

class GreatestProductOfStep1Tests : public ::testing::TestWithParam<TestParam>, MemLeakTest {

};

TEST_P(GreatestProductOfStep1Tests, GreatestProductOfPositiveNumbersNfixedTo2ShouldReturnExpectedResult) {
  const TestParam &p = GetParam();
  int expected = p.second;
  const std::vector<int> &numbers = p.first.first;
  int N = p.first.second;
  EXPECT_EQ(expected, GreatestProduct(numbers, N))
            << "Did call GreatestProductOf(" << utility::ToString<int>(numbers) << ", " << N << ")\n";
}

std::vector<TestParam> greatest_product_test_positive_n_eq_2_data{
    {{{0, 1, 2, 3, 4}, 2}, 12},
    {{{6, 6, 6}, 2}, 36},
    {{{9, 8, 3, 5, 8, 1, 3, 5, 10}, 2}, 90},
    {{{17, 5, 9, 1000, 15689, 57, 89, 10, 89, 283, 197, 0, 0, 132, 45, 78, 18, 15, 89,
       19203, 98, 14, 78, 45, 35, 23, 24, 25, 46, 45, 756, 7567, 123, 890, 99, 98, 51,
       991, 9123, 8912, 89534, 8923, 1823, 7385, 91, 1748, 1, 1, 893, 2813,
       1381, 23, 563, 645, 24, 24, 51, 839, 38, 34, 35, 123, 324, 9283, 22, 19}, 2}, 1719321402},
    {{{1, 1}, 2}, 1},
    {{{0, 1}, 2}, 0},
    {{{3789, 999}, 2}, 3785211}};

INSTANTIATE_TEST_CASE_P(GreatestProductOfStep1Tests,
                        GreatestProductOfStep1Tests,
                        ::testing::ValuesIn(greatest_product_test_positive_n_eq_2_data));

