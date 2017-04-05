//
// Created by mwypych on 04.04.17.
//

#include <gtest/gtest.h>
#include <memory>
#include <type_traits>
#include <MemLeakTest.h>
#include <StudentRepository.h>

using ::academia::StudyYear;
using ::std::make_unique;
using ::std::move;
using ::std::fill;
using ::std::swap;
using ::std::vector;
using ::std::string;

class StudentRepositoryStudyYearTests : public ::testing::Test, MemLeakTest {
};

TEST_F(StudentRepositoryStudyYearTests, IsAbleToCreateDefaultStudyYear) {

  StudyYear year{};

  EXPECT_EQ(1, year);

}

TEST_F(StudentRepositoryStudyYearTests, IsAbleToCompateTwoYears) {

  StudyYear year{};
  StudyYear year2{2};

  EXPECT_LT(year, year2);

}