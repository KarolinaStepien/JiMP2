//
// Created by mwypych on 21.02.17.
//

#include <Polybius.h>
#include <gtest/gtest.h>

using TestParam = std::pair<std::pair<std::string, std::string>, std::string>;

class PolybiusStep3Tests : public ::testing::TestWithParam<TestParam>, MemLeakTest {

};

TEST_P(PolybiusStep3Tests, DefineEncryptionMapUsing) {
  const TestParam &p = GetParam();
  std::string encrypted = p.second;
  std::string message = p.first;
  EXPECT_EQ(encrypted, PolybiusCrypt(message)) << "Did call PolybiusCrypt(" << message << ")\n";
}

std::vector<TestParam> polybius_test_data{
    {{"", ""}, ""},
    {{"message",}, "32154343112215"},
    {"wiadomosc ze spacjami", "52241114343234431355154335111324113224"},
    {"abcdefghijklmnopqrstuvwxyz", "1112131415212223242425313233343541424344455152535455"},
    {"a b c d e f g h i j k l m n o p q r s t u v w x y z", "1112131415212223242425313233343541424344455152535455"},
    {"scisle tajne", "4313244331154411243315"},
    {"SCISLE TAJNE", "4313244331154411243315"}/*,
    {"Wiadomość z polskimi znakami ą ę ć ż ź ł ó ń ś Ą Ę Ć Ź Ż Ł Ó Ń Ś", ""}*/};

INSTANTIATE_TEST_CASE_P(PolybiusStep3Tests,
                        PolybiusStep3Tests,
                        ::testing::ValuesIn(polybius_test_data));

