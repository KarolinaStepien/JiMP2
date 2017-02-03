//
// Created by mwypych on 02.02.17.
//

//#include "../lib/gtest-1.8.0/googletest/include/gtest/gtest.h"

#include <gtest/gtest.h>
#include <Factorial.h>

TEST(factorial_test, factorial_of_0_is_1) {
  EXPECT_EQ(1, factorial(0));
}

TEST(factorial_test, factorial_of_1_is_1) {
  EXPECT_EQ(1, factorial(1));
}

TEST(factorial_test, factorial_of_5_is_120) {
  EXPECT_EQ(120, factorial(5));
}

TEST(factorial_test, factorial_of_neg3_is_neg6) {
  EXPECT_EQ(-6, factorial(-3));
}

TEST(factorial_test, factorial_of_neg4_is_24) {
  EXPECT_EQ(24, factorial(-4));
}

