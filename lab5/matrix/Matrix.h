//
// Created by Admin on 2017-04-01.
//

#ifndef JIMP_EXERCISES_MATRIX_H
#define JIMP_EXERCISES_MATRIX_H

#include <iostream>
using namespace std;

class Matrix {
    int columns;
    int rows;
    int *valueptr;
public:
    Matrix Create_Matrix();
    void Print_Matrix();
};

#endif //JIMP_EXERCISES_MATRIX_H
