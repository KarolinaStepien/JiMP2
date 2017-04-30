//
// Created by mwypych on 30.04.17.
//

#include <gtest/gtest.h>
#include <string>
#include <memory>
#include <stdexcept>
#include <MemLeakTest.h>
#include <MovieSubtitles.h>

using ::moviesubs::MicroDvdSubtitles;

using namespace std;
using namespace std::literals;

class MicroDvdCorrectCasesTest : public ::testing::Test, MemLeakTest {
 public:
};

TEST_F(MicroDvdCorrectCasesTest, MicroDvdSubtitlesMovedBy300ms) {
  auto subs = make_unique<MicroDvdSubtitles>();
  stringstream in {"{0}{250}TEXT\n{260}{300}NEWLINE\n"};
  stringstream out;
  subs->ShiftAllSubtitlesBy(300, 25, &in, &out);
  EXPECT_EQ("{7}{257}TEXT\n{267}{307}NEWLINE\n"s,out.str());
}

TEST_F(MicroDvdCorrectCasesTest, MicroDvdSubtitlesMovedBy1400ms) {
  auto subs = make_unique<MicroDvdSubtitles>();
  stringstream in {"{0}{250}TEXT TEXT\n{260}{300}NEWLINE\n"};
  stringstream out;
  subs->ShiftAllSubtitlesBy(1400, 10, &in, &out);
  EXPECT_EQ("{14}{264}TEXT TEXT\n{274}{314}NEWLINE\n"s,out.str());
}

TEST_F(MicroDvdCorrectCasesTest, OverlappingSubtitlesAreCorrect) {
  auto subs = make_unique<MicroDvdSubtitles>();
  stringstream in {"{0}{250}TEXT\n{260}{300}NEWLINE\n{280}{350} Longer text of subtitles"};
  stringstream out;
  subs->ShiftAllSubtitlesBy(300, 25, &in, &out);
  EXPECT_EQ("{7}{257}TEXT\n{267}{307}NEWLINE\n{287}{357} Longer text of subtitles\n"s,out.str());
}

TEST_F(MicroDvdCorrectCasesTest, TextWithFormattingIsCorrect) {
  auto subs = make_unique<MicroDvdSubtitles>();
  stringstream in {"{0}{100}{y:b}bold text\n{144}{299}{s:12}12 Font used\n{280}{350}{c:$0000FF}Hello!\n{1000}{1050}Multi|Line|Text\n"};
  stringstream out;
  subs->ShiftAllSubtitlesBy(2300, 20, &in, &out);
  EXPECT_EQ("{46}{146}{y:b}bold text\n{190}{345}{s:12}12 Font used\n{326}{396}{c:$0000FF}Hello!\n{1046}{1096}Multi|Line|Text\n"s,out.str());
}