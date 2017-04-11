//
// Created by mwypych on 11.04.17.
//

#include <gtest/gtest.h>
#include <vector>
#include <MemLeakTest.h>
#include <StudyYear.h>
#include <Student.h>
#include <StudentRepositoryQueries.h>

using ::academia::ByFirstName;
using ::academia::Student;
using ::academia::StudyYear;

class StudentRepositoryQueryByFirstNameTest : public ::testing::Test, MemLeakTest {
};

TEST_F(StudentRepositoryQueryByFirstNameTest, QueryIsBuildable) {
  ByFirstName query {"Marek"};
}

TEST_F(StudentRepositoryQueryByFirstNameTest, QueryIsQueriable) {
  ByFirstName query {"Marek"};
  Student marek {"1", "Marek", "Aureliusz", "filozofia", StudyYear {3}};
  Student albert {"2", "Albert", "Einstein", "muzyka", StudyYear{1}};
  EXPECT_TRUE(query.Accept(marek));
  EXPECT_FALSE(query.Accept(albert));
}
