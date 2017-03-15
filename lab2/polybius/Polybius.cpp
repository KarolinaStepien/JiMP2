//
// Created by Admin on 2017-03-10.
//

#include "Polybius.h"


string PolybiusCrypt (string message){
    string crypt="";
    transform(message.begin(), message.end(), message.begin(), ::tolower);
    map <char, string> polybius = {{'a', "11"}, {'b',"12"}, {'c',"13"}, {'d',"14"}, {'e',"15"}, {'f', "21"}, {'g', "22"}, {'h', "23"},
                                   {'i', "24"}, {'j', "24"}, {'k', "25"}, {'l', "31"}, {'m', "32"}, {'n', "33"}, {'o', "34"}, {'p', "35"},
                                   {'q', "41"}, {'r', "42"}, {'s', "43"}, {'t', "44"}, {'u', "45"}, {'v', "51"}, {'w', "52"}, {'x', "53"},
                                   {'y', "54"}, {'z', "55"}};

    for (string::iterator it = message.begin(); it != message.end(); ++it){
        crypt += polybius[*it];
    }
    return crypt;
}

string PolybiusDecrypt (string crypt){
    string message="", tmp="";
    map <string, char> polybius = {{"11",'a'},{"12",'b'},{"13",'c'},{"14",'d'},{"15",'e'},{"21",'f'},{"22",'g'},
                                   {"23",'h'},{"24",'i'},{"24",'j'},{"25",'k'},{"31",'l'},{"32",'m'},{"33",'n'},
                                   {"34",'o'},{"35",'p'},{"41",'q'},{"42",'r'},{"43",'s'},{"44",'t'},{"45",'u'},
                                   {"51",'v'},{"52",'w'},{"53",'x'},{"54",'y'},{"55",'z'}};
    for (string::iterator it = crypt.begin(); it != crypt.end(); ++it){
        tmp = *it;
        ++it;
        tmp+=*it;
        message += polybius[tmp];
    }
    return message;
}
