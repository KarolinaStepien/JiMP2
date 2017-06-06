//
// Created by mwypych on 25.05.17.
//
#include <string>
#include <unordered_map>
#include <thread>
#include <chrono>
#include <gtest/gtest.h>
#include <MemLeakTest.h>
#include "TimeRecorder.h"

using ::profiling::TimeRecorder;
using ::std::literals::string_literals::operator ""s;

struct TestStruct {
  TestStruct(int f1, const std::string &f2) : f1(f1), f2(f2) {}
  int f1;
  std::string f2;
};

class TimeRecorderTest : public ::testing::Test, MemLeakTest {
 public:
};

int TestNothingFunction() {
  return 0;
}

std::string TestStringFunction() {
  return "test"s;
}

TestStruct TestStructFunction() {
  return TestStruct (1'000'871, "191xyz"s);
}

struct TestIntOperatorOverloading {
  int operator()() const {
    return 23;
  }
};

struct TestStringOperatorOverloading {
  std::string operator()() const {
    return "head tail";
  }
};

struct TestStructOperatorOverloading {
  TestStruct operator()() const {
    return TestStruct(62,"u");
  }
};


struct TestLongFunction {
  TestLongFunction(int ms) : ms(ms) {}

  int operator()() const {
    std::this_thread::sleep_for(std::chrono::milliseconds{ms});
    return 0;
  }

  int ms;
};

TEST_F(TimeRecorderTest, CanCallTimeRecorderWithGlobalIntFunctionPointer) {
  std::pair<int, double> record = TimeRecorder(TestNothingFunction);
  EXPECT_EQ(0, record.first);
  //execution time between 0 and 10 ms
  EXPECT_LT(record.second, 10);
  EXPECT_GT(record.second, 0);
}

TEST_F(TimeRecorderTest, CanCallTimeRecorderWithGlobalStringFunctionPointer) {
  std::pair<std::string, double> record = TimeRecorder(TestStringFunction);
  EXPECT_EQ("test"s, record.first);
  //execution time between 0 and 10 ms
  EXPECT_LT(record.second, 10);
  EXPECT_GT(record.second, 0);
}

TEST_F(TimeRecorderTest, CanCallTimeRecorderWithGlobalTestStructFunctionPointer) {
  std::pair<TestStruct, double> record = TimeRecorder(TestStructFunction);
  EXPECT_EQ(1'000'871, record.first.f1);
  EXPECT_EQ("191xyz"s, record.first.f2);
  //execution time between 0 and 10 ms
  EXPECT_LT(record.second, 10);
  EXPECT_GT(record.second, 0);
}

TEST_F(TimeRecorderTest, CanCallTimeRecorderWithLambdaReturningInt) {
  std::pair<int, double> record = TimeRecorder([](){return 89;});
  EXPECT_EQ(89, record.first);
  //execution time between 0 and 10 ms
  EXPECT_LT(record.second, 10);
  EXPECT_GT(record.second, 0);
}

TEST_F(TimeRecorderTest, CanCallTimeRecorderWithLambdaReturningString) {
  std::pair<std::string, double> record = TimeRecorder([](){return "x78i"s;});
  EXPECT_EQ("x78i"s, record.first);
  //execution time between 0 and 10 ms
  EXPECT_LT(record.second, 10);
  EXPECT_GT(record.second, 0);
}

TEST_F(TimeRecorderTest, CanCallTimeRecorderWithLambdaReturningTestStruct) {
  std::pair<TestStruct, double> record = TimeRecorder([](){return TestStruct(-12, "+*()");});
  EXPECT_EQ(-12, record.first.f1);
  EXPECT_EQ("+*()"s, record.first.f2);
  //execution time between 0 and 10 ms
  EXPECT_LT(record.second, 10);
  EXPECT_GT(record.second, 0);
}

TEST_F(TimeRecorderTest, CanCallTimeRecorderWithStructOverloadingFunctionOperatorReturningInt) {
  std::pair<int, double> record = TimeRecorder(TestIntOperatorOverloading());
  EXPECT_EQ(23, record.first);
  //execution time between 0 and 10 ms
  EXPECT_LT(record.second, 10);
  EXPECT_GT(record.second, 0);
}

TEST_F(TimeRecorderTest, CanCallTimeRecorderWithStructOverloadingFunctionOperatorReturningString) {
  std::pair<std::string, double> record = TimeRecorder(TestStringOperatorOverloading());
  EXPECT_EQ("head tail"s, record.first);
  //execution time between 0 and 10 ms
  EXPECT_LT(record.second, 10);
  EXPECT_GT(record.second, 0);
}

TEST_F(TimeRecorderTest, CanCallTimeRecorderWithStructOverloadingFunctionOperatorReturningTestStruct) {
  std::pair<TestStruct, double> record = TimeRecorder(TestStructOperatorOverloading());
  EXPECT_EQ(62, record.first.f1);
  EXPECT_EQ("u"s, record.first.f2);
  //execution time between 0 and 10 ms
  EXPECT_LT(record.second, 10);
  EXPECT_GT(record.second, 0);
}

TEST_F(TimeRecorderTest, RecordsTimeOfLongerFunctionsApprox30ms) {
  std::pair<int, double> record = TimeRecorder(TestLongFunction(30));
  EXPECT_EQ(0, record.first);
  //execution time between 29 and 60 ms
  EXPECT_LT(record.second, 60);
  EXPECT_GT(record.second, 29);
}

TEST_F(TimeRecorderTest, RecordsTimeOfLongerFunctionsApprox470ms) {
  std::pair<int, double> record = TimeRecorder(TestLongFunction(470));
  EXPECT_EQ(0, record.first);
  //execution time between 450 and 600 ms
  EXPECT_LT(record.second, 600);
  EXPECT_GT(record.second, 450);
}