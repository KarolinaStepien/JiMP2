//
// Created by mwypych on 08.05.17.
//

#include <gmock/gmock.h>
#include <string>
#include <memory>
#include <functional>
#include <vector>
#include <stdexcept>
#include <sstream>
#include <MemLeakTest.h>
#include <Serialization.h>

using ::academia::Building;
using ::academia::Room;
using ::academia::Serializer;
using ::academia::Serializable;
using ::academia::XmlSerializer;
using ::academia::JsonSerializer;
using ::academia::BuildingRepository;


using namespace std;
using namespace std::literals;

using ::testing::_;
using ::testing::IsEmpty;
using ::testing::SizeIs;

class MockSerializer : public Serializer {
 public:
  MockSerializer() : Serializer{&std::cout} {}
  MOCK_METHOD2(IntegerField, void(
      const std::string &field_name,
      int value));
  MOCK_METHOD2(DoubleField, void(
      const std::string &field_name,
      double value));
  MOCK_METHOD2(StringField, void(
      const std::string &field_name,
      const std::string &value));
  MOCK_METHOD2(BooleanField, void(
      const std::string &field_name,
      bool value));
  MOCK_METHOD2(SerializableField, void(
      const std::string &field_name,
      const Serializable &value));
  MOCK_METHOD2(ArrayField, void(
      const std::string &field_name,
      const std::vector<std::reference_wrapper<const Serializable>> &value));
  MOCK_METHOD1(Header, void(
      const std::string &object_name));
  MOCK_METHOD1(Footer, void(
      const std::string &object_name));
};

class BuildingRepositoryTest : public ::testing::Test, protected MemLeakTest {
 public:
  void ExpectSingleSerializationWithArrayFieldOfEmptyVector(MockSerializer *serializer);
  void ExpectSingleSerializationWithArrayFieldOfVectorOfSize(size_t expected_size, MockSerializer *serializer);
};

TEST_F(BuildingRepositoryTest, IsAbleToCreateEmptyBuildingRepositoryAndSaveIt) {
  BuildingRepository repository{};
  MockSerializer serializer;
  std::vector<std::reference_wrapper<const Serializable>> empty;

  ExpectSingleSerializationWithArrayFieldOfEmptyVector(&serializer);

  repository.StoreAll(&serializer);
}

TEST_F(BuildingRepositoryTest, IsAbleToCreateInitializedWithSingleValueBuildingRepositoryAndSaveIt) {
  BuildingRepository repository{Building {101, "B-1", {Room {101301, "H-24", Room::Type::LECTURE_HALL},
                                                       Room {102683, "021", Room::Type::COMPUTER_LAB}}}};
  MockSerializer serializer;

  ExpectSingleSerializationWithArrayFieldOfVectorOfSize(1, &serializer);

  repository.StoreAll(&serializer);
}

TEST_F(BuildingRepositoryTest, IsAbleToCreateBuildingRepositoryAddSingleValueAndSaveIt) {

  BuildingRepository repository{};
  Building
      b1{101, "B-1", {Room {101301, "H-24", Room::Type::LECTURE_HALL}, Room {102683, "021", Room::Type::COMPUTER_LAB}}};
  MockSerializer serializer;

  ExpectSingleSerializationWithArrayFieldOfVectorOfSize(1, &serializer);

  repository.Add(b1);

  repository.StoreAll(&serializer);
}

TEST_F(BuildingRepositoryTest, IsAbleToCreateBuildingRepositoryWith3BuildingsAndSaveIt) {

  BuildingRepository repository{};
  Building
      b1{101, "B-1", {Room {101301, "H-24", Room::Type::LECTURE_HALL}, Room {102683, "021", Room::Type::COMPUTER_LAB}}};
  Building b2{102, "B-2", {}};
  Building c2{103, "C-2", {Room {100110, "208", Room::Type::COMPUTER_LAB}}};
  MockSerializer serializer;

  ExpectSingleSerializationWithArrayFieldOfVectorOfSize(3, &serializer);

  repository.Add(b1);
  repository.Add(b2);
  repository.Add(c2);

  repository.StoreAll(&serializer);
}

TEST_F(BuildingRepositoryTest, IsAbleToCreateBuildingRepositoryWith3BuildingsAndSaveIntoXML) {

  BuildingRepository repository{};
  Building
      b1{101, "B-1", {Room {101301, "H-24", Room::Type::LECTURE_HALL}, Room {102683, "021", Room::Type::COMPUTER_LAB}}};
  Building b2{102, "B-2", {}};
  Building c2{103, "C-2", {Room {100110, "208", Room::Type::COMPUTER_LAB}}};
  std::stringstream out;
  XmlSerializer serializer{&out};

  repository.Add(b1);
  repository.Add(b2);
  repository.Add(c2);

  repository.StoreAll(&serializer);
  EXPECT_EQ(
      "<building_repository>"
        "<buildings>"
          "<building><id>101<\\id><name>B-1<\\name>"
            "<rooms>"
              "<room><id>101301<\\id><name>H-24<\\name><type>LECTURE_HALL<\\type><\\room>"
              "<room><id>102683<\\id><name>021<\\name><type>COMPUTER_LAB<\\type><\\room>"
            "<\\rooms>"
          "<\\building>"
          "<building><id>102<\\id><name>B-2<\\name>"
            "<rooms><\\rooms>"
          "<\\building>"
          "<building><id>103<\\id><name>C-2<\\name>"
            "<rooms>"
              "<room><id>100110<\\id><name>208<\\name><type>COMPUTER_LAB<\\type><\\room>"
            "<\\rooms>"
          "<\\building>"
        "<\\buildings>"
      "<\\building_repository>"s,
      out.str());
}

TEST_F(BuildingRepositoryTest, IsAbleToCreateBuildingRepositoryWith3BuildingsAndSaveIntoJson) {

  BuildingRepository repository{};
  Building
      b1{101, "B-1", {Room {101301, "H-24", Room::Type::LECTURE_HALL}, Room {102683, "021", Room::Type::COMPUTER_LAB}}};
  Building b2{102, "B-2", {}};
  Building c2{103, "C-2", {Room {100110, "208", Room::Type::COMPUTER_LAB}}};
  std::stringstream out;
  JsonSerializer serializer{&out};

  repository.Add(b1);
  repository.Add(b2);
  repository.Add(c2);

  repository.StoreAll(&serializer);
  EXPECT_EQ(
      "{\"buildings\": "
        "[{\"id\": 101, \"name\": \"B-1\", "
          "\"rooms\": "
            "[{\"id\": 101301, \"name\": \"H-24\", \"type\": \"LECTURE_HALL\"}, "
            "{\"id\": 102683, \"name\": \"021\", \"type\": \"COMPUTER_LAB\"}]}, "
        "{\"id\": 102, \"name\": \"B-2\", "
          "\"rooms\": "
            "[]}, "
        "{\"id\": 103, \"name\": \"C-2\", "
          "\"rooms\": "
            "[{\"id\": 100110, \"name\": \"208\", \"type\": \"COMPUTER_LAB\"}]}]}"s,
      out.str());
}

TEST_F(BuildingRepositoryTest, OneCanAccessBuildingsInsideRepositoryWithBracketOperator) {

  BuildingRepository repository{};
  Building
      b1{101, "B-1", {Room {101301, "H-24", Room::Type::LECTURE_HALL}, Room {102683, "021", Room::Type::COMPUTER_LAB}}};
  Building b2{102, "B-2", {}};
  Building c2{103, "C-2", {Room {100110, "208", Room::Type::COMPUTER_LAB}}};

  repository.Add(b1);
  repository.Add(b2);
  repository.Add(c2);

  std::experimental::optional<Building> ob1 = repository[101];

  Building &b1_ref = ob1.value();

  EXPECT_EQ(101, b1_ref.Id());
  EXPECT_EQ(102, repository[102].value().Id());
  EXPECT_EQ(103, repository[103].value().Id());
}

TEST_F(BuildingRepositoryTest, OneCanAccessBuildingsInsideRepositoryWithConstBracketOperator) {

  BuildingRepository repository{};
  Building
      b1{101, "B-1", {Room {101301, "H-24", Room::Type::LECTURE_HALL}, Room {102683, "021", Room::Type::COMPUTER_LAB}}};
  Building b2{102, "B-2", {}};
  Building c2{103, "C-2", {Room {100110, "208", Room::Type::COMPUTER_LAB}}};

  repository.Add(b1);
  repository.Add(b2);
  repository.Add(c2);

  const BuildingRepository &const_repository = repository;

  std::experimental::optional<Building> ob1 = const_repository[101];

  EXPECT_EQ(101, ob1.value().Id());
  EXPECT_EQ(102, repository[102].value().Id());
  EXPECT_EQ(103, repository[103].value().Id());
}

void BuildingRepositoryTest::ExpectSingleSerializationWithArrayFieldOfEmptyVector(MockSerializer *serializer) {
  this->StopRecording();
  ::testing::InSequence in_sequence;
  EXPECT_CALL(*serializer, Header("building_repository")).Times(1);
  EXPECT_CALL(*serializer, ArrayField("buildings", IsEmpty())).Times(1);
  EXPECT_CALL(*serializer, Footer("building_repository")).Times(1);
  this->ResumeRecording();
}

void BuildingRepositoryTest::ExpectSingleSerializationWithArrayFieldOfVectorOfSize(size_t expected_size,
                                                                                   MockSerializer *serializer) {
  this->StopRecording();
  ::testing::InSequence in_sequence;
  EXPECT_CALL(*serializer, Header("building_repository")).Times(1);
  EXPECT_CALL(*serializer, ArrayField("buildings", SizeIs(expected_size))).Times(1);
  EXPECT_CALL(*serializer, Footer("building_repository")).Times(1);
  this->ResumeRecording();
}
