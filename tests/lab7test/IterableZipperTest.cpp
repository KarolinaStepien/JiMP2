//
// Created by mwypych on 20.04.17.
//

#include <gtest/gtest.h>
#include <string>
#include <vector>
#include <memory>
#include <MemLeakTest.h>
#include <Iterable.h>

using ::utility::Zipper;
using ::std::vector;
using ::std::string;


class IterableZipperTests : public ::testing::Test, MemLeakTest {
 public:
};

TEST_F(IterableZipperTests, ZipEqualLenghtLists) {
  vector<int> vi {4, 77, -91};
  vector<string> vs {"4", "9991", "adfskld"};

  int i = 0;
  for (const auto &p : Zipper(vi, vs)) {
    EXPECT_EQ(vi[i], p.first);
    EXPECT_EQ(vs[i], p.second);
    i++;
  }
}

TEST_F(IterableZipperTests, ZipWithLeftListLonger) {
  vector<int> vi {4, 77, -91, 100, 2000};
  vector<string> vs {"4", "9991", "adfskld"};
  vector<string> vs_expected {"4", "9991", "adfskld", "adfskld", "adfskld"};

  int i = 0;
  for (const auto &p : Zipper(vi, vs)) {
    EXPECT_EQ(vi[i], p.first);
    EXPECT_EQ(vs_expected[i], p.second);
    i++;
  }
}

TEST_F(IterableZipperTests, ZipWithRightListLonger) {
  vector<int> vi {4};
  vector<string> vs {"4", "9991", "adfskld"};
  vector<int> vi_expected {4, 4, 4};

  int i = 0;
  for (const auto &p : Zipper(vi, vs)) {
    EXPECT_EQ(vi_expected[i], p.first);
    EXPECT_EQ(vs[i], p.second);
    i++;
  }
}

TEST_F(IterableZipperTests, ZipEmptyLists) {
  vector<int> vi {};
  vector<string> vs {};

  int i = 0;
  for (const auto &p : Zipper(vi, vs)) {
    EXPECT_EQ(vi[i], p.first);
    EXPECT_EQ(vs[i], p.second);
    i++;
  }
}

