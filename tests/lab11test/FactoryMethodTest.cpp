//
// Created by mk on 18.05.2017.
//

#include <vector>
#include <gtest/gtest.h>
#include <MemLeakTest.h>
#include "FactoryMethod.h"

using ::factoryMethod::Create;
using ::factoryMethod::MyType;

class FactoryMethodTest : public ::testing::Test, MemLeakTest {
public:
};

TEST_F(FactoryMethodTest, IntFactoryMethodReturnsDefault0Value) {
    int i = Create<int>();
    EXPECT_EQ(0, i);
}

TEST_F(FactoryMethodTest, DoubleFactoryMethodReturnsDefault0Value) {
    double d = Create<double>();
    EXPECT_EQ(0.0, d);
}

TEST_F(FactoryMethodTest, StringFactoryMethodReturnsEmptyString) {
    std::string s = Create<std::string>();
    EXPECT_EQ("", s);
}

TEST_F(FactoryMethodTest, VectorOfDoubleFactoryMethodReturnsEmptyVector) {
    std::vector<double> v = Create<std::vector<double>>();
    EXPECT_EQ(0, v.size());
}

TEST_F(FactoryMethodTest, MyTypeFactoryMethodReturnsDefaultObject) {
    MyType m = Create<MyType>();
    EXPECT_EQ("hello", m.SayHello());
}

