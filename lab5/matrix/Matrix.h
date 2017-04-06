//
// Created by Admin on 2017-04-01.
//

#ifndef JIMP_EXERCISES_MATRIX_H
#define JIMP_EXERCISES_MATRIX_H

#include <iostream>
#include <complex>
using namespace std;

class Matrix {
public:
    Matrix();
    Matrix(int rows_, int columns_);

    //1. konstruktor kopiujący
    Matrix(const Matrix &matrix);

    /*//2. konstruktor przenoszący
    Matrix(Matrix &&matrix);
    //3. operator przypisania kopiujący
    Matrix &operator=(const Matrix &matrix);
    //4. operator przypisania przenoszący
    Matrix &operator=(Matrix &&matrix);*/

    //5. Destruktor
    ~Matrix();

    void Create_Matrix();
    void Print_Matrix();
    Matrix Addition(const Matrix &m2) const;
    Matrix Subtraction(const Matrix &m2) const;
    Matrix Multiplication(const Matrix &m2) const;
    Matrix Exponentation(int p);
private:
    int columns;
    int rows;
    complex<double> **tab;
};

#endif //JIMP_EXERCISES_MATRIX_H



















//
// Created by zosia on 01.04.17.
//

/*#ifndef JIMP_EXERCISES_MATRIX_H
#define JIMP_EXERCISES_MATRIX_H
#include <cstdlib>
#include <string>
#include <iostream>
#include <complex>



using namespace std;

class Matrix {
    complex<double> **macierz;
    int n,m;

public:
    Matrix (int, int);
    Matrix ();
    Matrix (std::string);
    Matrix(Matrix &ziemniak);
    void Print();
    ~Matrix();

};


#endif //JIMP_EXERCISES_MATRIX_H*/