//
// Created by zosiek on 12.06.17.
//

#ifndef JIMP_EXERCISES_SEQUENTIALGENERATOR_H
#define JIMP_EXERCISES_SEQUENTIALGENERATOR_H

#include <iostream>

template<class T, class U>
class SequentialIdGenerator {
    U id_;
    bool first_;
public:
    SequentialIdGenerator(){
        id_=0;
        first_=true;
    };
    ~SequentialIdGenerator(){};
    SequentialIdGenerator(U id):id_{id},first_{true}{};
    operator int() {return int(id_);}
    int NextValue(){
        if(first_){
            first_=false;
            return int(id_);
        }
        else{
            ++id_;
            return int(id_);
        }
    }
};

#endif //JIMP_EXERCISES_SEQUENTIALGENERATOR_H
