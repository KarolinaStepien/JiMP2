//
// Created by zosiek on 23.05.17.
//

#ifndef JIMP_EXERCISES_JUWE_H
#define JIMP_EXERCISES_JUWE_H
#include "vector"
#include "iostream"
#include "functional"
#include "cstdlib"
#include "ctime"

class Student {
public:
    Student();
    ~Student(){};
    double masa;
    double czas_picia;
    double stala_woda;

    friend class Plecak;
};




class Zaopatrzenie{
public:
    double alko_gr;
    double obj;

};

class Plecak {
public:
    //Plecak(Zaopatrzenie &zaopatrzenie) : prowiant{&zaopatrzenie},pojemnosc{0}{}

    operator Zaopatrzenie&(){
        return *prowiant;
    }

    Zaopatrzenie *prowiant;
    double pojemnosc=0;
    double ilosc_napojow=0;
    friend class Student;
    std::vector <Zaopatrzenie> produkty;
    void PokazPlecak(){
            std::cout<<pojemnosc<<"  "<<ilosc_napojow<<std::endl;

    }

};

bool ChlEbac(Plecak cos, Student ktos);

void Zakupy (Plecak &cos, Student &ktos);



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

class Woda : public Zaopatrzenie{
public:
    Woda(){
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


