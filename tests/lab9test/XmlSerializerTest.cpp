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
using ::academia::XmlSerializer;


using namespace std;
using namespace std::literals;

class XmlSerializerTest : public ::testing::Test, MemLeakTest {
 public:
  stringstream out;
  XmlSerializer serializer{&out};
};

TEST_F(XmlSerializerTest, SerializationOfSingleComputerLabRoom) {
  Room room {117, "218", Room::Type::COMPUTER_LAB};
  EXPECT_NO_THROW(room.Serialize(&serializer));
  EXPECT_EQ("<room><id>117<\\id><name>218<\\name><type>COMPUTER_LAB<\\type><\\room>"s, out.str());
}

TEST_F(XmlSerializerTest, SerializationOfSingleLectureHallRoom) {
  Room room {100167, "H-24", Room::Type::LECTURE_HALL};
  EXPECT_NO_THROW(room.Serialize(&serializer));
  EXPECT_EQ("<room><id>100167<\\id><name>H-24<\\name><type>LECTURE_HALL<\\type><\\room>"s, out.str());
}

TEST_F(XmlSerializerTest, SerializationOfSingleClassroom) {
  Room room {898910, "316", Room::Type::CLASSROOM};
  EXPECT_NO_THROW(room.Serialize(&serializer));
  EXPECT_EQ("<room><id>898910<\\id><name>316<\\name><type>CLASSROOM<\\type><\\room>"s, out.str());
}

TEST_F(XmlSerializerTest, SerializationOfEmptyBuilding) {
  Building building {11, "A0", {}};
  EXPECT_NO_THROW(building.Serialize(&serializer));
  EXPECT_EQ("<building><id>11<\\id><name>A0<\\name><rooms><\\rooms><\\building>"s, out.str());
}

TEST_F(XmlSerializerTest, SerializationOfBuildingWithSingleRoom) {
  Room room {100167, "H-24", Room::Type::LECTURE_HALL};
  Building building {11, "A0", {room}};
  EXPECT_NO_THROW(building.Serialize(&serializer));
  EXPECT_EQ("<building><id>11<\\id><name>A0<\\name><rooms><room><id>100167<\\id><name>H-24<\\name><type>LECTURE_HALL<\\type><\\room><\\rooms><\\building>"s, out.str());
}

TEST_F(XmlSerializerTest, SerializationOfBuildingWithSeveralRooms) {
  Room r1 {100167, "429", Room::Type::LECTURE_HALL};
  Room r2 {100168, "208", Room::Type::COMPUTER_LAB};
  Room r3 {100169, "216", Room::Type::COMPUTER_LAB};
  Building building {11, "C2", {r1, r2, r3}};
  EXPECT_NO_THROW(building.Serialize(&serializer));
  EXPECT_EQ("<building><id>11<\\id><name>C2<\\name><rooms>"
                "<room><id>100167<\\id><name>429<\\name><type>LECTURE_HALL<\\type><\\room>"
                "<room><id>100168<\\id><name>208<\\name><type>COMPUTER_LAB<\\type><\\room>"
                "<room><id>100169<\\id><name>216<\\name><type>COMPUTER_LAB<\\type><\\room>"
                "<\\rooms><\\building>"s, out.str());
}