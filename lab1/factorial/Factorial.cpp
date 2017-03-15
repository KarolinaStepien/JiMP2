//
// Created by Admin on 2017-03-15.
//

#include "Factorial.h"

int factorial(int value)
{
    if(value<-12||value>12){
        return 0;
    }
    if(value==0||value==1){
        return 1;
    }
    if(value>1 && value<13){
        return factorial(value-1)*value;
    }
    if(value<0 && value>-13){
        return factorial(value+1)*value;
    }
}