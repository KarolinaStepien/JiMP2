//
// Created by stepkaro on 25.04.17.
//

#ifndef JIMP_EXERCISES_PESEL_H
#define JIMP_EXERCISES_PESEL_H

#include <string>
#include <iostream>

class PESEL {
public:
    PESEL(std::string p);
    ~PESEL(){};
    void validatePESEL(std::string p);
private:
    std::string number;
};

class PeselLength{

};

class PeselNumbers{

};


#endif //JIMP_EXERCISES_PESEL_H
