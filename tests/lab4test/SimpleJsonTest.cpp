//
// Created by mwypych on 20.03.17.
//


#include <gtest/gtest.h>
#include <regex>
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
  JsonValue
      simple_object_value{map<string, JsonValue>{{"name", {"Maciej"s}}, {"age", {44}}, {"account_balance", {-107.89}}}};
  string obj_str = simple_object_value.ToString();
  EXPECT_NE(string::npos, obj_str.find("\"account_balance\": -107.89"));
  EXPECT_NE(string::npos, obj_str.find("\"age\": 44"));
  EXPECT_NE(string::npos, obj_str.find("\"name\": \"Maciej\""));
EXPECT_TRUE(regex_match(obj_str, regex{R"(\{"\w+": ["\w\.-]+, "\w+": ["\w\.-]+, "\w+": ["\w\.-]+\})"}));
EXPECT_FALSE(regex_match(obj_str, regex{"-107.89(0)+"}));
}

TEST_P(SimpleJsonTestTests, CreationOfTrickyJsonStringValues) {
  JsonValue str_value{0};
  string expected;
  std::bind(GetParam(), str_value, expected);
  EXPECT_EQ(expected, str_value.ToString());
}

TEST_P(SimpleJsonTestTests, CreationOfTrickyJsonObjectsWithTrickyNameValues) {
  JsonValue str_value{0};
  string expected_str;
  std::bind(GetParam(), str_value, expected_str);
  JsonValue obj_value{{str_value.ToString(), JsonValue{10}}};
  auto expected = "{" + expected_str + ": 10}";
  EXPECT_EQ(expected, obj_value.ToString());
}

std::vector<TestParam> trickyJsonStringTestData
    {{JsonValue {R"("abc")"}, R"("\"abc\"")"},
     {JsonValue {R"(efg"hjk")"}, R"(efg\"hjk\")"},
     {JsonValue {R"(\"abc\")"}, R"(\"abc\")"},
     {JsonValue {R"(\\"ghh\")"}, R"(\\\"ghh\")"},
     {JsonValue {R"(\\\"klmnopr\\\")"}, R"(\\\"klmnopr\\\")"},
     {JsonValue {R"(\\\\\\\"http:\\\\\\\"klmno)"}, R"("\"abc\"")"},
     {JsonValue {R"(\\\\\\"http:\\\\\\"klmno)"}, R"("\"abc\"")"}
    };

INSTANTIATE_TEST_CASE_P(SimpleJsonTestTestsFixture,
                        SimpleJsonTestTests,
                        ::testing::ValuesIn(trickyJsonStringTestData));

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
  EXPECT_EQ("Maciej", simple_object_value.ValueByName("name")->ToString());
  EXPECT_EQ("44", simple_object_value.ValueByName("age")->ToString());
  EXPECT_EQ("-107.89", simple_object_value.ValueByName("account_balance")->ToString());
}