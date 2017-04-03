//
// Created by mwypych on 03.04.17.
//

#include <gtest/gtest.h>
#include <memory>
#include <MemLeakTest.h>


using ::datastructures::Counter;
using ::datastructures::Counts;
using ::datastructures::Word;


class CounterTests : public ::testing::Test, MemLeakTest {
};