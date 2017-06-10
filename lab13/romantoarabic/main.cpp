//
// Created by stepkaro on 06.06.17.
//

#include "RomanToArabic.h"
#include "RomanToArabicTest.h"

#include <string>
#include <utility>
#include <iostream>
#include<vector>

using std::string;
using std::pair;
using std::cerr;
using std::endl;

//test function to wskaźnik na funkcję zwracającą bool
using TestFunction = bool (*)();

std::vector<pair<string,TestFunction>> all_tests {{"EasyRomanToArabicTest", EasyRomanToArabicTest}, {"EasyArabicToRomanTest", EasyArabicToRomanTest}, {"ZeroArabicToRomanTest", ZeroArabicToRomanTest}, {"NegativeArabicToRomanTest", NegativeArabicToRomanTest}};

void ReportTest(const string &failed_test_name) {
    cerr << "Test " << failed_test_name << " FAILED" << endl;
}

int RunTests(const std::vector<pair<string,TestFunction>>  tests) {
    int failed_tests = 0;
    for (auto test : tests) {
        bool result = test.second();
        if (result) {
            continue;
        } else {
            ReportTest(test.first);
            failed_tests++;
        }
    }
    return failed_tests;
}

int main() {
    int result = RunTests(all_tests);
    cout<< RzymskieNaArabskie("IX");
    return result;
}
