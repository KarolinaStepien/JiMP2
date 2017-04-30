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
using ::moviesubs::NegativeFrameAfterShift;
using ::moviesubs::SubtitleEndBeforeStart;
using ::moviesubs::InvalidSubtitleLineFormat;

using namespace std;
using namespace std::literals;

class MicroDvdErrorCasesTest : public ::testing::Test, MemLeakTest {
 public:
};

TEST_F(MicroDvdErrorCasesTest, ShiftIntoNegativeFramesThrowsException) {
  auto subs = make_unique<MicroDvdSubtitles>();
  stringstream in {"{10}{250}TEXT\n{260}{300}NEWLINE\n"};
  stringstream out;
  EXPECT_THROW(subs->ShiftAllSubtitlesBy(-11 * 40, 25, &in, &out),NegativeFrameAfterShift);
}

TEST_F(MicroDvdErrorCasesTest, EndFrameLaterThanStartFrameThrowsException) {
  auto subs = make_unique<MicroDvdSubtitles>();
  stringstream in {"{10}{250}TEXT\n{260}{220}NEWLINE\n"};
  stringstream out;
  try {
    subs->ShiftAllSubtitlesBy(1000, 24, &in, &out);
    FAIL() << "it throws nothing";
  } catch (const SubtitleEndBeforeStart &e) {
    EXPECT_EQ(2,e.LineAt()) << "improper line that triggered exception";
    EXPECT_EQ("At line 2: {260}{220}NEWLINE"s,string(e.what()));
  } catch (const std::exception &e) {
    FAIL() << "Should throw exception of type SubtitleEndBeforeStart but instead it threw: " << e.what();
  } catch (...) {
    FAIL() << "Should throw exception of type SubtitleEndBeforeStart but instead it threw different type of exception";
  }
}

TEST_F(MicroDvdErrorCasesTest, IncompleteLineThrowsParsingError) {
  auto subs = make_unique<MicroDvdSubtitles>();
  stringstream in1 {"{10}{250}TEXT\n260}{220}NEWLINE\n"};
  stringstream out;
  EXPECT_THROW(subs->ShiftAllSubtitlesBy(1000, 24, &in1, &out),InvalidSubtitleLineFormat);

  stringstream in2 {"{10250}TEXT\n{260}{220}NEWLINE\n"};
  EXPECT_THROW(subs->ShiftAllSubtitlesBy(1000, 24, &in2, &out),InvalidSubtitleLineFormat);

  stringstream in3 {"{10}250}TEXT\n{260}{220}NEWLINE\n"};
  EXPECT_THROW(subs->ShiftAllSubtitlesBy(1000, 24, &in3, &out),InvalidSubtitleLineFormat);

  stringstream in4 {"{10}{x}TEXT\n{260}{220}NEWLINE\n"};
  EXPECT_THROW(subs->ShiftAllSubtitlesBy(1000, 24, &in4, &out),InvalidSubtitleLineFormat);

  stringstream in5 {"{10}{}TEXT\n{260}{220}NEWLINE\n"};
  EXPECT_THROW(subs->ShiftAllSubtitlesBy(1000, 24, &in5, &out),InvalidSubtitleLineFormat);

  stringstream in6 {"{10}{787}TEXT\n{260}{220NEWLINE\n"};
  EXPECT_THROW(subs->ShiftAllSubtitlesBy(1000, 24, &in6, &out),InvalidSubtitleLineFormat);
}

TEST_F(MicroDvdErrorCasesTest, NegativeFrameRateThrowsIlegalArgument) {
  auto subs = make_unique<MicroDvdSubtitles>();
  stringstream in;
  stringstream out;
  EXPECT_THROW(subs->ShiftAllSubtitlesBy(100, -10, &in, &out),std::invalid_argument);
}