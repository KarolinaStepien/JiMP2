//
// Created by stepkaro on 16.05.17.
//

#include "Algo.h"

using namespace algo;

int main() {
    std::vector<int> v = {1, 4, 9, 7, 2};
    Algo::SortInPlace(&v);
    for (auto a : v) {
        std::cout << a << " ";
    }
    std::cout<<std::endl;

    std::vector<int> k = {0, 0, 0, 0, 0};
    k = Algo::Sort(v);
    for (auto a : k) {
        std::cout << a << " ";
    }
    std::cout<<std::endl;

    int l;
    l = Algo::Sum(v);
    std::cout<<l<<std::endl;

    int m;
    m = Algo::Product(v);
    std::cout<<m<<std::endl;
}