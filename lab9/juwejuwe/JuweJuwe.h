//
// Created by stepkaro on 09.05.17.
//

#ifndef JIMP_EXERCISES_JUWEJUWE_H
#define JIMP_EXERCISES_JUWEJUWE_H



class Student {
public:
    int masa;
    int czas_picia;
    int stala_woda;

    friend class Plecak;
};

class Plecak {
public:
    Plecak(Zaopatrzenie &zaopatrzenie) : prowiant{&zaopatrzenie}{
        pojemnosc = 20;
    }

    operator Zaopatrzenie&(){
        return *prowiant;
    }

    Zaopatrzenie *prowiant;
    int pojemnosc;
    int ilosc_napojow;
    friend class Student;
};

bool ChlEbac(Plecak cos, Student ktos);

void Zakupy (Plecak cos, Student ktos);

class Zaopatrzenie{
public:
    double alko_gr;
    double obj;

};

class SokPorzeczkowy : public Zaopatrzenie{
    SokPorzeczkowy(){
        alko_gr = 0;
        obj = 2;
    }

};

class SunBites : public Zaopatrzenie{
    SunBites(){
        alko_gr = 0;
        obj = 0.5;
    }

};

class Wóda : public Zaopatrzenie{
    Wóda(){
        alko_gr = 200;
        obj = 0.5;
    }

};

class Piwerko : public Zaopatrzenie{
    Piwerko(){
        alko_gr = 25;
        obj = 0.5;
    }
};

#endif //JIMP_EXERCISES_JUWEJUWE_H
