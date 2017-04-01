//
// Created by Admin on 2017-04-01.
//

#include "Matrix.h"

int columns;
int rows;
int *valueptr;

Matrix Matrix::Create_Matrix() {
    int columns;
    int rows;
    cin >> columns;
    cin >> rows;
    this->valueptr = new int[rows*columns];
    this->columns = columns;
    this->rows = rows;
    for (int i = 0; i<rows; i++) {
        for (int j = 0; j<columns; j++) {
            cin >> this->valueptr[i*columns + j];
        }
    }
    return *this;
}
void Matrix::Print_Matrix() {
    for (int i = 0; i<rows; i++) {
        for (int j = 0; j < columns; j++) {
            cout << this->valueptr[i * columns + j];
        }
    }
}