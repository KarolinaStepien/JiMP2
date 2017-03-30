//
// Created by Admin on 2017-03-30.
//

#include "GreatestProduct.h"

int main()
{
    string what_i_get;
    vector <int> my_vector;
    cout << "Podaj liczby, z ktorych chcesz wybrac iloczyn i 0 zeby skonczyc: " << endl;
    getline(cin,what_i_get);
    while(true){
        if(what_i_get.length()!=0){
            stringstream ss;
            ss << what_i_get;
            int cipher;
            ss >> cipher;
            my_vector.push_back(cipher);
            getline(cin,what_i_get);
        }
        else {
            break;
        }
    }
    cout << "Najwiekszy iloczyn to " << GreatestProduct(my_vector, 2);

    return 0;
}