//
// Created by mwypych on 04.05.17.
//


#include <gtest/gtest.h>
#include <string>
#include <memory>
#include <MemLeakTest.h>
#include <Serialization.h>

using ::academia::Room;
using ::academia::Serializer;


using namespace std;
using namespace std::literals;

class DummySerializer : public Serializer {
 public:
  DummySerializer(std::ostream *out) : Serializer(out) {

  }
  void IntegerField(const std::string &field_name, int value) override {
    integer_field_called++;
  }
  void DoubleField(const std::string &field_name, double value) override {
    double_field_called++;
  }
  void StringField(const std::string &field_name, const std::string &value) override {
    string_field_called++;
  }
  void BooleanField(const std::string &field_name, bool value) override {
    boolean_field_called++;
  }
  void SerializableField(const std::string &field_name, const academia::Serializable &value) override {
    serializable_field_called++;
  }
  void ArrayField(const std::string &field_name,
                  const vector<reference_wrapper<const academia::Serializable>> &value) override {
    array_field_called++;
  }
  void Header(const std::string &object_name) override {
    header_field_called++;
  }
  void Footer(const std::string &object_name) override {
    footer_field_called++;
  }

  int integer_field_called = 0;
  int double_field_called = 0;
  int boolean_field_called = 0;
  int serializable_field_called = 0;
  int string_field_called = 0;
  int array_field_called = 0;
  int header_field_called = 0;
  int footer_field_called = 0;
};

class XmlSerializerTest : public ::testing::Test, MemLeakTest {
 public:
  stringstream out;
  DummySerializer serializer{&out};
};

TEST_F(XmlSerializerTest, SerializationOfSingleComputerLabRoom) {
  Room room {117, "218", Room::Type::COMPUTER_LAB};
  EXPECT_NO_THROW(room.Serialize(&serializer));
  EXPECT_EQ(1,serializer.header_field_called);
  EXPECT_EQ(1,serializer.integer_field_called);
  EXPECT_EQ(2,serializer.string_field_called);
  EXPECT_EQ(0,serializer.double_field_called);
  EXPECT_EQ(0,serializer.array_field_called);
  EXPECT_EQ(0,serializer.boolean_field_called);
  EXPECT_EQ(1,serializer.footer_field_called);
}