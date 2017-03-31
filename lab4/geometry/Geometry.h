//
// Created by Admin on 2017-03-31.
//

#ifndef JIMP_EXERCISES_GEOMETRY_H
#define JIMP_EXERCISES_GEOMETRY_H

#include <iostream>
#include <cmath>

using namespace std;

class Point {
public:
    Point();
    Point(double x, double y);
    ~Point();

    void ToString(std::ostream *out) const;
    double Distance(const Point &other) const;

    double GetX() const;
    double GetY() const;

    void SetX(double x);
    void SetY(double y);
private:
    double x_, y_;
};

class Square {
public:
    Square();
    Square(Point A, Point B, Point C, Point D);
    ~Square();

    double Circumference(); //obwód
    double Area(); //pole powierzchni

private:
    Point A_;
    Point B_;
    Point C_;
    Point D_;

};

#endif //JIMP_EXERCISES_GEOMETRY_H
