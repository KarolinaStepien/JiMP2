//
// Created by Admin on 2017-03-31.
//

#include "Geometry.h"

int main(){
    Point p1{0,0};
    Point p2{5,0};
    Point p3{5,5};
    Point p4{5,0};

    Square object{p1, p2, p3, p4};
    cout << "Obwod kwadratu wynosi " << object.Square::Circumference() << endl;
    cout << "Pole kwadratu wynosi " << object.Square::Area() << endl;
    return 0;
}