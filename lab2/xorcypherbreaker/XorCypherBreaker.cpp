//
// Created by Admin on 2017-03-14.
//

#include "XorCypherBreaker.h"

string XorCypherBreaker(const vector<char> &cryptogram, int key_length,
                        const vector<string> &dictionary) {
    int counter_max = -10, counter = 0; // sprawdzi przy którym kluczu najwiecej słów pasuje
    string key_word = "", key_tmp = "   ";
    vector<char> decrypt;
    for (int i = 97; i <= 122; i++) {
        for (int j = 97; j <= 122; j++) {
            for (int k = 97; k <= 122; k++) {
                int l=0;

                key_tmp[0] = (char)(i);
                key_tmp[1] = (char)(j);
                key_tmp[2] = (char)(k);
                string word = "";

                for (int m :  cryptogram) { //zmienna iterujaca po wektorze z kryptogramem
                    char letter = (char) (key_tmp[l % key_length] xor m); //stosujemy tymczasowy klucz

                    if ((letter >= 97) && (letter <= 122) || ((letter >= 65) && (letter <=90 ))) {
                        word += letter;
                    }
                    else {
                        if (word.length() > 2){
                            transform(word.begin(), word.end(), word.begin(), ::tolower);
                            if (find(dictionary.begin(), dictionary.end(), word) != dictionary.end()) {
                                counter ++;
                            }
                        }
                        word = "";
                    }
                    l++;
                }
                if (counter >= counter_max) {
                    counter_max = counter;
                    key_word = key_tmp;
                }
                counter =0;
            }
        }
    }
    return key_word;
}