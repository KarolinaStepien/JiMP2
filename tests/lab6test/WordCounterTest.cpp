//
// Created by mwypych on 04.04.17.
//
#include <gtest/gtest.h>
#include <memory>
#include <set>
#include <MemLeakTest.h>
#include "WordCounter.h"

using ::datastructures::WordCounter;
using ::datastructures::Counts;
using ::datastructures::Word;
using ::std::set;


class WordCounterTests : public ::testing::Test, MemLeakTest {
};

TEST_F(WordCounterTests, IsAbleToCreateEmptyWordCounter) {
  WordCounter counter;
  EXPECT_EQ(0,counter.DistinctWords());
  EXPECT_EQ(0,counter.TotalWords());
}

TEST_F(WordCounterTests, IsAbleToInitilzeWordCounter) {
  WordCounter counter {Word("enigma"), Word("puzzle")};
  EXPECT_EQ(2,counter.DistinctWords());
  EXPECT_EQ(2,counter.TotalWords());
}

TEST_F(WordCounterTests, IsAbleToInitilzeWordCounterWithDuplicatedWords) {
  WordCounter counter {Word("a"), Word("p"), Word("a"), Word("a")};
  EXPECT_EQ(2,counter.DistinctWords());
  EXPECT_EQ(4,counter.TotalWords());
}

TEST_F(WordCounterTests, IsAbleToQueryWordsCounts) {
  WordCounter counter {Word("a"), Word("p"), Word("a"), Word("a")};
  EXPECT_EQ(Counts(3), counter["a"]);
  EXPECT_EQ(Counts(1), counter["p"]);
}


TEST_F(WordCounterTests, IsAbleToQueryNotPreviouslyStoredWord) {
  WordCounter counter;
  EXPECT_EQ(0, counter["abc"]);
  EXPECT_EQ(0, counter.DistinctWords());
  EXPECT_EQ(0, counter.TotalWords());
}

TEST_F(WordCounterTests, IsAbleListWords) {
  WordCounter counter {Word("a"), Word("p"), Word("a"), Word("a"), Word("hi"), Word("voltage")};
  set<Word> expected_words {Word("a"),Word("hi"), Word("voltage"), Word("p")};
  set<int> ii {1, 56, 3,4};
  set<int> ij {1, 56,4,3};
  EXPECT_EQ(ii,ij);
  EXPECT_EQ(expected_words, counter.Words());
}

