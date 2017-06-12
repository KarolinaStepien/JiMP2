//
// Created by Admin on 2017-03-21.
//

#include "TinyUrl.h"

namespace tinyurl{

    void NextHash(std::array<char, 6> *state) {
        int it[6];
        for(int i=0;i<6;i++) {
            it[i] = (*state)[i];
        }
        it[5]++;
        for(int i=5;i>=0;i--) {
            if(it[i]==91) {
                it[i]=97;
                break;
            }
            if(it[i]==58) {
                it[i]=65;
                break;
            }
            if(it[i]==123 && i!=0) {
                it[i]=48;
                it[i-1]++;
            }
        }
        for(int i=0;i<6;i++) {
            (*state)[i] = char(it[i]);
        }
    }
}
