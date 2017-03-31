//
// Created by Admin on 2017-03-31.
//

#include "Square.h"

Square::Square(){}
Square::Square(Point A, Point B, Point C, Point D){
    A_=A;
    B_=B;
    C_=C;
    D_=D;
}
Square::~Square(){}

double Circumference(){
    return A_.Point::Distance(B_)*4;
}

double Area(){
    return A_.Point::Distance(B_)*A_.Point::Distance(B_);
}