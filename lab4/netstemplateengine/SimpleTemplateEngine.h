//
// Created by Admin on 2017-03-28.
//

#ifndef JIMP_EXERCISES_SIMPLETEMPLATEENGINE_H
#define JIMP_EXERCISES_SIMPLETEMPLATEENGINE_H

#include <iostream>
#include <regex>
#include <string>
#include <unordered_map>
using namespace std;

namespace nets {
    class View {
    public:
        View();
        View(string nana_);
        ~View();
        string Render(const unordered_map <string, string> &model) const;
    private:
        string nana;
    };
}
#endif //JIMP_EXERCISES_SIMPLETEMPLATEENGINE_H
