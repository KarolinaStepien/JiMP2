//
// Created by Admin on 2017-03-14.
//

#include "DoubleBasePalindromes.h"

uint64_t DoubleBasePalindromes(int max_vaule_exculsive) //max_vaule_exculsive = number_int
{
    uint64_t sum=0;
    for(max_vaule_exculsive=0;max_vaule_exculsive<1000000;max_vaule_exculsive++){
        char number_string_bin[30];
        char number_string[30];
        //char * itoa( int value, char * str, int base );
        itoa(max_vaule_exculsive, number_string_bin, 2);
        itoa(max_vaule_exculsive, number_string, 10);
        bool result1=is_palindrome(number_string);
        bool result2=is_palindrome(number_string_bin);
        if(result1&&result2){
            sum+=max_vaule_exculsive;
        }
    }
    return sum;
}

bool is_palindrome(string number)
{
    int i=0;
    long length=number.length();
    while(i<number.length()){
        if(number[i]==number[length-1]){
            if(i==number.length()-1){
                return true;
            }
            else{
                i++;
                length--;
            }
        }
        else{
            return false;
        }
    }
}