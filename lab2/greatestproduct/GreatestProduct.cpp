//
// Created by Admin on 2017-03-14.
//

#include "GreatestProduct.h"

int GreatestProduct(const vector <int> &numbers, int k)
{
    int max1=numbers[0], max2=numbers[0], tmp;
    for(int v : numbers)
    {
        if(v>max1){
            max1 = v;
        }
        if(max2<max1){
            tmp = max2;
            max2 = max1;
            max1 = tmp;
        }
    }

    return max1*max2;
}
