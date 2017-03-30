//
// Created by Admin on 2017-03-30.
//

#include "GreatestProduct.h"

int GreatestProduct(const vector <int> &numbers, int k)
{
    //ustawiam max1 i max2 na najmniejsze mozliwe inty #include <limits>
    int max1 = numeric_limits<int>::min(), max2=numeric_limits<int>::min(), tmp;
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
    cout << max1 << max2 << endl;
    cout << max1*max2 << endl;
    return max1*max2;
}