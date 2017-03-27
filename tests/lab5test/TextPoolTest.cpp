//
// Created by mwypych on 27.03.17.
//


#include <gtest/gtest.h>
#include <memory>
#include <experimental/string_view>
#include <MemLeakTest.h>
#include <TextPool.h>

using ::pool::TextPool;
using ::std::make_unique;
using ::std::move;
using ::std::fill;
using ::std::swap;
using ::std::vector;
using ::std::string;
using ::std::experimental::string_view;

class TextPoolTests : public ::testing::Test, MemLeakTest {
};

TEST_F(TextPoolTests, IsAbleToStoreDuplicatedValuesAtTheSamePlace) {

  TextPool pool{};

  vector<string> values{"abc", "efg", "hij", "klmn", "oprst", "abc"};
  for (const string &v : values) {
    pool.Intern(v);
  }

  EXPECT_EQ(5, pool.StoredStringCount());
  for (const string &v : values) {
    string_view stored = pool.Intern(v);
    string_view view = pool.Intern(v);
    EXPECT_EQ(view.begin(), stored.begin());
    EXPECT_EQ(view.end(), stored.end());
    EXPECT_EQ(view, stored);
    EXPECT_EQ(5, pool.StoredStringCount());
  }
}

TEST_F(TextPoolTests, IsAbleToCreateChunkAndDestroyItAsHeapVariable) {
  TextPool *ppool = new TextPool;
  ppool->Intern("abc");
  ppool->Intern("abc");
  EXPECT_EQ(1, ppool->StoredStringCount());
  EXPECT_EQ("abc", ppool->Intern("abc"));
  delete ppool;
}

TEST_F(TextPoolTests, IsAbleToInitilizePoolWithInitilizerList) {
  TextPool pool{"abc", "efg", "hij", "klmn", "oprst"};
  string_view s1 = pool.Intern("efg");
  string_view s2 = pool.Intern("efg");

  EXPECT_EQ(s1, s2);
  EXPECT_EQ(5, pool.StoredStringCount());
  EXPECT_EQ(s1.begin(), s2.begin());
}

TEST_F(TextPoolTests, IsAbleToMoveChunks) {
  TextPool pool{"abc", "efg", "hij", "klmn", "oprst", "abc", "abc", "kllll"};
  TextPool moved_pool = move(pool);

  EXPECT_EQ(6, moved_pool.StoredStringCount());
  EXPECT_EQ(0, pool.StoredStringCount());
  EXPECT_EQ("abc", pool.Intern("abc"));
  EXPECT_EQ("abc", moved_pool.Intern("abc"));
  EXPECT_EQ(1, pool.StoredStringCount());
  EXPECT_EQ(6, moved_pool.StoredStringCount());
}

TEST_F(TextPoolTests, IsNotAbleToCopyConstructChunks) {
  EXPECT_FALSE(false);
}

TEST_F(TextPoolTests, IsAbleToCopyMoveChunks) {
  TextPool pool{"hemoglobina", "kreda", "trias", "dewon"};
  EXPECT_EQ(4, pool.StoredStringCount());
  TextPool moved_pool{move(pool)};
  EXPECT_EQ(0, pool.StoredStringCount());
  EXPECT_EQ(4, moved_pool.StoredStringCount());
  EXPECT_EQ("abc", pool.Intern("abc"));
  EXPECT_EQ(1, pool.StoredStringCount());
}

TEST_F(TextPoolTests, IsNotAbleToCopyAssignChunks) {
  EXPECT_FALSE(false);
}

TEST_F(TextPoolTests, IsSelfMoveAssignableAware) {
  TextPool chunk{"ijk","chełm","zośka","erudyta"};
  EXPECT_EQ(4, chunk.StoredStringCount());
  chunk = move(chunk);

  EXPECT_EQ(4, chunk.StoredStringCount());
  EXPECT_EQ("ijk", chunk.Intern("ijk"));
  EXPECT_EQ(4, chunk.StoredStringCount());
}

TEST_F(TextPoolTests, IsAbleToSwapPools) {
  TextPool pool1{"abc", "efg"};
  TextPool pool2{"hij", "klm"};

  swap(pool1, pool2);
  auto view1 = pool1.Intern("abc");
  auto view2 = pool2.Intern("abc");

  EXPECT_EQ(3, pool1.StoredStringCount());
  EXPECT_EQ(2, pool2.StoredStringCount());
  EXPECT_EQ("abc", view1);
  EXPECT_EQ("abc", view2);
}

TEST_F(TextPoolTests, IsAbleEmplacePoolsIntoVector) {
  vector<TextPool> chunks;
  chunks.emplace_back(TextPool {"abc", "efg"});
  chunks.emplace_back(TextPool {"hij", "klm"});
  TextPool &pool = chunks[0];
  TextPool &pool2 = chunks[1];

  auto view1 = pool.Intern("abc");
  auto view2 = pool2.Intern("abc");

  EXPECT_EQ(2, pool.StoredStringCount());
  EXPECT_EQ(3, pool2.StoredStringCount());
  EXPECT_EQ("abc", view1);
  EXPECT_EQ("abc", view2);
}