//
// Created by mwypych on 10.04.17.
//

#include <gtest/gtest.h>
#include <string>
#include <vector>
#include <memory>
#include <MemLeakTest.h>
#include <Iterable.h>

using ::utility::Zipper;
using ::utility::ZipperIterator;
using ::utility::IterableIterator;
using ::std::vector;
using ::std::string;
using ::std::make_unique;


class IterableTests : public ::testing::Test, MemLeakTest {
 public:
};

TEST_F(IterableTests, ImplementsZipperIterator) {
  vector<int> vi {4, 77, -91};
  vector<string> vs {"4", "9991", "adfskld"};
  auto it = ZipperIterator(vi.begin(),vs.begin(), vi.end(), vs.end());
  auto expected_pair = std::make_pair<int,std::string>(4,"4");
  EXPECT_EQ(expected_pair, it.Dereference());
  std::unique_ptr<IterableIterator> next_it = make_unique<ZipperIterator>(vi.begin()+1,vs.begin()+1, vi.end(), vs.end());
  EXPECT_TRUE( it.NotEquals(next_it));
  EXPECT_FALSE(it.Next().NotEquals(next_it));
}

class TestIterator : public IterableIterator {
public:
    std::pair<int, std::string> Dereference() const override {
      return std::make_pair(44,"moje imie");
    }

    IterableIterator &Next() override {
      return *this;
    }

    bool NotEquals(const std::unique_ptr<IterableIterator> &other) const override {
      return false;
    }
};

TEST_F(IterableTests, ThereIsIterableIteratorBaseClass) {
  std::unique_ptr<IterableIterator> test_it = std::make_unique<TestIterator>();
  std::pair<int, std::string> expected_value {44, "moje imie"};
  EXPECT_EQ(expected_value, test_it->Dereference());
  EXPECT_EQ(test_it->Dereference(), test_it->Next().Dereference());
  EXPECT_FALSE(test_it->NotEquals(test_it));
}

//TEST_F(IterableTests, ThereIsIterableIteratorWrapperClass) {
//    IterableIteratorWrapper {};
//}