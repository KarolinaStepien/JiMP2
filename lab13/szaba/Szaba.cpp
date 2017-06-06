//
// Created by stepkaro on 06.06.17.
//

#include "Szaba.h"

string ArabskieNaRzymskie(long int liczba) {

    if (liczba <= 0 ){
        return "niemawodynapustyni";
    }
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

int RzymskieNaArabskie(string zawartosc) {
    int wynik = 0;
    for(int i = 0; i <= 24; i++)
    {
        if(zawartosc[i] == 'I' && zawartosc[i+1] == 'V')
        {
            wynik+=4;
            i++;
        }
        else if(zawartosc[i] == 'I' && zawartosc[i+1] == 'X')
        {
            wynik+=9;
            i++;
        }
        else if(zawartosc[i] == 'X' && zawartosc[i+1] == 'L')
        {
            wynik+=40;
            i++;
        }
        else if(zawartosc[i] == 'X' && zawartosc[i+1] == 'C')
        {
            wynik+=90;
            i++;
        }
        else if(zawartosc[i] == 'C' && zawartosc[i+1] == 'D')
        {
            wynik+=400;
            i++;
        }
        else if(zawartosc[i] == 'C' && zawartosc[i+1] == 'M')
        {
            wynik+=900;
            i++;
        }
        else if(zawartosc[i] == 'I')
        {
            wynik++;
        }
        else if(zawartosc[i] == 'V')
        {
            wynik+=5;
        }
        else if(zawartosc[i] == 'X')
        {
            wynik+=10;
        }
        else if(zawartosc[i] == 'L')
        {
            wynik+=50;
        }
        else if(zawartosc[i] == 'C')
        {
            wynik+=100;
        }
        else if(zawartosc[i] == 'D')
        {
            wynik+=500;
        }
        else if(zawartosc[i] == 'M')
        {
            wynik+=1000;
        }
        else if(!(zawartosc[i]))
        {
            break;
        }
    }
    return wynik;
}
