//
// Created by mwypych on 20.03.17.
//


#include <string>
#include <vector>
#include <map>
#include <regex>
#include <gtest/gtest.h>
#include <MemLeakTest.h>
#include <StringUtility.h>
#include <SimpleJson.h>

using ::nets::JsonValue;
using ::std::vector;
using ::std::string;
using ::std::map;
using ::utility::FromString;
using ::std::regex;
using ::std::regex_match;
using namespace ::std::literals;

using TestArgument = JsonValue;
using TestExpected = std::string;
using TestParam = std::pair<TestArgument, TestExpected>;

using TrickyTestArgument = std::string;
using TrickyTestParam = std::pair<TrickyTestArgument, TestExpected>;

class SimpleJsonTestTests : public ::testing::TestWithParam<TestParam>, MemLeakTest {
};

TEST_F(SimpleJsonTestTests, CreationOfJsonValues) {
  JsonValue int_value{17};
  EXPECT_EQ("17", int_value.ToString());
  JsonValue double_value{56.89};
  EXPECT_EQ("56.89", double_value.ToString());
  JsonValue bool_true_value{true};
  EXPECT_EQ("true", bool_true_value.ToString());
  JsonValue bool_false_value{false};
  EXPECT_EQ("false", bool_false_value.ToString());
  JsonValue str_value{"abc"s};
  EXPECT_EQ("\"abc\"", str_value.ToString());
  JsonValue int_array_value{vector<JsonValue>{{14}, {1003}, {-56}}};
  EXPECT_EQ("[14, 1003, -56]", int_array_value.ToString());
  map<string, JsonValue> object{{"name", {"Maciej"s}}, {"age", {44}}, {"account_balance", {-107.89}}};
  JsonValue simple_object_value{object};
  string obj_str = simple_object_value.ToString();
  EXPECT_NE(string::npos, obj_str.find("\"account_balance\": -107.89"));
  EXPECT_NE(string::npos, obj_str.find("\"age\": 44"));
  EXPECT_NE(string::npos, obj_str.find("\"name\": \"Maciej\""));
EXPECT_TRUE(regex_match(obj_str, regex{R"(\{"\w+": ["\w\.-]+, "\w+": ["\w\.-]+, "\w+": ["\w\.-]+\})"}));
EXPECT_FALSE(regex_match(obj_str, regex{"-107.89(0)+"}));
}

TEST_P(SimpleJsonTestTests, GetValueByNameReturnsSubValueInCaseOfObjectOrNullptrOtherwise) {
  JsonValue int_value{17};
  EXPECT_FALSE(int_value.ValueByName("whatever"));
  JsonValue double_value{56.89};
  EXPECT_FALSE(double_value.ValueByName("whatever"));
  JsonValue bool_true_value{true};
  EXPECT_FALSE(bool_true_value.ValueByName("whatever"));
  JsonValue bool_false_value{false};
  EXPECT_FALSE(bool_false_value.ValueByName("whatever"));
  JsonValue str_value{"abc"s};
  EXPECT_FALSE(str_value.ValueByName("whatever"));
  JsonValue int_array_value{vector<JsonValue>{{14}, {1003}, {-56}}};
  EXPECT_FALSE(int_array_value.ValueByName("whatever"));
  JsonValue simple_object_value{map<string, JsonValue> {{"name", {"Maciej"s}},
                                                        {"age", {44}},
                                                        {"account_balance", {-107.89}}}};
  EXPECT_FALSE(simple_object_value.ValueByName("whatever"));
  EXPECT_EQ("\"Maciej\"", simple_object_value.ValueByName("name")->ToString());
  EXPECT_EQ("44", simple_object_value.ValueByName("age")->ToString());
  EXPECT_EQ("-107.89", simple_object_value.ValueByName("account_balance")->ToString());
}

class TrickySimpleJsonTestTests : public ::testing::TestWithParam<TrickyTestParam>, MemLeakTest {
};

TEST_P(TrickySimpleJsonTestTests, CreationOfTrickyJsonStringValues) {
  string str_value;
  string expected;
  std::tie(str_value, expected) = GetParam();
  EXPECT_EQ(expected, JsonValue{str_value}.ToString());
}

TEST_P(TrickySimpleJsonTestTests, CreationOfTrickyJsonObjectsWithTrickyNameValues) {
  string str_value;
  string expected_str;
  std::tie(str_value, expected_str) = GetParam();
  map<string, JsonValue> obj{{str_value, JsonValue{10}}};
  JsonValue obj_value{obj};
  auto expected = "{" + expected_str + ": 10}";
  EXPECT_EQ(expected, obj_value.ToString());
}

std::vector<TrickyTestParam> trickyJsonStringTestData
    {{R"("abc")"s, R"("\"abc\"")"s},
     {R"(efg"hjk")"s, R"("efg\"hjk\"")"s},
     {R"(\"abc\")"s, R"("\\\"abc\\\"")"s},
     {R"(\\"ghh\")"s, R"("\\\\\"ghh\\\"")"s},
     {R"(\\\"klmnopr\\\")"s, R"("\\\\\\\"klmnopr\\\\\\\"")"s},
     {R"(\\\\\\\"http:\\\\\\\"klmno)"s, R"("\\\\\\\\\\\\\\\"http:\\\\\\\\\\\\\\\"klmno")"s},
     {R"(\\\\\\"http:\\\\\\"klmno)"s, R"("\\\\\\\\\\\\\"http:\\\\\\\\\\\\\"klmno")"s}
    };

INSTANTIATE_TEST_CASE_P(TrickySimpleJsonTestTestsFixture,
                        TrickySimpleJsonTestTests,
                        ::testing::ValuesIn(trickyJsonStringTestData));



