/*//
// Created by Admin on 2017-04-01.
//

#include "Matrix.h"

int main() {
    Matrix m1;
    Matrix m2;
    m1.Matrix::Create_Matrix();
    m2.Matrix::Create_Matrix();
    m1.Matrix::Print_Matrix();
    m2.Matrix::Print_Matrix();
    //m1.Matrix::Add(m2);
    m2.Matrix::Multiply(m2);
    return 0;
}*/

//
// Created by zosia on 03.04.17.
//
#include "Matrix.h"


int main(){
    string str = "[13i65 2.0 3; 7 4 3]";
    Matrix m(str);
    m.Print();
    return 0;
}
