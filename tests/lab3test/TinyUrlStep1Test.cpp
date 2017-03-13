//
// Created by mwypych on 21.02.17.
//

#include <gtest/gtest.h>
#include <array>
#include <memory>
#include <MemLeakTest.h>
#include <TinyUrl.h>

using TestParam = std::pair<std::string, std::string>;

class TinyUrlStep1 : public ::testing::TestWithParam<TestParam>, MemLeakTest {
 public:
  void FillArray(const std::string &prototype, std::array<char, 6> *arg) {
    for (int i = 0; i < 6; ++i) {
      (*arg)[i] = prototype[i];
    }
  }
};

TEST_P(TinyUrlStep1, DefineMethod_NextHash) {
  std::array<char, 6> arg;
  std::array<char, 6> expected;
  auto param = GetParam();
  FillArray(param.first, &arg);
  FillArray(param.second, &expected);
  ::tinyurl::NextHash(&arg);
  EXPECT_EQ(expected, arg);
}

std::vector<TestParam> tinyUrlTestData
    {{"000000", "000001"}, {"XYZazz", "XYZb00"}, {"099999", "09999A"}, {"0zzzzz", "100000"}, {"0ZZZZZ", "0ZZZZa"},
     {"1zzzzz", "200000"}, {"9zzzzz", "A00000"}, {"Azzzzz", "B00000"}, {"Zzzzzz", "a00000"}, {"abcdef", "abcdeg"}};

INSTANTIATE_TEST_CASE_P(TinyUrlStep1Fixture,
                        TinyUrlStep1,
                        ::testing::ValuesIn(tinyUrlTestData));