//
// Created by Admin on 2017-03-14.
//

#include "GreatestProduct.h"

int main()
{
    int cipher;
    vector <int> my_vector;
    cout << "Podaj liczby, z ktorych chcesz wybrac iloczyn i 0 zeby skonczyc: " << endl;
    do{
        cin >> cipher;
        my_vector.push_back(cipher);
    } while(cipher);

    cout << "Najwiekszy iloczyn to " << GreatestProduct(my_vector, 2);

    return 0;
}
