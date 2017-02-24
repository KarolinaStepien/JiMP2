//
// Created by mwypych on 21.02.17.
//

#include <GreatestProduct.h>
#include <gtest/gtest.h>
#include <MemLeakTest.h>

using TestParam = std::pair<std::pair<std::vector<int>,int>, int>;

class GreatestProductOfStep1Tests : public ::testing::TestWithParam<TestParam>, MemLeakTest {

};

TEST_P(GreatestProductOfStep1Tests, PolybiusCryptShouldReturnExpectedResult) {
  const TestParam &p = GetParam();
  int expected = p.second;
  const std::vector<int> &numbers = p.first.first;
  int N = p.first.second;
  EXPECT_EQ(encrypted, GreatestProductOf(numbers,N)) << "Did call GreatestProductOf(" << ToString(numbers) << ", " << N << ")\n";
}

std::vector<TestParam> greatest_product_test_data{
    {{{0,1,2,3,4},2}, 12}};

INSTANTIATE_TEST_CASE_P(GreatestProductOfStep1Tests,
                        GreatestProductOfStep1Tests,
                        ::testing::ValuesIn(greatest_product_test_data));

