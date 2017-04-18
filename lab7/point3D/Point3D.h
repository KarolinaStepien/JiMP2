//
// Created by stepkaro on 11.04.17.
//

#ifndef JIMP_EXERCISES_POINT3D_H
#define JIMP_EXERCISES_POINT3D_H

#include <iostream>

using namespace std;

class Point {
public:
    Point();
    Point(double x, double y);
    ~Point();

    double Distance(const Point &other) const;

    double GetX() const;
    double GetY() const;

    void SetX(double x);
    void SetY(double y);

private:
    double x_, y_;
};
//3D
class Point3D: public Point{
public:
    Point3D();
    Point3D(double x, double y, double z);
    ~Point3D();
    double GetZ() const;
    double Distance(const Point3D &other) const;
private:
    double z_;
};

istream& operator>>(istream & is, Point & point);
ostream& operator<<(ostream & os, Point & point);

#endif //JIMP_EXERCISES_POINT3D_H
