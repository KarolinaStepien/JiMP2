//
// Created by Admin on 2017-03-16.
//

#include "minimaltimedifference.h"

int main()
{
    int hours;
    string time_HH_MM;
    vector <string> times;
    //regex pattern {R"((\d{1,2})(\":")(\d{1,2}))"};
    cout << "Ile godzin chcesz wpisac?" << endl;
    cin >> hours;
    for(int i=0;i<hours;i++) {
        cout << "Wpisz godzine w formacie HH:MM" << endl;
        cin >> time_HH_MM;

        stringstream ss;
        unsigned int time_uint;
        string time_str;

        //wyslanie zmiennej typu unsigned int do string stream, po czym pobranie jej do zmiennej typu string
        time_uint = minimaltimedifference::ToMinutes(time_HH_MM);
        ss << time_uint;
        ss >> time_str;
        times.push_back(time_str);
    }
    cout << "Najmniejsza roznica czasu miedzy podanymi godzinami to " << minimaltimedifference::MinimalTimeDifference(times) << " minut";
    return 0;
}