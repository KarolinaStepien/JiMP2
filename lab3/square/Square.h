//
// Created by owsizofi on 21.03.17.
//

#ifndef JIMP_EXERCISES_SQUARE_H
#define JIMP_EXERCISES_SQUARE_H
#include "Point.h"
using namespace std;
class Square {
public:
    Square();

    Square(Point a, Point b, Point c, Point d);

    ~Square();
    double Point::Distance(const Point inny,const Point jeszcze_inny);

    double Square::Circumference(const Square &other) const;

    double Square::Area(const Square &other) const;

    Point GetA() const;

    Point GetB() const;

    Point GetC() const;

    Point GetD() const;

    void SetA(Point a);

    void SetB(Point b);
    void SetC(Point c);

    void SetD(Point d);

private:

    Point a_, b_, c_, d_;
};
#endif //JIMP_EXERCISES_SQUARE_H
