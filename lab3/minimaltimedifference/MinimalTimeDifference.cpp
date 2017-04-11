//
// Created by Admin on 2017-03-16.
//

#include "MinimalTimeDifference.h"

namespace minimaltimedifference {

    unsigned int ToMinutes(string time_HH_MM) {
        long length = time_HH_MM.length();
        string hour_string, just_hour, minute_string, just_minute;
        unsigned int number_h, number_m;

        for (int i = 0; i < length; i++) {
            if (time_HH_MM[i] != ':') {
                just_hour = time_HH_MM[i];
                hour_string.append(just_hour);
            } else {
                for (int j = 0; j < 2; j++) {
                    just_minute = time_HH_MM[i + j + 1];
                    minute_string.append(just_minute);

                }
                break;
            }
        }
        //zamiana string -> int
        sscanf(hour_string.c_str(), "%d", &number_h);
        sscanf(minute_string.c_str(), "%d", &number_m);
        return number_h * 60 + number_m;
    }

    unsigned int MinimalTimeDifference(vector<string> times) {
        unsigned int difference = 24 * 60;
        vector<unsigned int> times_int;

        // stworzenie nowego wektora unsigned int i przepisanie do niego wartosci z wektora typu string
        for (string t : times) {
            unsigned int t_int;
            sscanf(t.c_str(), "%d", &t_int);
            times_int.push_back(t_int);
        }
        // kazdy element porownujemy ze wszystkimi po nim i szukamy najmniejszej roznicy czasow
        for (int i = 0; i < times_int.size(); i++) {
            for (int j = 0; j < times_int.size(); j++) {
                if (i != j) {
                    unsigned int d = times_int[i] - times_int[j]; //d przechowuje aktualna roznice
                    if (d >= 0 && d <= 12 * 60) {
                        if (d < difference) {
                            difference = d;
                        }
                    } else if (d > 12 * 60) {
                        d = 24 * 60 - d;
                        if (d < difference) {
                            difference = d;
                        }
                    }
                }
            }
        }

        return difference;
    }
}