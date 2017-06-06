//
// Created by mwypych on 25.05.17.
//
#include <string>
#include <unordered_map>
#include <gtest/gtest.h>
#include <MemLeakTest.h>
#include "TeacherHash.h"

using ::academia::Teacher;
using ::academia::TeacherId;
using ::academia::TeacherHash;
using ::std::literals::string_literals::operator""s;


class TeacherHashTest : public ::testing::Test, MemLeakTest {
 public:
};


TEST_F(TeacherHashTest, CanCreateTeacherIdCastableToInt) {
  TeacherId id (1002);
  int casted_id = id;
  EXPECT_EQ(1002, casted_id);
  EXPECT_EQ(1002, id);
}

TEST_F(TeacherHashTest, CanCompareDifferentTeacherIdsAndReturnsFalse) {
  TeacherId id1 (300);
  TeacherId id2 (347);
  EXPECT_NE(id1, id2);
}

TEST_F(TeacherHashTest, CanCompareSameTeacherIdsAndReturnsTrue) {
  TeacherId id1 (612);
  TeacherId id2 (612);
  EXPECT_EQ(id1, id2);
}

TEST_F(TeacherHashTest, CanCreateTeacherWithSpecifiedFields) {
  Teacher s1 = Teacher (TeacherId (1002), "Alozjzy", "Katedra Informatyki");
  EXPECT_EQ((TeacherId(1002)), s1.Id());
  EXPECT_EQ("Alozjzy"s, s1.Name());
  EXPECT_EQ("Katedra Informatyki"s, s1.Department());
}

TEST_F(TeacherHashTest, CanCompareSameTeachersAndReturnsTrue) {
  Teacher s1 = Teacher (TeacherId (1002), "Alozjzy", "Katedra Informatyki");
  Teacher s2 = Teacher (TeacherId (1002), "Alozjzy", "Katedra Informatyki");
  EXPECT_EQ(s1, s2);
}

TEST_F(TeacherHashTest, CanCalculateHashOfTeacherUsingStructWithRedefinedFunctionCallOperator) {
  Teacher s1 = Teacher (TeacherId (1002), "Alozjzy", "Katedra Informatyki");
  const TeacherHash hash {};
  size_t hash_value = hash(s1);
  EXPECT_NE(0, hash_value);
  EXPECT_NE(0, hash(s1));
}

TEST_F(TeacherHashTest, EveryHashCalculationGiveSameResult) {
  Teacher s1 = Teacher (TeacherId (1002), "Alozjzy", "Katedra Informatyki");
  const TeacherHash hash {};
  size_t hash_value = hash(s1);
  EXPECT_NE(0, hash_value);

  size_t hash_value2 = hash(s1);
  EXPECT_EQ(hash_value2, hash_value);
}

TEST_F(TeacherHashTest, SameTeachersHasEqualHashes) {
  Teacher s1 = Teacher (TeacherId (1002), "Alozjzy", "Katedra Informatyki");
  Teacher s2 = Teacher (TeacherId (1002), "Alozjzy", "Katedra Informatyki");
  const TeacherHash hash {};
  EXPECT_EQ(s1, s2);
  EXPECT_EQ(hash(s1), hash(s2));
  //and again the same result
  EXPECT_EQ(hash(s1), hash(s2));
}

TEST_F(TeacherHashTest, DifferentTeachersHasUsuallyHaveDifferentHashes) {
  Teacher s1 = Teacher (TeacherId (1002), "Alozjzy", "Katedra Informatyki");
  Teacher s2 = Teacher (TeacherId (1003), "Euzebiusz", "Katedra Automatyki");
  const TeacherHash hash {};
  EXPECT_NE(s1, s2);
  EXPECT_NE(hash(s1), hash(s2));
}

TEST_F(TeacherHashTest, AlmostEqualTeachersHasUsuallyHaveDifferentHashesToo) {
  Teacher s1 = Teacher (TeacherId (1002), "Alozjzy", "Katedra Informatyki");
  Teacher s2 = Teacher (TeacherId (1002), "Alozjzy", "Katedra InFormatyki");
  Teacher s3 = Teacher (TeacherId (1003), "Alozjzy", "Katedra Informatyki");
  Teacher s4 = Teacher (TeacherId (1002), "alozjzy", "Katedra Informatyki");
  const TeacherHash hash {};
  EXPECT_NE(s1, s2);
  EXPECT_NE(s1, s3);
  EXPECT_NE(s1, s4);
  EXPECT_NE(s2, s3);
  EXPECT_NE(s2, s4);
  EXPECT_NE(s3, s4);
  EXPECT_NE(hash(s1), hash(s2));
  EXPECT_NE(hash(s1), hash(s3));
  EXPECT_NE(hash(s1), hash(s4));
  EXPECT_NE(hash(s2), hash(s3));
  EXPECT_NE(hash(s2), hash(s4));
  EXPECT_NE(hash(s3), hash(s4));
}

TEST_F(TeacherHashTest, CanInsertTeachersAsKeysIntoUnorderedMap) {
  Teacher s1 = Teacher (TeacherId (1002), "Alozjzy", "Katedra Informatyki");
  Teacher s2 = Teacher (TeacherId (1002), "Alozjzy", "Katedra Informatyki");
  Teacher s3 = Teacher (TeacherId (1017), "Klaudiusz", "Katedra Elektroniki");
  const TeacherHash hash {};
  std::unordered_map<Teacher, int, TeacherHash> m;
  m.emplace(s1, 100'000'000);
  m.emplace(s3, 98);

  EXPECT_EQ(2, m.size());
  EXPECT_EQ(100'000'000, m[s1]);
  EXPECT_EQ(100'000'000, m[s2]);
  EXPECT_EQ(98, m[s3]);
}


