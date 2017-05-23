//
// Created by stepkaro on 09.05.17.
//

#ifndef JIMP_EXERCISES_JUWE_H
#define JIMP_EXERCISES_JUWE_H
#include "vector"
#include "iostream"
#include "functional"
#include "cstdlib"
#include "ctime"

class Student {
    Student();
    ~Student(){};
public:
    double masa;
    double czas_picia;
    double stala_woda;

    friend class Plecak;
};

class Plecak {
public:
    Plecak(Zaopatrzenie &zaopatrzenie) : prowiant{&zaopatrzenie}{
        pojemnosc = 0;
    }

    operator Zaopatrzenie&(){
        return *prowiant;
    }

    Zaopatrzenie *prowiant;
    int pojemnosc=0;
    int ilosc_napojow=0;
    friend class Student;
    std::vector <std::reference_wrapper<Zaopatrzenie>> produkty;
};

bool ChlEbac(Plecak cos, Student ktos);

void Zakupy (Plecak cos, Student ktos);

class Zaopatrzenie{
public:
    double alko_gr;
    double obj;

};

class SokPorzeczkowy : public Zaopatrzenie{
public:
    SokPorzeczkowy(){
        alko_gr = 0;
        obj = 2;
    }

};

class SunBites : public Zaopatrzenie{
public:
    SunBites(){
        alko_gr = 0;
        obj = 0.5;
    }

};

class Wóda : public Zaopatrzenie{
public:
    Wóda(){
        alko_gr = 200;
        obj = 0.5;
    }

};

class Piwerko : public Zaopatrzenie{
public:
    Piwerko(){
        alko_gr = 25;
        obj = 0.5;
    }
};

#endif //JIMP_EXERCISES_JUWEJUWE_H


#endif //JIMP_EXERCISES_JUWE_H
