//
// Created by Admin on 2017-04-01.
//

#ifndef JIMP_EXERCISES_MATRIX_H
#define JIMP_EXERCISES_MATRIX_H

#include <iostream>
#include <complex>
//#include <string>
#include <algorithm>
#include <regex>

using namespace std;

namespace algebra {
    class Matrix {
    public:
        Matrix();
        Matrix(int rows_, int columns_);

        //1. konstruktor kopiujący
        Matrix(const Matrix &matrix);
        //2. konstruktor przenoszący
        //Matrix(Matrix &&matrix);
        //3. operator przypisania kopiujący
        Matrix &operator=(const Matrix &matrix);
        //4. operator przypisania przenoszący
        //Matrix &operator=(Matrix &&matrix);
        //5. Destruktor
        ~Matrix();

        //konstruktor zamieniajacy postac matlabowa na tablice dwuwymiarowa
        //Matrix(string uuu);
        //Matrix(std::initializer_list<vector<complex<double>>> cosik);
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
}
#endif //JIMP_EXERCISES_MATRIX_H