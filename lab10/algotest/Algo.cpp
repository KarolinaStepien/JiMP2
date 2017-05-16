//
// Created by stepkaro on 16.05.17.
//

#include "Algo.h"

using namespace algo;

void Algo::SortInPlace(std::vector<int> *v){
    std::sort(v->begin(), v->end());
}

std::vector<int> Algo::Sort(const std::vector<int> &v){
    std::vector<int> l = v;
    std::sort(l.begin(), l.end());
    return l;
}

int Algo::Sum(const std::vector<int> &v){
    int sum = std::accumulate(v.begin(), v.end(), 0);
    return sum;
}

int Algo::Product(const std::vector<int> &v){
    int product = std::accumulate(v.begin(), v.end(), 1, std::multiplies<int>());
    return product;
}
