//
// Created by mwypych on 04.04.17.
//
#include <gtest/gtest.h>
#include <memory>
#include <type_traits>
#include <MemLeakTest.h>
#include <StudentRepository.h>

using ::academia::StudentRepository;
using ::academia::StudyYear;
using ::academia::Student;
using ::std::make_unique;
using ::std::move;
using ::std::fill;
using ::std::swap;
using ::std::vector;
using ::std::string;

class StudentRepositoryTests : public ::testing::Test, MemLeakTest {
};

TEST_F(StudentRepositoryTests, IsAbleToCreateEmptyRepository) {

  StudentRepository repository{};

  EXPECT_EQ(0, repository.StudentCount());

}

TEST_F(StudentRepositoryTests, IsAbleToInitlizeRepositoryByInilizerList) {

  StudentRepository repository
      {{"2030", "Michał", "Karak", "architektura", 5}, {"2031", "Katarzyna", "Bach", "informatyka", 3},
       {"2035", "Orson", "Sabach", "górnictwo", 2}};

  EXPECT_EQ(3, repository.StudentCount());

}

TEST_F(StudentRepositoryTests, IsAbleToRetriveStudentById) {

  StudentRepository repository
      {{"2030", "Michał", "Karak", "architektura", 5}, {"2031", "Katarzyna", "Bach", "informatyka", 3},
       {"2035", "Orson", "Sabach", "górnictwo", 2}};

  EXPECT_EQ("2031", repository["2031"].Id());
  EXPECT_EQ("Katarzyna", repository["2031"].FirstName());
  EXPECT_EQ("Bach", repository["2031"].LastName());
  EXPECT_EQ("informatyka", repository["2031"].Program());
  EXPECT_EQ(StudyYear {3}, repository["2031"].Year());
  EXPECT_EQ(3, static_cast<int>(repository["2031"].Year()));

}

TEST_F(StudentRepositoryTests, IsAbleToRetriveStudentByIdAndModifyItsStateInRepository) {

  StudentRepository repository
      {{"2030", "Michał", "Karak", "architektura", 5}, {"2031", "Katarzyna", "Bach", "informatyka", 3},
       {"2035", "Orson", "Sabach", "górnictwo", 2}};

  EXPECT_EQ("2035", repository["2035"].Id());
  EXPECT_EQ("Orson", repository["2035"].FirstName());
  EXPECT_EQ("Sabach", repository["2035"].LastName());
  EXPECT_EQ("górnictwo", repository["2035"].Program());
  EXPECT_EQ(StudyYear {2}, repository["2035"].Year());
  EXPECT_EQ(2, static_cast<int>(repository["2035"].Year()));

  repository["2035"].ChangeLastName("Sabak");

  EXPECT_EQ("2035", repository["2035"].Id());
  EXPECT_EQ("Orson", repository["2035"].FirstName());
  EXPECT_EQ("Sabak", repository["2035"].LastName());
  EXPECT_EQ("górnictwo", repository["2035"].Program());
  EXPECT_EQ(StudyYear {2}, repository["2035"].Year());
  EXPECT_EQ(2, static_cast<int>(repository["2035"].Year()));

}


TEST_F(StudentRepositoryTests, IsAbleToCompateTwoRepositories) {

  StudentRepository repository
      {{"2030", "Michał", "Karak", "architektura", 5}, {"2031", "Katarzyna", "Bach", "informatyka", 3},
       {"2035", "Orson", "Sabach", "górnictwo", 2}};

  StudentRepository copy
      {{"2035", "Orson", "Sabach", "górnictwo", 2}, {"2031", "Katarzyna", "Bach", "informatyka", 3},
       {"2030", "Michał", "Karak", "architektura", 5}};

  EXPECT_EQ(copy, repository);
  EXPECT_EQ(copy["2035"], repository["2035"]);
  EXPECT_EQ(copy["2031"], repository["2031"]);
  EXPECT_EQ(copy["2030"], repository["2030"]);

}
