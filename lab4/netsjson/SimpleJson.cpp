//
// Created by zosia on 03.04.17.
//

#include "SimpleJson.h"

//using namespace std;

nets::JsonValue::JsonValue(int costam) {
    liczba = costam;
}

nets::JsonValue::JsonValue(double costam) {
    dluga_liczba = costam;
}

nets::JsonValue::JsonValue(std::string costam) {
    lancuch = costam;
}

nets::JsonValue::JsonValue(bool costam) {
    logiczna = costam;
}

nets::JsonValue::JsonValue(std::vector<nets::JsonValue> costam) {
    wektor = costam;
}

nets::JsonValue::JsonValue(std::map<std::string, nets::JsonValue> costam) {
    mapa = costam;
}

nets::JsonValue::~JsonValue() {
    cout << "Do widzenia.";
}

std::string nets::JsonValue::ToString() const {
    if (liczba){
        return std::to_string(*liczba);
    }
    else if (lancuch) "\"" + *lancuch + "\"";
    else if (dluga_liczba) return std::to_string(*dluga_liczba);
    else if (logiczna){
        if (*logiczna) return "true";
        else return "false";
    }
    else if (wektor){
        string wektorek = "";
        for (auto &n : *wektor) wektorek += (", " + n.ToString());
        wektorek+="]";
        wektorek = wektorek.substr(1);
        wektorek[0] = '[';
        return wektorek;
    }
    else if (&mapa != nullptr){
        string mapka = "{";
        for (auto &n : mapa){
            string tmp = n.first;
            for (int i = 0; i<tmp.length();i++){
                if (tmp[i] == '\"' || tmp[i] == '\\'){
                    tmp.insert(i,1,'\\');
                    i++;
                }
            }
            mapka = mapka + "\"" + tmp + "\": "+n.second.ToString()+", ";
        }
        mapka[mapka.size()-2]='}';
        mapka.pop_back();
        return mapka;
    }
}

std::experimental::optional<nets::JsonValue> nets::JsonValue::ValueByName(const std::string &name) const {
    for (auto &n: mapa){
        if (n.first == name) return n.second;
    }
}