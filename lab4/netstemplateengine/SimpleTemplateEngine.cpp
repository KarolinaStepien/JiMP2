//
// Created by Admin on 2017-03-28.
//

#include "SimpleTemplateEngine.h"

using nets::View;

//konstruktory
View::View() : nana("") {}
View::View(string nana_) {
    this->nana = nana_;
}
View::~View() {}

//funkcja
string View::Render(const unordered_map <string, string> &model) const {
    string lala = nana;
    string rara = "";
    regex pattern {R"(\{\{\w+\}\})"};
    smatch matches;

    while (regex_search (lala, matches, pattern)) {
        for (auto match : matches) {
            string sub = match.str(); //match to string {{name}}
            sub = sub.substr(2, sub.length()-4); //name
            rara += matches.prefix().str();
            if (model.find(sub) != model.end()) {
                //rara += model.at(sub); lub kolejne 3 linijki :)
                string next; //drugi element mapy
                next = model.find(sub)->second;
                rara += next;
            }
        }
        lala = matches.suffix().str();
    }
    rara += lala;
    return rara;
}