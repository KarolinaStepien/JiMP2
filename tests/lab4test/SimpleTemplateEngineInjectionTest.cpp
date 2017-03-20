//
// Created by mwypych on 17.03.17.
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

class TemplateEngineInjectionTests : public ::testing::TestWithParam<TestParam>, MemLeakTest {
};

TEST_F(TemplateEngineInjectionTests, Injection) {
  const auto view = make_unique<View>("Test {{test}} {{injected}}");
  EXPECT_EQ("Test {{injected}} {{test}}", view->Render({{"test", "{{injected}}"}, {"injected", "{{test}}"}}));
}