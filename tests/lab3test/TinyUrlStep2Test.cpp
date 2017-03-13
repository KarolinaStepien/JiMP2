//
// Created by mwypych on 21.02.17.
//

#include <gtest/gtest.h>
#include <memory>
#include <map>
#include <string>
#include <MemLeakTest.h>
#include <TinyUrl.h>

using ::std::string;
using ::std::unique_ptr;
using ::std::map;
using ::tinyurl::TinyUrlCodec;
using TestParam = string;

class TinyUrlStep2 : public ::testing::TestWithParam<TestParam>, MemLeakTest {
 public:
  void FillArray(const std::string &prototype, std::array<char, 6> *arg) {
    for (int i = 0; i < 6; ++i) {
      (*arg)[i] = prototype[i];
    }
  }
};

TEST_P(TinyUrlStep2, DefineMethod_Init_Encode_Decode) {
  unique_ptr<TinyUrlCodec> codec = tinyurl::Init();
  const auto url = GetParam();
  const auto hash = tinyurl::Encode(url, &codec);
  auto decoded_url = tinyurl::Decode(codec, hash);
  EXPECT_EQ(url, decoded_url);
}

std::vector<TestParam> tinyUrlBunchOfUrlsTestData
    {"https://google.com", "https://wikipedia.org", "https://regex101.com/",
     "http://www.regular-expressions.info/recurse.html#balanced", "https://xkcd.com/1755/", "https://xkcd.com/1758/",
     "https://xkcd.com/1775/", "http://stackoverflow.com/questions/29397066/c-regexp-to-parsing-nested-struct",
     "http://www.regular-expressions.info/boost.html",
     "https://phys.org/news/2016-09-discovery-quasars-ancient-universe.html",
     "https://phys.org/news/2017-03-discovery-bevy-quasars-boost-efforts.html",
     "https://www.youtube.com/watch?v=FkCT_LV9Syk", "http://ai.ia.agh.edu.pl/wiki/pl:dydaktyka:jimp2:2017:labs:pamiec2",
     "https://leetcode.com/problemset/algorithms/#", "https://en.wikipedia.org/wiki/List_of_Unicode_characters",
     "http://unicode.org/reports/tr15/", "https://reviewable.io/", "https://github.com/integrations",
     "https://github.com/integrations/travis-ci", "https://github.com/integrations/sonarqube",
     "http://www.talkenglish.com/vocabulary/top-2000-vocabulary.aspx", "https://www.topcoder.com",
     "https://pl.wikipedia.org/wiki/Filtr_Kalmana", "https://www.youtube.com/watch?v=2pzxEmh0gYw",
     "http://geofl.ge/#!/page_saxelmdzvanelo", "https://www.youtube.com/watch?v=K83YZYcpExc",
     "https://www.memrise.com/", "https://www.duolingo.com/"
    };

INSTANTIATE_TEST_CASE_P(TinyUrlStep2Fixture,
                        TinyUrlStep2,
                        ::testing::ValuesIn(tinyUrlBunchOfUrlsTestData));

TEST_F(TinyUrlStep2, AllUrlsShouldBeEncodedUniquely) {
  unique_ptr<TinyUrlCodec> codec = tinyurl::Init();
  map<string, string> hashes;
  for (auto url : tinyUrlBunchOfUrlsTestData) {
    const auto hash = tinyurl::Encode(url, &codec);
    auto i = hashes.find(hash);
    if (i != hashes.end()) {
      EXPECT_NE(url, i->second)
                << "URL: " << url << " conflicts with URL: " << i->second << " (Both have hash: " << hash << ")";
    } else {
      hashes.emplace_hint(i, hash, url);
    }
  }
}