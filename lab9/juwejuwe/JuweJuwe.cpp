//
// Created by stepkaro on 09.05.17.
//

#include "Juwe.h"

Student::Student(){
    masa = 58;
    czas_picia = 6;
    stala_woda = 0.58;
}



bool ChlEbac(Plecak cos, Student ktos) {
    double ebac;
    ebac = ((9.672*cos.ilosc_napojow)/(ktos.stala_woda*ktos.masa))-0.17*ktos.czas_picia;
    return ebac < 0.2;
}

void Zakupy(Plecak cos, Student Zosia) {
    srand(time(NULL));

    while (cos.pojemnosc <= 20){
        int wybor = rand()%4;
        if (wybor == 1){
            SokPorzeczkowy tymbark;
            cos.produkty.emplace_back(tymbark);
            cos.pojemnosc += tymbark.obj;
        }
        if (wybor == 2){
            SunBites pomidorowe;
            cos.produkty.emplace_back(pomidorowe);
            cos.pojemnosc += pomidorowe.obj;
        }
        if (wybor == 3){
            Wóda żubrówka;
            cos.ilosc_napojow += (żubrówka.alko_gr/10);
            if(ChlEbac(cos, Zosia)){
                cos.produkty.emplace_back(żubrówka);
                cos.pojemnosc += żubrówka.obj;
            }
            else cos.ilosc_napojow -= (żubrówka.alko_gr/10);
        }
        if (wybor == 4){
            Piwerko żubr;
            cos.ilosc_napojow += (żubr.alko_gr/10);
            if(ChlEbac(cos, Zosia)){
                cos.produkty.emplace_back(żubr);
                cos.pojemnosc += żubr.obj;
            }
            else cos.ilosc_napojow -= (żubr.alko_gr/10);
        }

    }


}

