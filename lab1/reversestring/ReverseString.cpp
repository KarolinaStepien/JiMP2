//
// Created by Admin on 2017-03-14.
//

#include "ReverseString.h"

string reverse(string str)
{
    long length=str.size();
    string new_word, character;

    for (int i = 0; i < length; i++)
    {
        character = str[length-1-i];
        new_word.append(character);
    }
    return new_word;
}