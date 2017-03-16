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
#include <Url.h>

using ::nets::Url;
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
  auto pu = make_unique<Url>(url);

  EXPECT_EQ(expected["scheme"], pu->Scheme());
  EXPECT_EQ(expected["host"], pu->Host());
  EXPECT_EQ(FromString<uint16_t>(expected["port"]), pu->Port());
  EXPECT_EQ(expected["path"], pu->Path());
  EXPECT_EQ(expected["query"], pu->Query());
  EXPECT_EQ(expected["fragment"], pu->Fragment());
}

std::vector<TestParam> urlsTestData
    {{"https://google.com",
      {{"scheme", "https"}, {"host", "google.com"}, {"port", "443"}, {"path", ""}, {"query", ""}, {"fragment", ""}}},
     {"http://www.regular-expressions.info/recurse.html#balanced",
      {{"scheme", "http"}, {"host", "www.regular-expressions.info"}, {"port", "80"}, {"path", "recurse.html"},
       {"query", ""}, {"fragment", "balanced"}}},
     {"https://en.wikipedia.org/wiki/Uniform_Resource_Locator",
      {{"scheme", "https"}, {"host", "en.wikipedia.org"}, {"port", "443"}, {"path", "wiki/Uniform_Resource_Locator"},
       {"query", ""}, {"fragment", ""}}},
     {"https://www.youtube.com/watch?v=K83YZYcpExc",
      {{"scheme", "https"}, {"host", "www.youtube.com"}, {"port", "443"}, {"path", "watch"},
       {"query", "v=K83YZYcpExc"}, {"fragment", ""}}},
     {"https://www.google.pl/maps/dir/50.0661704,19.9231828/50.0622998,19.9379993/@50.064617,19.9255421,16z/data=!4m3!4m2!3e2!5i2",
      {{"scheme", "https"}, {"host", "www.google.pl"}, {"port", "443"}, {"path",
                                                                         "maps/dir/50.0661704,19.9231828/50.0622998,19.9379993/@50.064617,19.9255421,16z/data=!4m3!4m2!3e2!5i2"},
       {"query", ""}, {"fragment", ""}}},
     {"https://www.youtube.com/watch?v=dQw4w9WgXcQ&feature=youtu.be&v=dQw4w9WgXcQ&list=RDdQw4w9WgXcQ&t=33",
      {{"scheme", "https"}, {"host", "www.youtube.com"}, {"port", "443"}, {"path", "watch"},
       {"query", "v=dQw4w9WgXcQ&feature=youtu.be&v=dQw4w9WgXcQ&list=RDdQw4w9WgXcQ&t=33"}, {"fragment", ""}}},
     {"https://leetcode.com/problemset/algorithms/#",
      {{"scheme", "https"}, {"host", "leetcode.com"}, {"port", "443"}, {"path", "problemset/algorithms/"},
       {"query", ""}, {"fragment", ""}}},
     {"ftp://demo.wftpserver.com:2222",
      {{"scheme", "ftp"}, {"host", "demo.wftpserver.com"}, {"port", "2222"}, {"path", ""},
       {"query", ""}, {"fragment", ""}}},
     {"http://ai.ia.agh.edu.pl/wiki/pl:dydaktyka:jimp2:2017:labs:pamiec2",
      {{"scheme", "http"}, {"host", "ai.ia.agh.edu.pl"}, {"port", "80"},
       {"path", "wiki/pl:dydaktyka:jimp2:2017:labs:pamiec2"},
       {"query", ""}, {"fragment", ""}}},
     {"ftp://test.rebex.net",
      {{"scheme", "ftp"}, {"host", "test.rebex.net"}, {"port", "22"}, {"path", ""},
       {"query", ""}, {"fragment", ""}}},
     {"http://geofl.ge/#!/page_saxelmdzvanelo",
      {{"scheme", "http"}, {"host", "geofl.ge"}, {"port", "80"}, {"path", ""},
       {"query", ""}, {"fragment", "!/page_saxelmdzvanelo"}}}

    };

INSTANTIATE_TEST_CASE_P(UrlTestsFixture,
                        UrlTests,
                        ::testing::ValuesIn(urlsTestData));