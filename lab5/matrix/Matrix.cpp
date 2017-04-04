/*//
// Created by Admin on 2017-04-01.
//

#include "Matrix.h"

Matrix::Matrix():rows(0),columns(0),valueptr(NULL) {}
Matrix::Matrix(int rows_, int columns_){
    rows = rows_;
    columns = columns_;
    //valueptr = NULL;
}
/*
Matrix::~Matrix(){
    if(valueptr!=NULL) {
        delete[]valueptr;
        valueptr=NULL;
    }
}
Matrix::Matrix(const Matrix &matrix){
    this->rows = matrix.rows;
    this->columns = matrix.columns;
    this->valueptr = new int [matrix.rows*matrix.columns];
    for(int i=0;i<this->rows*this->columns;i++){
        this->valueptr[i] = matrix.valueptr[i];
    }
}
Matrix Matrix::Create_Matrix() {
    int columns;
    int rows;
    cin >> columns;
    cin >> rows;
    this->valueptr = new int[rows*columns];
    this->columns = columns;
    this->rows = rows;
    for (int i = 0; i<rows*columns; i++) {
            cin >> this->valueptr[i];
    }
    return *this;
}
void Matrix::Print_Matrix() {
    for (int i = 0; i<rows*columns; i++) {
            cout << this->valueptr[i];
            cout<<endl;
    }
}
Matrix Matrix::Add(Matrix &m2){
    Matrix sum;
    if(this->rows==m2.rows  && this->columns==m2.columns){
        sum.valueptr = new int[this->rows*this->columns];
        for (int i = 0; i<rows*columns; i++){
            sum.valueptr[i]=this->valueptr[i]+m2.valueptr[i];
            cout<<sum.valueptr[i];
            if (i%(columns-1)==0) cout<<endl;
        }
    }
    else{
        cout << "Macierz ma niepoprawne wymiary :(";
    }
    return sum;
}
Matrix Matrix::Multiply(Matrix &m2){
    Matrix product;
    if(this->rows==m2.columns  && this->columns==m2.rows){
        product.valueptr = new int[this->rows*m2.columns];
        for(int i=0;i<this->rows;i++){
            for (int j=0;j<m2.columns;j++){
                int element=0;
                for(int k=0;k<m2.rows;k++){
                    element+=this->valueptr[i*this->columns+k]*m2.valueptr[k*m2.columns+j];
                }
                product.valueptr[i*product.columns+j] = element;
                cout << element;
            }
        }
    }
    else{
        cout << "Macierz ma niepoprawne wymiary :(";
    }
    return product;
}*/

//
// Created by zosia on 01.04.17.
//

#include <complex>
#include "Matrix.h"


Matrix::Matrix(int n, int m) {
    this->n=n;
    this->m=m;
    macierz = new complex<double>*[n];
    for (int i=0; i<n; ++i){
        macierz[i] = new complex<double>[m];
    }

}

Matrix::Matrix(Matrix &ziemniak) {

    n = ziemniak.n;
    m = ziemniak.m;
    complex<double> ** wektory = new complex<double>*[n];
    for (int i=0; i<n; ++i){
        wektory[i] = new complex<double>[m];
        for(int x=0;x<m;x++)
        {
            wektory[i][x]=ziemniak.macierz[i][x];
        }
    }
}

Matrix::Matrix() {
    cout << "Dzien dobry, tu Twoja macierz."<<endl;
}

Matrix::~Matrix() {
    cout << "Do widzenia!" << endl;
}

Matrix::Matrix(std::string matlabowe_cos) {
    int n = 0, m = 0;
    string::size_type sz;
    string liczba = "", liczba_re = "", liczba_im = "";
    double liczba_double, liczba_re_double,liczba_im_double;
    for (string::iterator it = matlabowe_cos.begin(); it != matlabowe_cos.end(); ++it) {
        if (*it == 32) m++;
        if (*it == 59) n++;
    }
    this->n = n;
    this->m = m;
    macierz = new complex<double> *[n];
    for (int i = 0; i < n; ++i) {
        macierz[i] = new complex<double>[m];
    }

    int i = 0, j = 0;
    for (string::iterator it = matlabowe_cos.begin(); it != matlabowe_cos.end(); ++it) {
        if ((*it <= 57 && *it >= 48) ||  *it == 105 || *it == 46) {
            cout << " ";
            liczba += *it;

        }
        else if (*it == ' ' || *it == ']') {
            if (liczba.find("i") != string::npos) {
                for (int k = 0; k != liczba.find("i"); k++) {
                    liczba_re += liczba[k];
                    liczba_im += liczba[liczba.length() - k -1];
                }
                liczba_re_double = stod(liczba_re, &sz);
                liczba_im_double = stod(liczba_im, &sz);
                macierz[i][j] = complex<double>(liczba_re_double, liczba_im_double);
                j++;
                liczba = "";
                liczba_re = "";
                liczba_im = "";
            } else {
                liczba_double = stod(liczba, &sz);
                macierz[i][j] = complex<double>(liczba_double);
                j++;
                liczba = "";
            }
        }
        else if (*it == 59) {
            if (liczba.find("i") != string::npos) {
                for (int k = 0; k != liczba.find("i"); k++) {
                    liczba_re += liczba[k];
                    liczba_im += liczba[liczba.length() - k];
                }
                liczba_re_double = stod(liczba_re, &sz);
                liczba_im_double = stod(liczba_im, &sz);
                macierz[i][j] = complex<double>(liczba_re_double, liczba_im_double);
                j++;
                liczba = "";
                liczba_re = "";
                liczba_im = "";
            } else {
                liczba_double = stod(liczba, &sz);
                macierz[i][j] = complex<double>(liczba_double);
                j++;
                liczba = "";

            }
            *it++;
        }
    }

}

void Matrix::Print() {
    for(int o=0;o<n;o++){
        for(int p=0;p<=m;p++){
            cout << macierz[o][p];
        }
    }

}