//
// Created by Admin on 2017-04-11.
//

#include "WordCounter.h"

using namespace datastructures;

//konstruktory podklas
Word::Word(std::string str) {
    word = str;
}

Counts::Counts(int number) {
    counts = number;
}

//operatory podklas
//porownywanie wzgledem liczebnosci
bool Counts::operator<(const Counts &nana) const{
    return (counts < nana.counts);
}

bool Counts::operator>(const Counts &lala) const{
    return (counts > lala.counts);
}

bool Counts::operator==(const Counts &haha) const{
    return (counts == haha.counts);
}

//preinkrementacja ++
Counts &Counts::operator++() {
    counts++;
}

/*//postinkrementacja ++
Counts Counts::operator++(int){
    counts++;
}*/

//konstruktor klasy glownej
WordCounter::WordCounter() {
    int distinct = 0;
    int total = 0;
}

//konstruktor z lista inicjalizacyjna
WordCounter::WordCounter(std::initializer_list<Word> list_ini) {
    distinct = 0;
    total = 0;
    int check; //sprawdza czy slowo jest juz w liscie
    for (auto every_word : list_ini){
        total++;
        check = 1;
        for(std::pair<Word, Counts> &my_iterator : list_list) {
            if (list_list.empty()) break;
            else if (my_iterator.first.word == every_word.word) { //powtorzone
                //my_iterator.second.counts++; //normalnie
                ++my_iterator.second; //przeciazony operator preinkrementacji
                //my_iterator.second++; //przeciazony operator postinkrementacji
                check = 0;
                break;
            }
        }
        if(check){ //nowy na liscie
            Counts new_word{1};
            list_list.emplace_back(std::make_pair(every_word,new_word));
            distinct++;
        }
    }
    for(std::pair<Word, Counts> &iterator : list_list) {
        std::cout << iterator.first.word << " " << iterator.second.counts << std::endl;
    }
}

//operator klasy glownej []
int WordCounter::operator[](const std::string &gaga) {
    for(std::pair<Word, Counts> &iterator : list_list){
        if(iterator.first.word == gaga){
            return iterator.second.counts;
        }
    }
    return 0;
}

//funkcje zwracajace ilosc roznych i wszystkich slow
int WordCounter::DistinctWords() {
    return distinct;
}

int WordCounter::TotalWords() {
    return total;
}

//funkcja zwracajaca zbior roznych slow
std::set<Word> WordCounter::Words(){
    std::set<Word> my_set;
    for(auto &iterator_l : list_list){
        my_set.emplace(iterator_l.first);
    }
    return my_set;
}
