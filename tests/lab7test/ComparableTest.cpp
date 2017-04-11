//
// Created by mwypych on 10.04.17.
//

#include <gtest/gtest.h>
#include <vector>
#include <MemLeakTest.h>
#include <Comparable.h>

using ::academia::ByFirstNameAscending;
using ::academia::ByFirstNameDescending;
using ::academia::ByLastNameAscending;
using ::academia::ByProgramAscendingEmptyFirst;
using ::academia::ByProgramAscendingEmptyLast;
using ::academia::Student;
using ::academia::StudyYear;


class ComparableTests : public ::testing::Test, MemLeakTest {
 public:
  std::vector<Student> test_students {
      Student {"1","Marek","Aureliusz","filozofia",StudyYear {3}},
      Student {"2","Albert","Einstein","muzyka",StudyYear{1}},
      Student {"3","Niels","Bohr","fizyka",StudyYear{1}},
      Student {"4","Ada","Lovelace","informatyka",StudyYear {4}},
      Student {"5", "Maria","Gopert-Mayer","fizyka",StudyYear {3}}};
};

TEST_F(ComparableTests, CompareStudentsByFirstNameAscending) {
  ByFirstNameAscending cmp;
  EXPECT_TRUE(cmp.IsLess(test_students[0],test_students[2]));
  EXPECT_TRUE(cmp(test_students[0],test_students[2]));

  EXPECT_TRUE(cmp.IsLess(test_students[1],test_students[4]));
  EXPECT_TRUE(cmp(test_students[1],test_students[4]));

  EXPECT_TRUE(cmp.IsLess(test_students[4],test_students[2]));
  EXPECT_TRUE(cmp(test_students[4],test_students[2]));
}

TEST_F(ComparableTests, CompareStudentsByFirstNameDescending) {
  ByFirstNameDescending cmp;
  EXPECT_FALSE(cmp.IsLess(test_students[0],test_students[2]));
  EXPECT_FALSE(cmp(test_students[0],test_students[2]));

  EXPECT_FALSE(cmp.IsLess(test_students[1],test_students[4]));
  EXPECT_FALSE(cmp(test_students[1],test_students[4]));

  EXPECT_FALSE(cmp.IsLess(test_students[4],test_students[2]));
  EXPECT_FALSE(cmp(test_students[4],test_students[2]));
}

TEST_F(ComparableTests, CompareStudentsByLastNameAscending) {
  ByLastNameAscending cmp;
  EXPECT_TRUE(cmp.IsLess(test_students[0],test_students[2]));
  EXPECT_TRUE(cmp(test_students[0],test_students[2]));

  EXPECT_TRUE(cmp.IsLess(test_students[1],test_students[4]));
  EXPECT_TRUE(cmp(test_students[1],test_students[4]));

  EXPECT_FALSE(cmp.IsLess(test_students[4],test_students[2]));
  EXPECT_FALSE(cmp(test_students[4],test_students[2]));
}

TEST_F(ComparableTests, CompareStudentsByProgramAscendingEmptyFirst) {
  ByProgramAscendingEmptyFirst cmp;
  EXPECT_TRUE(cmp.IsLess(test_students[0],test_students[2]));
  EXPECT_TRUE(cmp(test_students[0],test_students[2]));

  EXPECT_FALSE(cmp.IsLess(test_students[1],test_students[4]));
  EXPECT_FALSE(cmp(test_students[1],test_students[4]));

  EXPECT_FALSE(cmp.IsLess(test_students[4],test_students[2]));
  EXPECT_FALSE(cmp(test_students[4],test_students[2]));

  EXPECT_FALSE(cmp.IsLess(test_students[2],test_students[4]));
  EXPECT_FALSE(cmp(test_students[2],test_students[4]));

  Student emptyProgramStudnet {"45","Elizabeth","Blackburn","",StudyYear{}};
  for (const Student &student : test_students) {
    EXPECT_TRUE(cmp.IsLess(emptyProgramStudnet,student));
    EXPECT_TRUE(cmp(emptyProgramStudnet,student));
  }
}

TEST_F(ComparableTests, CompareStudentsByProgramAscendingEmptyLast) {
  ByProgramAscendingEmptyLast cmp;
  EXPECT_TRUE(cmp.IsLess(test_students[0],test_students[2]));
  EXPECT_TRUE(cmp(test_students[0],test_students[2]));

  EXPECT_FALSE(cmp.IsLess(test_students[1],test_students[4]));
  EXPECT_FALSE(cmp(test_students[1],test_students[4]));

  EXPECT_FALSE(cmp.IsLess(test_students[4],test_students[2]));
  EXPECT_FALSE(cmp(test_students[4],test_students[2]));

  EXPECT_FALSE(cmp.IsLess(test_students[2],test_students[4]));
  EXPECT_FALSE(cmp(test_students[2],test_students[4]));

  Student emptyProgramStudnet {"45","Elizabeth","Blackburn","",StudyYear{}};
  for (const Student &student : test_students) {
    EXPECT_FALSE(cmp.IsLess(emptyProgramStudnet,student));
    EXPECT_FALSE(cmp(emptyProgramStudnet,student));
  }
  EXPECT_FALSE(cmp.IsLess(emptyProgramStudnet, emptyProgramStudnet));
}