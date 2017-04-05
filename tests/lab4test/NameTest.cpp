//
// Created by mwypych on 21.03.17.
//

#include <gtest/gtest.h>
#include <tuple>
#include <memory>
#include <MemLeakTest.h>
#include <StringUtility.h>
#include <Name.h>

using ::modelnames::Name;
using ::std::make_unique;
using ::utility::FromString;
using ::std::tuple;
using ::std::pair;

using ::std::tie;

using TestArgument = std::string;
using TestExpected = std::map<std::string, std::string>;
using TestParam = std::pair<TestArgument, TestExpected>;

class NameTests : public ::testing::TestWithParam<TestParam>, MemLeakTest {
};

TEST_P(NameTests, ProperSquares) {
  auto param = GetParam();
  Point p1, p2, p3, p4;
  tie(p1, p2, p3, p4) = param.first;
  double expected_circumference, expected_area;
  tie(expected_circumference, expected_area) = param.second;
  auto square = make_unique<Square>(p1, p2, p3, p4);

  EXPECT_NEAR(expected_circumference, square->Circumference(), 1e-15d);
  EXPECT_NEAR(expected_area, square->Area(), 1e-15d);
}

std::vector<TestParam> nameTestData{
    {TestArgument{Point {0, 1}, Point {0, 0}, Point {1, 1}, Point {1, 0}}, {4.0, 1.0}},
    {TestArgument{Point {0, 5}, Point {0, 0}, Point {5, 5}, Point {5, 0}}, {20.0, 25.0}},
    {TestArgument{Point {-1, 0}, Point {0, -1}, Point {0, 1}, Point {1, 0}}, {4.0 * sqrt(2.0), 2.0}},
    {TestArgument{Point {0, 1}, Point {0, 0}, Point {1, 1}, Point {3, 0}}, {0.0, 0.0}},
};

INSTANTIATE_TEST_CASE_P(NameTestsFixture,
                        NameTests,
                        ::testing::ValuesIn(nameTestData));