//
// Created by stepkaro on 06.06.17.
//

#ifndef JIMP_EXERCISES_SZABA_H
#define JIMP_EXERCISES_SZABA_H
#include <string>

using namespace std;

std::string ArabskieNaRzymskie(long int liczba)
{
    const long int Numbers[13] = { 1, 4, 5, 9, 10, 40, 50, 90, 100,
                                   400, 500, 900, 1000 };
    const std::string Romans[13] = { "I", "IV", "V", "IX", "X", "XL",
                                     "L", "XC", "C", "CD", "D", "CM", "M" };
    std::string Result = "";
    for (int i = 12; i >= 0; --i)
    {
        while (liczba >= Numbers[i])
        {
            liczba -= Numbers[i];
            Result += Romans[i];
        }
    }
    return Result;
}


#endif //JIMP_EXERCISES_SZABA_H
