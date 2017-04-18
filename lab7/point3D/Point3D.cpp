//
// Created by stepkaro on 11.04.17.
//

#include "Point3D.h"

#include <cmath>

//2D
Point::Point():x_(0),y_(0){
    cout << "Konstruktor bezparametrowy" << endl;
}

Point::Point(double x, double y){
    cout << "Konstruktor parametrowy 2d!" << endl;
    x_ = x;
    y_ = y;
}

Point::~Point(){
    cout << "Destruktor 2d!" << endl;
}

double Point::Distance(const Point &other) const{
    return sqrt(pow(GetX()-other.GetX(),2)+pow(GetY()-other.GetY(),2));
}

double Point::GetX() const{
    return x_;
}

double Point::GetY() const{
    return y_;
}

void Point::SetX(double x_) {
    Point::x_ = x_;
}

void Point::SetY(double y_) {
    Point::y_ = y_;
}

//pomocnicze funkcje do operatora istream >>
/*void CheckNextChar(char c, istream* is) {
    int next_char = is->peek();
    if (next_char != c) {
        throw runtime_error("invalid character");
    }
    is->ignore();
}*/

/*void IgnoreWhitespace(istream* is) {
    (*is) >> ws;
}*/

double ReadNumber(istream* is) {
    double d;
    (*is) >> d;
    return d;
}

//przeciazanie operatorow
istream& operator>>(istream & input, Point & p){
    //CheckNextChar('(', &input);
    p.SetX(ReadNumber(&input));
    //CheckNextChar(',', &input);
    //IgnoreWhitespace(&input);
    p.SetY(ReadNumber(&input));
    //CheckNextChar(')', &input);
    return input;
}

ostream& operator<<(ostream & output, Point & p){
    output << "(";
    output << p.GetX();
    output << ",";
    output << p.GetY();
    output << ")";
    return output;
}

//3D
Point3D::Point3D(): Point() {}

Point3D::Point3D(double x, double y, double z): Point(x, y){
    cout << "Konstruktor parametrowy 3d!" << endl;
    z_ = z;
}

Point3D::~Point3D(){
    cout << "Destruktor 3d!" << endl;
}

double Point3D::GetZ() const{
    return z_;
}

double Point3D::Distance(const Point3D &other) const{
    return sqrt(pow(GetX()-other.GetX(),2)+pow(GetY()-other.GetY(),2)+pow(GetZ()-other.GetZ(),2));
}