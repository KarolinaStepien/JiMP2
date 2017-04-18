//
// Created by Admin on 2017-04-18.
//

#ifndef JIMP_EXERCISES_SHAPE_H
#define JIMP_EXERCISES_SHAPE_H

#include <iostream>
#include <cstdlib>
#include <vector>
#include <ctime>
using namespace std;

//klasa abstrakcyjna
class Shape{
public:
    virtual ~Shape(){}
    virtual void Draw() =0; //metoda wirtualna
};

//klasy dziedziczace
class Circle : public Shape{
public:
    virtual void Draw();
};

class Square : public Shape{
public:
    virtual void Draw();
};

class BrokenHeart : public Shape{
public:
    virtual void Draw();
};

#endif //JIMP_EXERCISES_SHAPE_H
