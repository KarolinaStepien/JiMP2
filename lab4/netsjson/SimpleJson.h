//
// Created by zosia on 03.04.17.
//

#ifndef JIMP_EXERCISES_SIMPLEJSON_H
#define JIMP_EXERCISES_SIMPLEJSON_H

#include <string>
#include <iostream>
#include <vector>
#include <map>
#include "SimpleJson.h"
#include <experimental/optional>
#include <string>

using namespace std;

namespace nets{

    class JsonValue {
        experimental::optional<int> liczba;
        experimental::optional<double> dluga_liczba;
        experimental::optional<string> lancuch;
        experimental::optional<bool> logiczna;
        experimental::optional<vector<JsonValue>> wektor;
        map<string, JsonValue> mapa;

    public:
        JsonValue(int costam);
        JsonValue(double costam);
        JsonValue(string costam);
        JsonValue(bool costam);
        JsonValue(vector<JsonValue> costam);
        JsonValue(map<string, JsonValue> costam);
        ~JsonValue();
        string ToString() const;
        experimental::optional<JsonValue> ValueByName(const std::string &name) const;
    };
}

#endif //JIMP_EXERCISES_SIMPLEJSON_H
