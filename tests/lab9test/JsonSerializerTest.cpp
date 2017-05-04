//
// Created by mwypych on 04.05.17.
//

#include <gtest/gtest.h>
#include <string>
#include <memory>
#include <stdexcept>
#include <MemLeakTest.h>
#include <Serialization.h>

using ::academia::Building;
using ::academia::Room;
using ::academia::JsonSerializer;


using namespace std;
using namespace std::literals;

class JsonSerializerTest : public ::testing::Test, MemLeakTest {
 public:
  stringstream out;
  JsonSerializer serializer{&out};
};

TEST_F(JsonSerializerTest, SerializationOfSingleComputerLabRoom) {
  Room room {117, "218", Room::Type::COMPUTER_LAB};
  EXPECT_NO_THROW(room.Serialize(&serializer));
  EXPECT_EQ("{\"id\": 117, \"name\": \"218\", \"type\": \"COMPUTER_LAB\"}"s, out.str());
}

TEST_F(JsonSerializerTest, SerializationOfSingleLectureHallRoom) {
  Room room {100167, "H-24", Room::Type::LECTURE_HALL};
  EXPECT_NO_THROW(room.Serialize(&serializer));
  EXPECT_EQ("{\"id\": 100167, \"name\": \"H-24\", \"type\": \"LECTURE_HALL\"}"s, out.str());
}

TEST_F(JsonSerializerTest, SerializationOfSingleClassroom) {
  Room room {898910, "316", Room::Type::CLASSROOM};
  EXPECT_NO_THROW(room.Serialize(&serializer));
  EXPECT_EQ("{\"id\": 898910, \"name\": \"316\", \"type\": \"CLASSROOM\"}"s, out.str());
}

TEST_F(JsonSerializerTest, SerializationOfEmptyBuilding) {
  Building building {11, "A0", {}};
  EXPECT_NO_THROW(building.Serialize(&serializer));
  EXPECT_EQ("{\"id\": 11, \"name\": \"A0\", \"rooms\": []}"s, out.str());
}

TEST_F(JsonSerializerTest, SerializationOfBuildingWithSingleRoom) {
  Room room {100167, "H-24", Room::Type::LECTURE_HALL};
  Building building {11, "A0", {room}};
  EXPECT_NO_THROW(building.Serialize(&serializer));
  EXPECT_EQ("{\"id\": 11, \"name\": \"A0\", \"rooms\": ["
                "{\"id\": 100167, \"name\": \"H-24\", \"type\": \"LECTURE_HALL\"}]}"s, out.str());
}

TEST_F(JsonSerializerTest, SerializationOfBuildingWithSeveralRooms) {
  Room r1 {100167, "429", Room::Type::LECTURE_HALL};
  Room r2 {100168, "208", Room::Type::COMPUTER_LAB};
  Room r3 {100169, "216", Room::Type::COMPUTER_LAB};
  Building building {11, "C2", {r1, r2, r3}};
  EXPECT_NO_THROW(building.Serialize(&serializer));
  EXPECT_EQ("{\"id\": 11, \"name\": \"C2\", \"rooms\": ["
                "{\"id\": 100167, \"name\": \"429\", \"type\": \"LECTURE_HALL\"}, "
                "{\"id\": 100168, \"name\": \"208\", \"type\": \"COMPUTER_LAB\"}, "
                "{\"id\": 100169, \"name\": \"216\", \"type\": \"COMPUTER_LAB\"}]}"s, out.str());
}