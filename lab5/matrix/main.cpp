//
// Created by Admin on 2017-04-01.
//

#include "Matrix.h"

int main() {
    int p=3; //power
    Matrix m1,m2, help;
    m1.Create_Matrix();
    cout << "Oto Twoja macierz :) " << endl;
    m1.Print_Matrix();
//    m2.Create_Matrix();
//    cout << "Oto Twoja macierz :) " << endl;
//    m2.Print_Matrix();
    cout << "Oto Twoja macierz potęgi :)" << endl;
    m1.Exponentation(p).Print_Matrix();
//    cout << "Oto Twoja macierz iloczynu :)" << endl;
//    m1.Multiplication(m2).Print_Matrix();
//    cout << "Oto Twoja macierz różnicy :)" << endl;
//    m1.Subtraction(m2).Print_Matrix();
//    cout << "Oto Twoja macierz sumy :)" << endl;
//    m1.Addition(m2).Print_Matrix();

    return 0;
}




















//
// Created by zosia on 03.04.17.
//
/*#include "Matrix.h"


int main(){
    string str = "[13i65 2.0 3; 7 4 3]";
    Matrix m(str);
    m.Print();
    return 0;
}*/
