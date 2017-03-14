//
// Created by Admin on 2017-03-14.
//

#include "Polybius.h"

string PolybiusCrypt(string message)
{
    string new_message="";
    transform(message.begin(), message.end(), message.begin(), ::tolower);
    map <char, string> mapa;
    mapa['a']="11";
    mapa['b']="12";
    mapa['c']="13";
    mapa['d']="14";
    mapa['e']="15";
    mapa['f']="21";
    mapa['g']="22";
    mapa['h']="23";
    mapa['i']="24";
    mapa['j']="24";
    mapa['k']="25";
    mapa['l']="31";
    mapa['m']="32";
    mapa['n']="33";
    mapa['o']="34";
    mapa['p']="35";
    mapa['q']="41";
    mapa['r']="42";
    mapa['s']="43";
    mapa['t']="44";
    mapa['u']="45";
    mapa['v']="51";
    mapa['w']="52";
    mapa['x']="53";
    mapa['y']="54";
    mapa['z']="55";

    for (string::iterator it=message.begin(); it!=message.end(); ++it){
        new_message+=mapa[*it];
    }
    return new_message;
}

string PolybiusDecrypt(string crypted)
{
    string new_crypted="", tmp="";
    map <string, char> mapa;
    mapa["11"]='a';
    mapa["12"]='b';
    mapa["13"]='c';
    mapa["14"]='d';
    mapa["15"]='e';
    mapa["21"]='f';
    mapa["22"]='g';
    mapa["23"]='h';
    mapa["24"]='i';
    mapa["24"]='j';
    mapa["25"]='k';
    mapa["31"]='l';
    mapa["32"]='m';
    mapa["33"]='n';
    mapa["34"]='o';
    mapa["35"]='p';
    mapa["41"]='q';
    mapa["42"]='r';
    mapa["43"]='s';
    mapa["44"]='t';
    mapa["45"]='u';
    mapa["51"]='v';
    mapa["52"]='w';
    mapa["53"]='x';
    mapa["54"]='y';
    mapa["55"]='z';

    for (string::iterator it=crypted.begin(); it!=crypted.end(); ++it){
        tmp=*it;
        it++;
        tmp+=*it;
        new_crypted+=mapa[tmp];
    }
    return new_crypted;
}
