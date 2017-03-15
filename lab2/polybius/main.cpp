//
// Created by Admin on 2017-03-10.
//

#include "Polybius.h"

string PolybiusDecrypt(string message);
string PolybiusCrypt(string crypt);


int main(){
    cout << "Podaj nazwe pliku do odszyfrowania/zaszyfrowania: ";
    string file1="", file2="", word="";
    int choice;
    cin >> file1;
    cout << "Podaj nazwe pliku do zapisania: ";
    cin >> file2;
    ifstream input_file(file1);
    ofstream output_file (file2, ios_base::in | ios_base::app);
    if (!input_file)
        cout >> "Nie mozna otworzyc pliku :(.";
    if (!output_file)
        cout >> "Nie mozna otworzyc pliku :(.";
    cout << "Jesli chcesz zaszyfrowac wpisz 1, a jak odszyfrowac - 0: ";
    if (choice){
        while (input_file >> word)
            output_file << PolybiusCrypt(word);
    }
    else{
        while (input_file >> word)
            output_file << PolybiusDecrypt (word);
    }
    return 0;
}