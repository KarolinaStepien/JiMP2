//
// Created by mwypych on 04.04.17.
//
#include <gtest/gtest.h>
#include <memory>
#include <type_traits>
#include <MemLeakTest.h>
#include <StudentRepository.h>

using ::academia::StudyYear;
using ::academia::Student;
using ::std::make_unique;
using ::std::move;
using ::std::fill;
using ::std::swap;
using ::std::vector;
using ::std::string;

class StudentRepositoryStudentTests : public ::testing::Test, MemLeakTest {
};

TEST_F(StudentRepositoryStudentTests, IsAbleToCreateDefaultStudent) {

  Student student{};

  EXPECT_EQ("", student.Id());

}

TEST_F(StudentRepositoryStudentTests, IsAbleToCreateNonDefaultStudent) {

  Student s {"2031", "Katarzyna", "Bach", "informatyka", 3};
  Student s2 {"2035", "Orson", "Sabach", "górnictwo", 2};

  EXPECT_EQ("2031", s.Id());
  EXPECT_EQ("Katarzyna", s.FirstName());
  EXPECT_EQ("Bach", s.LastName());
  EXPECT_EQ("informatyka", s.Program());
  EXPECT_EQ(StudyYear {3}, s.Year());

}

TEST_F(StudentRepositoryStudentTests, IsAbleToCompateTwoStudents) {

  Student s {"2035", "Orson", "Sabach", "górnictwo", 2};
  Student s2 {"2035", "Orson", "Sabach", "górnictwo", 2};

  EXPECT_EQ(s2, s);

}

TEST_F(StudentRepositoryStudentTests, IsAbleToModifyLastNameAfterCreation) {

  Student s2 {"2035", "Orson", "Sabach", "górnictwo", 2};

  s2.ChangeLastName("Nowe nazwisko");
  EXPECT_EQ("Nowe nazwisko", s2.LastName());
}
