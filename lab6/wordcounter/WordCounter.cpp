//
// Created by Admin on 2017-04-11.
//

#include "WordCounter.h"

using namespace datastructures;

Word::Word(std::string str) {
    word = str;
}

Counts::Counts(int number) {
    counts = number;
}

WordCounter::WordCounter() {
    int all_words = 0;
    int all_numbers = 0;
}

WordCounter::WordCounter(std::initializer_list<Word> list_ini) {
    all_words = 0;
    all_numbers = 0;
    int check;
    for (auto every_word : list_ini){
        //std::cout << "kazde slowo z listy ini" << std::endl;
        check = 1;
        for(std::pair<Word, Counts> &my_iterator : list_list) {
            //std::cout << "kazda para z listy listy" << std::endl;
            if (list_list.empty()) break;
            else if (my_iterator.first.word == every_word.word) {
                //std::cout << "powtorzone" << std::endl;
                my_iterator.second.counts++;
                //std::cout << my_iterator.first.word << " " << my_iterator.second.counts << std::endl;
                check = 0;
                break;
            }
        }
        if(check){
            //std::cout << "nowy na liscie" << std::endl;
            Counts new_word{1};
            list_list.emplace_back(std::make_pair(every_word,new_word));
            //std::cout <<  every_word.word << " " << new_word.counts << std::endl;
        }
    }
    for(std::pair<Word, Counts> &iterator : list_list) {
        std::cout << iterator.first.word << " " << iterator.second.counts << std::endl;
    }
}