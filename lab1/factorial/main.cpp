//
// Created by Admin on 2017-03-14.
//

#include <iostream>
#include "Factorial.h"

int main()
{
    int number;
    cout << "enter a number:" << endl;
    cin >> number;
    cout << "factorial of " << number << " is " << factorial(number);
    return 0;
}