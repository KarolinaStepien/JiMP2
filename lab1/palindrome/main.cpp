//
// Created by Admin on 2017-03-14.
//

#include "Palindrome.h"

int main()
{
    while (true){
        string choice;
        cout << "Write 1 to be able to write a word or anything else to exit:" << endl;
        getline(cin,choice);
        if(choice=="1"){
            string str;
            cout << "Write a word you want to check:" << endl;
            getline(cin,str);
            is_palindrome(str);
        }
        else{
            return 0;
        }
    }
}
