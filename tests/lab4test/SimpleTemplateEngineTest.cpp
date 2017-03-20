//
// Created by mwypych on 16.03.17.
//

#include <gtest/gtest.h>
#include <unordered_map>
#include <memory>
#include <MemLeakTest.h>
#include <StringUtility.h>
#include <SimpleTemplateEngine.h>

using ::nets::View;
using ::std::make_unique;
using ::utility::FromString;

using TestArgument = std::pair<std::string, std::unordered_map<std::string, std::string>>;
using TestExpected = std::string;
using TestParam = std::pair<TestArgument, TestExpected>;

class TemplateEngineTests : public ::testing::TestWithParam<TestParam>, MemLeakTest {};

TEST_P(TemplateEngineTests, DefineViewClassWithRenderMethod) {
  auto param = GetParam();
  const TestArgument &arg = param.first;
  const auto &mapping = arg.second;

  TestExpected &expected = param.second;
  const auto view = make_unique<View>(arg.first);
  EXPECT_EQ(expected, view->Render(mapping));
}

std::vector<TestParam> templateEngineTestData
    {{{"Hello {{name}}! How are you today? My name is {{program}}!",
       {{"name", "Zbigniew"}, {"program", "Borg"}}}, "Hello Zbigniew! How are you today? My name is Borg!"},
     {{"Person:\n\tName: {{name}}\n\tSurname: {{surname}}\n\tAge: {{age}}\n",
       {{"name", "Jan"}, {"surname", "Kowalski"}, {"age", "33"}}
      }, "Person:\n\tName: Jan\n\tSurname: Kowalski\n\tAge: 33\n"},
     {{"Person:\n\tName: {{name}}\n\t2nd time name: {{name}}\n\tAge: {{age}}\n\tNo surname!",
       {{"name", "Jan"}, {"surname", "Kowalski"}, {"age", "33"}}
      }, "Person:\n\tName: Jan\n\t2nd time name: Jan\n\tAge: 33\n\tNo surname!"}
    };

INSTANTIATE_TEST_CASE_P(TemplateEngineTestsFixture,
                        TemplateEngineTests,
                        ::testing::ValuesIn(templateEngineTestData));

TEST_F(TemplateEngineTests, ViewHasToBeImmutable) {
  const auto view = make_unique<View>("Test {{test}}");
  EXPECT_EQ("Test 56$", view->Render({{"test", "56$"}}));
  EXPECT_EQ("Test %%", view->Render({{"test", "%%"}}));
}

TEST_F(TemplateEngineTests, OnlyDoubleBracesSequencesHasToBeInfluenced) {
  const auto view = make_unique<View>("test {{test}} of {test} but {{test} or {test}} and {{{test}}}");
  EXPECT_EQ("test 888 of {test} but {{test} or {test}} and {888}", view->Render({{"test", "888"}}));
}

TEST_F(TemplateEngineTests, MissingDataShouldBeBlank) {
  const auto view = make_unique<View>("Test {{test}} missing:{{missing}}:missing");
  EXPECT_EQ("Test replacement missing::missing", view->Render({{"test", "replacement"}}));
}

TEST_F(TemplateEngineTests, TemplatesMayContainUnderscores) {
  const auto view = make_unique<View>("{{template_with_underscore}}<=>{{template_with_undersocre_missing}}");
  EXPECT_EQ("replacement<=>", view->Render({{"template_with_underscore", "replacement"}}));
}

TEST_F(TemplateEngineTests, TemplatesMayContainNumbers) {
  const auto view = make_unique<View>("{{t09}}<=>{{t17}}");
  EXPECT_EQ("<=>Am I?", view->Render({{"t17", "Am I?"}}));
}
