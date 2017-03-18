//
// Created by Admin on 2017-03-16.
//

#ifndef JIMP_EXERCISES_MINIMALTIMEDIFFERENCE_H
#define JIMP_EXERCISES_MINIMALTIMEDIFFERENCE_H

#include <vector>
#include <sstream>
#include <regex>
#include <cmath>
#include <string>
#include <regex>
#include <iostream>
#include <cstdlib>

using namespace std;

namespace minimaltimedifference
{
    unsigned int ToMinutes(string time_HH_MM);
    unsigned int MinimalTimeDifference(vector<string> times);
}

#endif //JIMP_EXERCISES_MINIMALTIMEDIFFERENCE_H
