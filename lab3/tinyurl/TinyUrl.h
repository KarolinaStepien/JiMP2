//
// Created by Admin on 2017-03-21.
//

#ifndef JIMP_EXERCISES_TINYURL_H
#define JIMP_EXERCISES_TINYURL_H

#include <utility>
#include <string>
#include <array>
#include <memory>
#include <iostream>

using namespace std;

namespace tinyurl {

//    unique_ptr<TinyUrlCodec> Init();
    void NextHash(array<char, 6> *state);
//    string Encode(const string &url, unique_ptr<TinyUrlCodec> *codec);
//    string Decode(const unique_ptr<TinyUrlCodec> &codec, const string &hash);
}

#endif //JIMP_EXERCISES_TINYURL_H
