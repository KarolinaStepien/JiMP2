//
// Created by mwypych on 30.04.17.
//

#include <gtest/gtest.h>
#include <string>
#include <memory>
#include <stdexcept>
#include <MemLeakTest.h>
#include <MovieSubtitles.h>

using ::moviesubs::SubRipSubtitles;
using ::moviesubs::NegativeFrameAfterShift;
using ::moviesubs::SubtitleEndBeforeStart;
using ::moviesubs::InvalidSubtitleLineFormat;
using ::moviesubs::MissingTimeSpecification;
using ::moviesubs::OutOfOrderFrames;

using namespace std;
using namespace std::literals;

class SubRipErrorCasesTest : public ::testing::Test, MemLeakTest {
 public:
  unique_ptr<SubRipSubtitles> subs = make_unique<SubRipSubtitles>();
  stringstream out;
};

TEST_F(SubRipErrorCasesTest, ShiftIntoNegativeFramesThrowsException) {
  stringstream in {"1\n00:00:10,345 --> 00:00:12,678\nTEXT\n\n2\n00:19:14,141 --> 00:21:20,100\nTT\n"};
  EXPECT_THROW(subs->ShiftAllSubtitlesBy(-1140, 25, &in, &out),NegativeFrameAfterShift);
}

TEST_F(SubRipErrorCasesTest, EndFrameLaterThanStartFrameThrowsException) {
  stringstream in {"1\n00:00:10,345 --> 00:00:12,678\nTEXT\n\n2\n00:19:14,141 --> 00:17:20,100\nTT\n"};
  try {
    subs->ShiftAllSubtitlesBy(1000, 24, &in, &out);
    FAIL() << "it throws nothing";
  } catch (const SubtitleEndBeforeStart &e) {
    EXPECT_EQ(2,e.LineAt()) << "improper line that triggered exception";
    EXPECT_EQ("At line 2: 00:19:14,141 --> 00:17:20,100"s,string(e.what()));
  } catch (const std::exception &e) {
    FAIL() << "Should throw exception of type SubtitleEndBeforeStart but instead it threw: " << e.what();
  } catch (...) {
    FAIL() << "Should throw exception of type SubtitleEndBeforeStart but instead it threw different type of exception";
  }
}

TEST_F(SubRipErrorCasesTest, IncompleteLineThrowsParsingError) {
  stringstream in1 {"1\n00:00:10,345 --> 00:00:12,678\nTEXT\n\n2\n00:19:14,141 --> 00:17:20,100\nTT\n"};
  EXPECT_THROW(subs->ShiftAllSubtitlesBy(1000, 24, &in1, &out),InvalidSubtitleLineFormat);

  stringstream in2 {"1\n00:00:10,345 -> 00:00:12,678\nTEXT\n\n2\n00:19:14,141 --> 00:17:20,100\nTT\n"};
  EXPECT_THROW(subs->ShiftAllSubtitlesBy(1000, 24, &in2, &out),InvalidSubtitleLineFormat);

  stringstream in3 {"1\n00:00:10,345 00:00:12,678\nTEXT\n\n2\n00:19:14,141 --> 00:17:20,100\nTT\n"};
  EXPECT_THROW(subs->ShiftAllSubtitlesBy(1000, 24, &in3, &out),InvalidSubtitleLineFormat);

  stringstream in4 {"1\n0:00:10,345 --> 00:00:12,678\nTEXT\n\n2\n00:19:14,141 --> 00:17:20,100\nTT\n"};
  EXPECT_THROW(subs->ShiftAllSubtitlesBy(1000, 24, &in4, &out),InvalidSubtitleLineFormat);

  stringstream in5 {"1\n00:00:10,345 --> 00:00:12678\nTEXT\n\n2\n00:19:14,141 --> 00:17:20,100\nTT\n"};
  EXPECT_THROW(subs->ShiftAllSubtitlesBy(1000, 24, &in5, &out),InvalidSubtitleLineFormat);

  stringstream in6 {"1\n00:00:10,345 --> 00:00:12,678\nTEXT\n\n2\n00:19:14,141 --> 0:17:20,100\nTT\n"};
  EXPECT_THROW(subs->ShiftAllSubtitlesBy(1000, 24, &in6, &out),InvalidSubtitleLineFormat);

  stringstream in7 {"1\nTEXT\n\n2\n00:19:14,141 --> 0:17:20,100\nTT\n"};
  EXPECT_THROW(subs->ShiftAllSubtitlesBy(1000, 24, &in7, &out),MissingTimeSpecification);
}

TEST_F(SubRipErrorCasesTest, NegativeFrameRateThrowsIlegalArgument) {
  stringstream in;
  EXPECT_THROW(subs->ShiftAllSubtitlesBy(100, -10, &in, &out),std::invalid_argument);
}

TEST_F(SubRipErrorCasesTest, OutOfOrderFramesThrowsException) {
  stringstream in {"1\n00:00:10,345 --> 00:00:12,678\nTEXT\n\n4\n00:19:14,141 --> 00:21:20,100\nTT\n"};
  EXPECT_THROW(subs->ShiftAllSubtitlesBy(-1140, 25, &in, &out),OutOfOrderFrames);
}
