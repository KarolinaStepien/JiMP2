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
using ::moviesubs::SubRipSubtitles;
using ::moviesubs::MovieSubtitles;

using namespace std;
using namespace std::literals;

class MovieSubtitlesTests : public ::testing::Test, MemLeakTest {
 public:
};

TEST_F(MovieSubtitlesTests, MicroDvdHasBaseClassOfMovieSubtitles) {
  unique_ptr<MovieSubtitles> subs = make_unique<MicroDvdSubtitles>();
  stringstream in {"{0}{250}TEXT\n{260}{300}NEWLINE\n"};
  stringstream out;
  subs->ShiftAllSubtitlesBy(300, 25, &in, &out);
  EXPECT_EQ("{7}{257}TEXT\n{267}{307}NEWLINE\n"s,out.str());
}

TEST_F(MovieSubtitlesTests, SubRipHasBaseClassOfMovieSubtitles) {
  unique_ptr<MovieSubtitles> subs = make_unique<SubRipSubtitles>();
  stringstream in {"1\n00:05:54,555 --> 00:05:56,722\nText\n\n2\n00:06:06,433 --> 00:06:07,801\nNEWLINE\n"};
  stringstream out;
  EXPECT_NO_THROW(subs->ShiftAllSubtitlesBy(300, 24, &in, &out));
  EXPECT_EQ("1\n00:05:54,855 --> 00:05:57,022\nText\n\n2\n00:06:06,733 --> 00:06:08,101\nNEWLINE\n"s,out.str());
}
