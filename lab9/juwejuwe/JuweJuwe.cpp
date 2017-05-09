//
// Created by stepkaro on 09.05.17.
//

#include "JuweJuwe.h"

bool ChlEbac(Plecak cos, Student ktos) {
    double ebac;
    ebac = ((9.672*cos.ilosc_napojow)/(ktos.stala_woda*ktos.masa))-0.17*ktos.czas_picia;
    return ebac < 0.2;
}

void Zakupy(Plecak cos, Student ktos) {

    int produkt;


}

