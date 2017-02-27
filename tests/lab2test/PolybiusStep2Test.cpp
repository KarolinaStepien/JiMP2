//
// Created by mwypych on 21.02.17.
//

#include <Polybius.h>
#include <gtest/gtest.h>
#include <MemLeakTest.h>

using TestParam = std::pair<std::string, std::string>;

class PolybiusStep2Tests : public ::testing::TestWithParam<TestParam>, MemLeakTest {

};

TEST_P(PolybiusStep2Tests, PolybiusDecryptShouldReturnExpectedResult) {
  const TestParam &p = GetParam();
  std::string encrypted = p.first;
  std::string message = p.second;
  EXPECT_EQ(encrypted, PolybiusDecrypt(message)) << "Did call PolybiusDecrypt(" << message << ")\n";
}

std::vector<TestParam> polybius_decrypt_test_data{
    {"", ""},
    {"message", "32154343112215"},
    {"wiadomosczespaciami", "52241114343234431355154335111324113224"},
    {"abcdefghiiklmnopqrstuvwxyz", "1112131415212223242425313233343541424344455152535455"},
    {"scisletaine", "4313244331154411243315"},/*,
    {"Wiadomość z polskimi znakami ą ę ć ż ź ł ó ń ś Ą Ę Ć Ź Ż Ł Ó Ń Ś", ""}*/};

INSTANTIATE_TEST_CASE_P(PolybiusStep2Tests,
                        PolybiusStep2Tests,
                        ::testing::ValuesIn(polybius_decrypt_test_data));

