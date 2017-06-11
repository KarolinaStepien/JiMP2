//
// Created by zosiek on 11.06.17.
//

#ifndef JIMP_EXERCISES_TIMERECORDER_H
#define JIMP_EXERCISES_TIMERECORDER_H
#include <iostream>
#include <chrono>

using namespace std;
namespace profiling
{
    template<class T>

    auto TimeRecorder(T nana)    {
        chrono::time_point<chrono::system_clock> start, stop;
        start = chrono::system_clock::now();
        nana();
        stop = chrono::system_clock::now();

        chrono::duration<double> time = (stop - start);

        return pair<decltype(nana()), double> {nana(), time.count()*1000.f};

    };
}

#endif //JIMP_EXERCISES_TIMERECORDER_H