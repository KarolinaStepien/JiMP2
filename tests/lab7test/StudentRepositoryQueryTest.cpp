//
// Created by mwypych on 10.04.17.
//

#include <gtest/gtest.h>
#include <vector>
#include <MemLeakTest.h>
#include <StudentRepository.h>
#include <StudentRepositoryQueries.h>

using ::academia::ByFirstName;
using ::academia::ByLastName;
using ::academia::ByOneOfPrograms;
using ::academia::ByYearLowerOrEqualTo;
using ::academia::OrQuery;
using ::academia::AndQuery;
using ::academia::StudentRepository;
using ::academia::Student;
using ::academia::StudyYear;

class StudentRepositoryQueryTest : public ::testing::Test, MemLeakTest {
 public:
  StudentRepository repository{
      Student {"1", "Marek", "Aureliusz", "filozofia", StudyYear {3}},
      Student {"2", "Albert", "Einstein", "muzyka", StudyYear{1}},
      Student {"3", "Niels", "Bohr", "fizyka", StudyYear{1}},
      Student {"4", "Ada", "Lovelace", "informatyka", StudyYear {4}},
      Student {"5", "Maria", "Gopert-Mayer", "fizyka", StudyYear {3}}};
};

TEST_F(StudentRepositoryQueryTest, QueryStudentByFirstName) {
  std::vector<Student> expected{repository["1"]};
  EXPECT_EQ(expected, repository.FindByQuery(ByFirstName {"Marek"}));
}

TEST_F(StudentRepositoryQueryTest, QueryStudentByLastName) {
  std::vector<Student> expected{repository["2"]};
  EXPECT_EQ(expected, repository.FindByQuery(ByLastName {"Einstein"}));
}

TEST_F(StudentRepositoryQueryTest, QueryStudentByOneOfPrograms) {
  std::set<Student> expected{repository["2"],repository["4"],repository["5"]};
  std::vector<Student> result = repository.FindByQuery(ByOneOfPrograms {"informatyka","muzyka"});
  EXPECT_EQ(3, result.size());
  EXPECT_TRUE(expected.find(result.at(0)) != expected.end());
  EXPECT_TRUE(expected.find(result.at(1)) != expected.end());
  EXPECT_TRUE(expected.find(result.at(2)) != expected.end());
}

TEST_F(StudentRepositoryQueryTest, QueryStudentByYearLowerOrEqualTo) {
  std::set<Student> expected{repository["2"],repository["1"],repository["4"],repository["5"]};
  std::vector<Student> result = repository.FindByQuery(ByYearLowerOrEqualTo {StudyYear{4}});
  EXPECT_EQ(4, result.size());
  EXPECT_TRUE(expected.find(result.at(0)) != expected.end());
  EXPECT_TRUE(expected.find(result.at(1)) != expected.end());
  EXPECT_TRUE(expected.find(result.at(2)) != expected.end());
  EXPECT_TRUE(expected.find(result.at(3)) != expected.end());
}

TEST_F(StudentRepositoryQueryTest, QueryStudentByFirstNameOrLastName) {
  std::set<Student> expected{repository["2"],repository["1"]};

  std::vector<Student> result = repository.FindByQuery(OrQuery {ByFirstName {"Albert"}, ByLastName {"Aureliusz"}});
  EXPECT_EQ(2, result.size());
  EXPECT_TRUE(expected.find(result.at(0)) != expected.end());
  EXPECT_TRUE(expected.find(result.at(1)) != expected.end());
}

TEST_F(StudentRepositoryQueryTest, QueryStudentByFirstNameAndByYearLowerOrEqualTo) {
  std::set<Student> expected{repository["2"]};

  std::vector<Student> result = repository.FindByQuery(AndQuery {ByFirstName {"Albert"}, ByYearLowerOrEqualTo {StudyYear{3}}});
  EXPECT_EQ(1, result.size());
  EXPECT_TRUE(expected.find(result.at(0)) != expected.end());
}
