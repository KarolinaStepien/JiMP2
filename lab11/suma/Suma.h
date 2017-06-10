//
// Created by stepkaro on 23.05.17.
//

#ifndef JIMP_EXERCISES_SUMA_H
#define JIMP_EXERCISES_SUMA_H

#include <complex>
#include <iostream>

template<class J>
class Typ {
public:
    J x;
    Typ operator + (Typ &cos){
        return this->x + cos.x;
    }
};

template<class T>
T Suma( const T &left, const T &right){
    return left + right;
}

#endif //JIMP_EXERCISES_SUMA_H
