//
// Created by zosiek on 23.05.17.
//

#include "Juwe.h"

Student::Student(){
    masa = 58;
    czas_picia = 6;
    stala_woda = 0.58;
}



bool ChlEbac(Plecak cos, Student ktos) {
    double ebac;
    ebac = ((0.9672*cos.ilosc_napojow)/(ktos.stala_woda*ktos.masa))-0.17*ktos.czas_picia;

   // std:: cout<<cos.ilosc_napojow<<"  "<<ebac<<std::endl;
    return ebac < 0.2;
}

void Zakupy(Plecak &cos, Student &Zosia) {
    srand(time(NULL));

    while (cos.pojemnosc < 20){
        int wybor;
        wybor = rand()%4;

        if (wybor == 1){
            SokPorzeczkowy tymbark;
            cos.produkty.push_back(tymbark);
            cos.pojemnosc += tymbark.obj;
            //std::cout<<"1: " <<cos.ilosc_napojow<<std::endl;
        }
        if (wybor == 2){
            SunBites pomidorowe;
            cos.produkty.push_back(pomidorowe);
            cos.pojemnosc += pomidorowe.obj;
            //std::cout<<"2: " <<cos.ilosc_napojow<<std::endl;
        }
        if (wybor == 3){
            Woda zubrowka;
            cos.ilosc_napojow += (zubrowka.alko_gr/10);
            if(ChlEbac(cos, Zosia)){
                cos.produkty.push_back(zubrowka);
                cos.pojemnosc += zubrowka.obj;
            }
            else cos.ilosc_napojow -= (zubrowka.alko_gr/10);
          //  std::cout<<"3: " <<cos.ilosc_napojow<<std::endl;
        }
        if (wybor == 0){
            Piwerko zubr;
            cos.ilosc_napojow += (zubr.alko_gr/10);
            if(ChlEbac(cos, Zosia)){
                cos.produkty.push_back(zubr);
                cos.pojemnosc += zubr.obj;
            }
            else cos.ilosc_napojow -= (zubr.alko_gr/10);
            //std::cout<<"0: " <<cos.ilosc_napojow<<std::endl;
        }

    }



}
