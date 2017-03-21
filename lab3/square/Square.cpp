//
// Created by owsizofi on 21.03.17.
//

#include "Square.h"
#include "Point.h"
#include <cmath>
#include <iostream>
using ::std::ostream;
using ::std::endl;
using ::std::pow;
using ::std::sqrt;


Square::Square(Point a, Point b, Point c, Point d){

    a_ = a;
    b_ = b;
    c_ = c;
    d_ = d;
}

double Point::Distance(const Point inny,const Point jeszcze_inny){
    return sqrt(pow(jeszcze_inny.GetX()-inny.GetX(),2)+pow(jeszcze_inny.GetY()-inny.GetY(),2));
}

double Square::Circumference(const Square &other) const {
    return 4*Distance(other.GetA(),other.GetB());
}

double Square::Area(const Square &other) const{
    return Distance(other.GetA(),other.GetB())*Distance(other.GetA(),other.GetB());
}


