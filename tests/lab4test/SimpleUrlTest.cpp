//
// Created by mwypych on 16.03.17.
//

//
// Created by mwypych on 21.02.17.
//

#include <gtest/gtest.h>
#include <memory>
#include <MemLeakTest.h>
#include <StringUtility.h>
#include <SimpleUrl.h>

using ::nets::SimpleUrl;
using ::std::make_unique;
using ::utility::FromString;

using TestArgument = std::string;
using TestExpected = std::map<std::string, std::string>;
using TestParam = std::pair<TestArgument, TestExpected>;

class UrlTests : public ::testing::TestWithParam<TestParam>, MemLeakTest {
};

TEST_P(UrlTests, DefineMethod_NextHash) {
  auto param = GetParam();
  const TestArgument &url = param.first;
  TestExpected &expected = param.second;
  auto purl = make_unique<SimpleUrl>(url);

  EXPECT_EQ(expected["scheme"], purl->Scheme());
  EXPECT_EQ(expected["login"], purl->Login());
  EXPECT_EQ(expected["host"], purl->Host());
  EXPECT_EQ(FromString<uint16_t>(expected["port"]), purl->Port());
  EXPECT_EQ(expected["path"], purl->Path());
  EXPECT_EQ(expected["query"], purl->Query());
  EXPECT_EQ(expected["fragment"], purl->Fragment());
}

std::vector<TestParam> urlsTestData
    {{"https://google.com",
      {{"scheme", "https"}, {"login", ""}, {"host", "google.com"}, {"port", "443"}, {"path", ""}, {"query", ""},
       {"fragment", ""}}},
     {"http://www.regular-expressions.info/recurse.html#balanced",
      {{"scheme", "http"}, {"login", ""}, {"host", "www.regular-expressions.info"}, {"port", "80"},
       {"path", "recurse.html"}, {"query", ""}, {"fragment", "balanced"}}},
     {"https://en.wikipedia.org/wiki/Uniform_Resource_Locator",
      {{"scheme", "https"}, {"login", ""}, {"host", "en.wikipedia.org"}, {"port", "443"},
       {"path", "wiki/Uniform_Resource_Locator"}, {"query", ""}, {"fragment", ""}}},
     {"https://www.youtube.com/watch?v=K83YZYcpExc",
      {{"scheme", "https"}, {"login", ""}, {"host", "www.youtube.com"}, {"port", "443"}, {"path", "watch"},
       {"query", "v=K83YZYcpExc"}, {"fragment", ""}}},
     {"https://www.google.pl/maps/dir/50.0661704,19.9231828/50.0622998,19.9379993/@50.064617,19.9255421,16z/data=!4m3!4m2!3e2!5i2",
      {{"scheme", "https"}, {"login", ""}, {"host", "www.google.pl"}, {"port", "443"},
       {"path", "maps/dir/50.0661704,19.9231828/50.0622998,19.9379993/@50.064617,19.9255421,16z/data=!4m3!4m2!3e2!5i2"},
       {"query", ""}, {"fragment", ""}}},
     {"https://www.youtube.com/watch?v=dQw4w9WgXcQ&feature=youtu.be&v=dQw4w9WgXcQ&list=RDdQw4w9WgXcQ&t=33",
      {{"scheme", "https"}, {"login", ""}, {"host", "www.youtube.com"}, {"port", "443"}, {"path", "watch"},
       {"query", "v=dQw4w9WgXcQ&feature=youtu.be&v=dQw4w9WgXcQ&list=RDdQw4w9WgXcQ&t=33"}, {"fragment", ""}}},
     {"https://leetcode.com/problemset/algorithms/#",
      {{"scheme", "https"}, {"login", ""}, {"host", "leetcode.com"}, {"port", "443"},
       {"path", "problemset/algorithms/"}, {"query", ""}, {"fragment", ""}}},
     {"ftp://demo.wftpserver.com:2222",
      {{"scheme", "ftp"}, {"login", ""}, {"host", "demo.wftpserver.com"}, {"port", "2222"}, {"path", ""}, {"query", ""},
       {"fragment", ""}}},
     {"http://ai.ia.agh.edu.pl/wiki/pl:dydaktyka:jimp2:2017:labs:pamiec2",
      {{"scheme", "http"}, {"login", ""}, {"host", "ai.ia.agh.edu.pl"}, {"port", "80"},
       {"path", "wiki/pl:dydaktyka:jimp2:2017:labs:pamiec2"}, {"query", ""}, {"fragment", ""}}},
     {"ftp://test.rebex.net",
      {{"scheme", "ftp"}, {"login", ""}, {"host", "test.rebex.net"}, {"port", "22"}, {"path", ""}, {"query", ""},
       {"fragment", ""}}},
     {"http://geofl.ge/#!/page_saxelmdzvanelo",
      {{"scheme", "http"}, {"login", ""}, {"host", "geofl.ge"}, {"port", "80"}, {"path", ""}, {"query", ""},
       {"fragment", "!/page_saxelmdzvanelo"}}},
     {"mailto:someone@example.com",
      {{"scheme", "mailto"}, {"login", "someone"}, {"host", "example.com"}, {"port", "0"}, {"path", ""}, {"query", ""},
       {"fragment", ""}}},
     {"mailto:someone@example.com?subject=This%20is%20the%20subject&cc=someone_else@example.com&body=This%20is%20the%20body",
      {{"scheme", "mailto"}, {"login", "someone"}, {"host", "example.com"}, {"port", "0"}, {"path", ""},
       {"query", "subject=This%20is%20the%20subject&cc=someone_else@example.com&body=This%20is%20the%20body"},
       {"fragment", ""}}},
    };

INSTANTIATE_TEST_CASE_P(UrlTestsFixture,
                        UrlTests,
                        ::testing::ValuesIn(urlsTestData));