//
// Created by Admin on 2017-03-31.
//

#ifndef JIMP_EXERCISES_SQUARE_H
#define JIMP_EXERCISES_SQUARE_H

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

#endif //JIMP_EXERCISES_SQUARE_H
