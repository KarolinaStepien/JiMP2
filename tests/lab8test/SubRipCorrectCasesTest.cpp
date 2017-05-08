//
// Created by mwypych on 30.04.17.
//

#include <gtest/gtest.h>
#include <string>
#include <memory>
#include <stdexcept>
#include <MemLeakTest.h>
#include <StringUtility.h>
#include <MovieSubtitles.h>

using ::moviesubs::SubRipSubtitles;
using ::utility::MatchesUpToExtraNewLine;

using namespace std;
using namespace std::literals;


class SubRipCorrectCasesTest : public ::testing::Test, MemLeakTest {
 public:
};


TEST_F(SubRipCorrectCasesTest, SubtitlesMovedBy300ms) {
  auto subs = make_unique<SubRipSubtitles>();
  stringstream in {"1\n00:05:54,555 --> 00:05:56,722\nText\n\n2\n00:06:06,433 --> 00:06:07,801\nNEWLINE\n"};
  stringstream out;
  EXPECT_NO_THROW(subs->ShiftAllSubtitlesBy(300, 24, &in, &out));
  EXPECT_PRED2(MatchesUpToExtraNewLine,"1\n00:05:54,855 --> 00:05:57,022\nText\n\n2\n00:06:06,733 --> 00:06:08,101\nNEWLINE\n"s,out.str());
}

TEST_F(SubRipCorrectCasesTest, SubtitlesMovedBy1500ms) {
  auto subs = make_unique<SubRipSubtitles>();
  stringstream in {"1\n"
                       "00:20:41,150 --> 00:20:45,109\n"
                       "- How did he do that?\n"
                       "- Made him an offer he couldn't refuse.\n\n"};
  stringstream out;
  EXPECT_NO_THROW(subs->ShiftAllSubtitlesBy(1500, 25, &in, &out));
  EXPECT_PRED2(MatchesUpToExtraNewLine,"1\n00:20:42,650 --> 00:20:46,609\n- How did he do that?\n- Made him an offer he couldn't refuse.\n\n"s,out.str());
}