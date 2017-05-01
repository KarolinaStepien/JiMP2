//
// Created by Admin on 2017-04-11.
//

#ifndef JIMP_EXERCISES_WORDCOUNTER_H
#define JIMP_EXERCISES_WORDCOUNTER_H

#include <iostream>
#include <string>
#include <list>
#include <set>

namespace datastructures {

    class Word {
    public:
        friend class WordCounter;
        Word() {};
        Word(std::string str);
        ~Word() {};
        std::string word;
    };

    class Counts {
    public:
        friend class WordCounter;
        Counts() {};
        Counts(int number);
        ~Counts() {};
        bool operator <(const Counts &nana) const;
        bool operator >(const Counts &lala) const;
        bool operator ==(const Counts &haha) const;
        Counts &operator++();
        //Counts operator++(int);
    private:
        int counts;
    };

    class WordCounter {
    public:
        WordCounter();
        WordCounter(std::initializer_list<Word> list_ini);
        ~WordCounter() {};
        int operator[](const std::string &gaga);
        int DistinctWords();
        int TotalWords();
        std::set<Word> Words();
    private:
        int distinct;
        int total;
        std::list<std::pair<Word, Counts>> list_list;
    };
}
#endif //JIMP_EXERCISES_WORDCOUNTER_H
