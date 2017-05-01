//
// Created by Admin on 2017-04-11.
//

#ifndef JIMP_EXERCISES_WORDCOUNTER_H
#define JIMP_EXERCISES_WORDCOUNTER_H

#include <iostream>
#include <string>
#include <list>

namespace datastructures {

    class Word {
    public:
        friend class WordCounter;
        Word() {};
        Word(std::string str);
        ~Word() {};
    private:
        std::string word;
    };

    class Counts {
    public:
        friend class WordCounter;
        Counts() {};
        Counts(int number);
        ~Counts() {};
    private:
        int counts;
    };

    class WordCounter {
    public:
        WordCounter();
        WordCounter(std::initializer_list<Word> list_ini);
        ~WordCounter() {};
    private:
        int all_words;
        int all_numbers;
        std::list<std::pair<Word, Counts>> list_list;
    };
}
#endif //JIMP_EXERCISES_WORDCOUNTER_H
