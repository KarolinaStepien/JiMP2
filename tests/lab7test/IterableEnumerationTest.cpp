//
// Created by mwypych on 20.04.17.
//

#include <gtest/gtest.h>
#include <string>
#include <vector>
#include <memory>
#include <MemLeakTest.h>
#include <Iterable.h>

using ::utility::Enumerate;
using ::std::vector;
using ::std::string;


class IterableEnumerationTests : public ::testing::Test, MemLeakTest {
 public:
};

TEST_F(IterableEnumerationTests, EnumerateStringList) {
  vector<string> vs {"4", "9991", "adfskld"};
  vector<int> expected {1, 2, 3};

  int i = 0;
  for (const auto &p : Enumerate(vs)) {
    EXPECT_EQ(expected[i], p.first);
    EXPECT_EQ(vs[i], p.second);
    i++;
  }
}
