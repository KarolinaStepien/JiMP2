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

};

TEST_F(BuildingRepositoryTest, IsAbleToCreateEmptyBuildingRepositoryAndSaveIt) {
  BuildingRepository repository{};
  MockSerializer serializer;
  std::vector<std::reference_wrapper<const Serializable>> empty;

  this->StopRecording();
  EXPECT_CALL(serializer, ArrayField("building_repository", IsEmpty()));
  this->ResumeRecording();
  repository.StoreAll(&serializer);
}

TEST_F(BuildingRepositoryTest, IsAbleToCreateInitializedWithSingleValueBuildingRepositoryAndSaveIt) {
  BuildingRepository repository{Building {101, "B-1", {Room {101301, "H-24", Room::Type::LECTURE_HALL},
                                                       Room {102683, "021", Room::Type::COMPUTER_LAB}}}};
  MockSerializer serializer;

  this->StopRecording();
  EXPECT_CALL(serializer, ArrayField("building_repository", SizeIs(1)));
  this->ResumeRecording();

  repository.StoreAll(&serializer);
}

TEST_F(BuildingRepositoryTest, IsAbleToCreateBuildingRepositoryAddSingleValueAndSaveIt) {

  BuildingRepository repository{};
  Building
      b1{101, "B-1", {Room {101301, "H-24", Room::Type::LECTURE_HALL}, Room {102683, "021", Room::Type::COMPUTER_LAB}}};
  MockSerializer serializer;

  this->StopRecording();
  EXPECT_CALL(serializer, ArrayField("building_repository", SizeIs(1)));
  this->ResumeRecording();

  repository.Add(b1);

  repository.StoreAll(&serializer);
}


TEST_F(BuildingRepositoryTest, IsAbleToCreateBuildingRepositoryWith3BuildingsAndSaveIt) {

  BuildingRepository repository{};
  Building
      b1{101, "B-1", {Room {101301, "H-24", Room::Type::LECTURE_HALL}, Room {102683, "021", Room::Type::COMPUTER_LAB}}};
  Building b2 {102, "B-2", {}};
  Building c2 {103, "C-2", {Room {100110,"208",Room::Type::COMPUTER_LAB}}};
  MockSerializer serializer;

  this->StopRecording();
  EXPECT_CALL(serializer, ArrayField("building_repository", SizeIs(3)));
  this->ResumeRecording();

  repository.Add(b1);
  repository.Add(b2);
  repository.Add(c2);

  repository.StoreAll(&serializer);
}
