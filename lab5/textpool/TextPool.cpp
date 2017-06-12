//
// Created by zosia on 03.04.17.
//

#include "TextPool.h"

namespace pool {

    TextPool::TextPool(initializer_list<string> basen) {
        for (auto &it : basen) {
            this->basen.insert(it);
        }
    }

    TextPool::TextPool(TextPool &&nowy)  {
        swap(basen, nowy.basen);
    }

    TextPool &TextPool::operator=(TextPool &&nowy) {
        if (this == &nowy) {
            return nowy;
        }
        basen.clear();
        swap(basen, nowy.basen);
    }

    TextPool::~TextPool() {
        basen.clear();
    }

    std::experimental::string_view TextPool::Intern(const std::string &str) {
        
        bool dodaj = true;
        for (auto it = basen.begin(); it != basen.end(); ++it){
            if (*it == str){
                dodaj = false;
                return *it;
            }
        }
        if (dodaj){
            basen.insert(str);
            return str;
        }
    }

    size_t TextPool::StoredStringCount() const {
        return basen.size();
    }
}