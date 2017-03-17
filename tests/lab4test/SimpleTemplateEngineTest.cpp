//
// Created by mwypych on 16.03.17.
//

#include <gtest/gtest.h>
#include <memory>
#include <MemLeakTest.h>
#include <StringUtility.h>
#include <SimpleTemplateEngine.h>

using ::nets::View;
using ::std::make_unique;
using ::utility::FromString;

using TestArgument = std::pair<std::string, std::map<std::string, std::string>>;
using TestExpected = std::string;
using TestParam = std::pair<TestArgument, TestExpected>;

class UrlTests : public ::testing::TestWithParam<TestParam>, MemLeakTest {
};

TEST_P(UrlTests, DefineViewClassWithRenderMethod) {
  auto param = GetParam();
  const TestArgument &arg = param.first;
  const auto &mapping = arg.second;

  TestExpected &expected = param.second;
  const auto view = make_unique<View>(arg.first);
  EXPECT_EQ(expected, view->Render(mapping));
}

std::vector<TestParam> urlsTestData
    {{{"Hello {{name}}! How are you today? My name is {{program}}!",
       {{"name", "Zbigniew"}, {"program", "Borg"}}}, "Hello Zbigniew! How are you today? My name is Borg!"},
     {{"Person:\n\tName: {{name}}\n\tSurname: {{surname}}\n\tAge: {{age}}\n",
       {{"name", "Jan"}, {"surname", "Kowalski"}, {"age", "33"}}
      }, "Person:\n\tName: Jan\n\tSurname: Kowalski\n\tAge: 33\n"},
     {{"Person:\n\tName: {{name}}\n\t2nd time name: {{name}}\n\tAge: {{age}}\n\tNo surname!",
       {{"name", "Jan"}, {"surname", "Kowalski"}, {"age", "33"}}
      }, "Person:\n\tName: Jan\n\t2nd time name: Jan\n\tAge: 33\n\tNo surname!"}
    };

INSTANTIATE_TEST_CASE_P(UrlTestsFixture,
                        UrlTests,
                        ::testing::ValuesIn(urlsTestData));

TEST_F(UrlTests, ViewHasToBeImmutable) {
  const auto view = make_unique<View>("Test {{test}}");
  EXPECT_EQ("Test 56$", view->Render({{"test", "56$"}}));
  EXPECT_EQ("Test %%", view->Render({{"test", "%%"}}));
}
