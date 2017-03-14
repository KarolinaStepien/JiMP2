//
// Created by Admin on 2017-03-14.
//

#include "Palindrome.h"

bool is_palindrome(string str)
{
    int i=0;
    long length=str.length();
    while(i<str.length()){
        if(str[i]==str[length-1]){
            if(i==str.length()-1){
                cout << "Palindrome! <3" << endl << endl;
                return true;
            }
            else{
                i++;
                length--;
            }
        }
        else{
            cout << "Your word is not a palindrome :(" << endl << endl;
            return false;
        }
    }
}

