//
// Created by Admin on 2017-03-14.
//

#include "Polybius.h"

int main()
{
    //string plik_wej="", plik_wyj="";
    int parametr;
    /*cout << "Wpisz nazwe pliku wejsciowego: " << endl;
    cin >> plik_wej;
    cout << "Wpisz nazwe pliku wyjsciowego: " << endl;
    cin >> plik_wyj;*/
    cout << "Wpisz 1 zeby zaszyfrowac plik lub 0 zeby odszyfrowac plik" << endl;
    cin >>  parametr;

    if(parametr==1){

        ifstream input_file("crypt.txt"); //plik_wej
        ofstream output_file ("wyjsciowy.txt", ios_base::in | ios_base::app); //plik_wyj

        string word;

        if(!input_file || !output_file)
            cout << "Nie mozna otworzyc pliku" << endl;

        while(input_file >> word)
            //cout << PolybiusCrypt(word) << endl;
            output_file << PolybiusCrypt(word) << endl;

        input_file.close();
        output_file.close();
    }

    if(parametr==0){ // + te same zakomentowane linijki z if-a wyzej

        ifstream input_file("decrypt.txt"); //plik_wej
        ofstream output_file ("wyjsciowy.txt", ios_base::in | ios_base::app); //plik_wyj

        string word;

        if(!input_file || !output_file)
            cout << "Nie mozna otworzyc pliku" << endl;

        while(input_file >> word)
            output_file << PolybiusDecrypt(word) << endl;

        input_file.close();
        output_file.close();
    }
    return 0;
}
