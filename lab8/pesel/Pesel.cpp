//
// Created by stepkaro on 25.04.17.
//

#include "Pesel.h"

PESEL::PESEL(std::string p) {
    number = p;
    validatePESEL(p);
}

void PESEL::validatePESEL(std::string p) {
    if(p.length()!=11) throw PeselLength();
    else{
        for(int i=0;i<p.length();i++){
            if(p[i]<48||p[i]>57) throw PeselNumbers();
        }
    }
}
