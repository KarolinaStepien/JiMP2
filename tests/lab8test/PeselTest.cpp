//
// Created by mwypych on 25.04.17.
//

#include <gtest/gtest.h>
#include <string>
#include <vector>
#include <memory>
#include <stdexcept>
#include <MemLeakTest.h>
#include <Pesel.h>

using ::academia::Pesel;
using ::academia::InvalidPeselChecksum;
using ::academia::InvalidPeselLength;
using ::academia::InvalidPeselCharacter;
using ::academia::AcademiaDataValidationError;

using ::std::make_unique;
using ::std::string;


class PeselTests : public ::testing::Test, MemLeakTest {
 public:
};

TEST_F(PeselTests, TooShortPeselThrowsInvalidPeselLenghtException) {
  EXPECT_THROW(Pesel("000"),InvalidPeselLength);
}

TEST_F(PeselTests, TooLongPeselThrowsInvalidPeselLenghtException) {
  EXPECT_THROW(Pesel("0000000000000000"),InvalidPeselLength);
}

TEST_F(PeselTests, PeselWithInvalidCharactersThrowsInvalidPeselCharacterException) {
  EXPECT_THROW(Pesel("000000000x0"),InvalidPeselCharacter);
}

TEST_F(PeselTests, PeselWithInvalidChecksumThrowsInvalidPeselChecksumException) {
  EXPECT_THROW(Pesel("00000000001"),InvalidPeselChecksum);
}

TEST_F(PeselTests, ValidPesel00000000000NotThrowsAnyException) {
  EXPECT_NO_THROW(Pesel("00000000000"));
}

TEST_F(PeselTests, ValidPesel44051401359NotThrowsAnyException) {
  EXPECT_NO_THROW(Pesel("44051401359"));
}

TEST_F(PeselTests, ThereAreNoMemoryLeaksAfterThrowingAnExcpetion) {
  EXPECT_THROW(make_unique<Pesel>("44051401354"),InvalidPeselChecksum);
}

TEST_F(PeselTests, BaseClassOfInvalidPeselChecksumIsDataValidationErrorThen__runtime_error__Then__exception) {
  EXPECT_THROW(Pesel("00000000001"),AcademiaDataValidationError);
  EXPECT_THROW(Pesel("00000000001"),std::runtime_error);
  EXPECT_THROW(Pesel("00000000001"),std::exception);
}

TEST_F(PeselTests, TheMessageOfInvalidPeselChecksum) {
  auto ex = make_unique<InvalidPeselChecksum>("00000000001",1);
  EXPECT_STREQ("Invalid PESEL(00000000001) checksum: 1",ex->what());
}

TEST_F(PeselTests, TheMessageOfInvalidPeselCharacter) {
  auto ex = make_unique<InvalidPeselCharacter>("00000000xxx");
  EXPECT_STREQ("Invalid PESEL(00000000xxx) character set",ex->what());
}

TEST_F(PeselTests, TheMessageOfInvalidPeselLength) {
  auto ex = make_unique<InvalidPeselLength>("0000000000",10);
  EXPECT_STREQ("Invalid PESEL(0000000000) length: 10",ex->what());
}


