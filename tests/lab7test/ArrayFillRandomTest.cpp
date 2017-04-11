//
// Created by mwypych on 10.04.17.
//

#include <gtest/gtest.h>
#include <vector>
#include <memory>
#include <random>
#include <MemLeakTest.h>
#include <ArrayFill.h>

using ::arrays::RandomFill;
using ::arrays::FillArray;
using ::std::default_random_engine;
using ::std::uniform_int_distribution;
using ::std::make_unique;

class ArrayFillRandomTests : public ::testing::Test, MemLeakTest {
};

TEST_F(ArrayFillRandomTests, FillsArrayWithRandomValues) {
  std::vector<int> vs;

  auto generator = make_unique<default_random_engine>();
  auto distribution = make_unique<uniform_int_distribution<int>>(1,6);
  RandomFill filler {move(generator), move(distribution)};
  FillArray(35, filler, &vs);

  auto expected_generator = default_random_engine {};
  auto expected_distribution = uniform_int_distribution<int> {1,6};
  for (int i = 0; i < 35; i++) {
    EXPECT_EQ(expected_distribution(expected_generator), vs.at(i));
  }
}
