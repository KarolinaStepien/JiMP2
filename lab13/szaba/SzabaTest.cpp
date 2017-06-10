//
// Created by stepkaro on 06.06.17.
//

#include "SzabaTest.h"

bool EasyRomanToArabicTest() {
    int expected = 12;
    int result = RzymskieNaArabskie("XII");
    return expected == result;
}

bool EasyArabicToRomanTest() {
    string expected = "XVIII";
    string result = ArabskieNaRzymskie(18);
    return expected == result;
}

bool ZeroArabicToRomanTest() {
    string expected = "niemawodynapustyni";
    string result = ArabskieNaRzymskie(0);
    return expected == result;
}

bool NegativeArabicToRomanTest() {
    string expected = "niemawodynapustyni";
    string result = ArabskieNaRzymskie(-20);
    return expected == result;
}


