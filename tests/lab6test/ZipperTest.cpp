//
// Created by mwypych on 04.04.17.
//

#include <gtest/gtest.h>
#include <memory>
#include <type_traits>
#include <MemLeakTest.h>
#include <Zipper.h>

using ::datastructures::Zipper;
using ::std::make_unique;
using ::std::move;
using ::std::fill;
using ::std::swap;
using ::std::vector;
using ::std::string;

class ZipperTests : public ::testing::Test, MemLeakTest {
};

TEST_F(ZipperTests, IsAbleToReachBeginOfZippedVectors) {
  std::vector<std::string> one {"abc","efg","koks","oks"};
  std::vector<int> two {34,78,98,13};
  EXPECT_EQ("abc", (*Zipper::zip(one,two).begin()).first);
  EXPECT_EQ(34, (*Zipper::zip(one,two).begin()).second);
}

TEST_F(ZipperTests, IsAbleToIterateOverEqualSizeSequences) {
  std::vector<std::string> one {"abc","efg","koks","oks"};
  std::vector<int> two {34,78,98,13};
  std::vector<std::string> expected {"abc34","efg78","koks98","oks13"};
  auto it = expected.begin();
  for (const auto &p : Zipper::zip(one, two)) {
    EXPECT_EQ(*it,p.first+std::to_string(p.second));
    ++it;
  }
}

TEST_F(ZipperTests, IsAbleToIterateOverUnequalSizeSequences) {
  std::vector<std::string> one {"abc","efg","koks","oks"};
  std::vector<int> two {34,78};
  std::vector<std::string> expected {"abc34","efg78","koks0","oks0"};
  auto it = expected.begin();
  for (const auto &p : Zipper::zip(one, two)) {
    EXPECT_EQ(*it,p.first+std::to_string(p.second));
    ++it;
  }
}

TEST_F(ZipperTests, IsAbleToIterateOverUnequalSizeSequences2) {
  std::vector<std::string> one {"abc"};
  std::vector<int> two {34,78,98,13};
  std::vector<std::string> expected {"abc34","78","98","13"};
  auto it = expected.begin();
  for (const auto &p : Zipper::zip(one, two)) {
    EXPECT_EQ(*it,p.first+std::to_string(p.second));
    ++it;
  }
}