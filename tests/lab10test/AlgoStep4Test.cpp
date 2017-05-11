//
// Created by mwypych on 11.05.17.
//

#include <gtest/gtest.h>
#include <utility>
#include <vector>
#include <MemLeakTest.h>
#include <Algo.h>

using algo::Keys;
using algo::ContainsKey;
using algo::Values;
using algo::ContainsValue;


class AlgoStep4 : public ::testing::Test, MemLeakTest {
 public:
};

TEST_F(AlgoStep4, DefineMethod_ContainsKey) {
  std::map<std::string, int> arg {{"abc",1},{"efg",1}};
  EXPECT_EQ(true, ContainsKey(arg,"efg"));
  EXPECT_EQ(true, ContainsKey(arg,"abc"));
  EXPECT_EQ(false, ContainsKey(arg,"xyz"));
}

TEST_F(AlgoStep4, DefineMethod_Keys) {
  std::set<std::string> expected {"efg","abc"};
  EXPECT_EQ(expected, Keys({{"abc",1},{"efg",1}}));
}

TEST_F(AlgoStep4, DefineMethod_ContainsValue) {
  std::map<std::string, int> arg {{"abc",1},{"efg",1}};
  EXPECT_EQ(true, ContainsValue(arg,1));
  EXPECT_EQ(false, ContainsValue(arg,2));
}

TEST_F(AlgoStep4, DefineMethod_Values) {
  std::vector<int> expected {1,1};
  EXPECT_EQ(expected, Values({{"abc",1},{"efg",1}}));
}
