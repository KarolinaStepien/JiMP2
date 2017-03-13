//
// Created by mwypych on 21.02.17.
//

#include <gtest/gtest.h>
#include <memory>
#include <map>
#include <string>
#include <vector>
#include <MemLeakTest.h>
#include <CCounter.h>

using ::std::string;
using ::std::unique_ptr;
using ::std::map;
using ::std::pair;
using ::std::vector;

using ::ccounter::Counter;
using ::ccounter::Init;
using ::ccounter::Inc;
using ::ccounter::Counts;
using ::ccounter::SetCountsTo;

using TestParam = pair<vector<string>, map<string, int>>;

class CCounterTest : public ::testing::TestWithParam<TestParam>, MemLeakTest {};

TEST_P(CCounterTest, DefineMethod_Init_Encode_Decode) {
  const auto arg = GetParam();

  unique_ptr<Counter> counter = Init();
  auto strings = arg.first;
  for (auto s : strings) {
    Inc(s, &counter);
  }

  auto expected = arg.second;
  for (auto p : expected) {
    auto expected = p.second;
    auto key = p.first;
    EXPECT_EQ(expected, Counts(counter, key));
  }
}

std::vector<TestParam> cCounterTestData
    {{{"a", "b", "a", "a", "c", "f"}, {{"a", 3}, {"b", 1}, {"c", 1}, {"f", 1}}},
     {{"efg", "f", "f", "efg", "x", "x", "efg", "efg"}, {{"efg", 4}, {"f", 2}, {"x", 2}}},
     {{"a", "c", "f"}, {{"a", 1}, {"c", 1}, {"f", 1}, {"g", 0}}},
     {{}, {{"a", 0}}}};

INSTANTIATE_TEST_CASE_P(CCounterTestFixture,
                        CCounterTest,
                        ::testing::ValuesIn(cCounterTestData));
