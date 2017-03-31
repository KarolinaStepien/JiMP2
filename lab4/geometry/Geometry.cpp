//
// Created by Admin on 2017-03-31.
//

#include "Geometry.h"

// POINT
Point::Point():x_(0),y_(0){}

Point::Point(double x, double y){
    x_ = x;
    y_ = y;
}

Point::~Point(){}

double Point::GetX() const{
    return x_;
}
double Point::GetY() const{
    return y_;
}

double Point::Distance(const Point &other) const{
    return sqrt(pow(GetX()-other.GetX(),2)+pow(GetY()-other.GetY(),2));
}

void Point::ToString(ostream *out) const{
    (*out) << "(" << GetX() << ";" << GetY() << ")";
}

//SQUARE
Square::Square(){}

Square::Square(Point A, Point B, Point C, Point D){
    A_=A;
    B_=B;
    C_=C;
    D_=D;
}

Square::~Square(){}

double Square::Circumference(){
    return A_.Point::Distance(B_)*4;
}

double Square::Area(){
    return A_.Point::Distance(B_)*A_.Point::Distance(B_);
}