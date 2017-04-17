//
// Created by Admin on 2017-04-01.
//

#include "Matrix.h"

using algebra::Matrix;

int main() {
    //int p=3; //power
    //Matrix m1("[1i3 2i5 3; 3 4 5; 6 7 8]");
    Matrix m1{{1.0i, 0., 0.}, {0., 1.0i, 0.}};
    m1.Print_Matrix();
    //Matrix m2{{1. + 3.0i, 2. + 2.0i}, {3. + 1.0i, 4. + 6.0i}, {5. + 5.i, 6. + 4.0i}};
/*    Matrix m1,m2, help;
    m1.Create_Matrix();
    cout << "Oto Twoja macierz :) " << endl;
    m1.Print_Matrix();
    m2.Create_Matrix();
    cout << "Oto Twoja macierz :) " << endl;
    m2.Print_Matrix();*/
    //cout << "Oto Twoja macierz potęgi :)" << endl;
    // m1.Exponentation(p).Print_Matrix();
/*    cout << "Oto Twoja macierz iloczynu :)" << endl;
    m1.Multiplication(m2).Print_Matrix();
    cout << "Oto Twoja macierz różnicy :)" << endl;
    m1.Subtraction(m2).Print_Matrix();
    cout << "Oto Twoja macierz sumy :)" << endl;
    m1.Addition(m2).Print_Matrix();*/

    return 0;
}