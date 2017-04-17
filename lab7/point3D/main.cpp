//
// Created by stepkaro on 11.04.17.
//

#include "Point3D.h"

int main(void){
    //Point punkt2d(2,3);
    //Point3D punkt3d(2,7,1);
    Point3D punkt3d2(2,10,5);
    //cout << "Odległość między punktami 2d i 3d wynosi " << punkt2d.Distance(punkt3d) << endl;
    //cout << "Odległość między dwoma punktami 3d wynosi " << punkt3d.Distance(punkt3d2) << endl;
    Point3D punkt3d3;
    cin >> punkt3d3; //pozwala na wpisanie danych w formie (a,b)
    cout << "Odległość między dwoma punktami 3d wynosi " << punkt3d2.Distance(punkt3d3) << endl;
    //cout << punkt3d3 << endl;
    return 0;
}

/*zadanie 5:
                            KONSTRUKTORY NAJPIERW 2D, POTEM 3D
Konstruktor parametrowy 2d!

Konstruktor parametrowy 2d!
Konstruktor parametrowy 3d!

Konstruktor parametrowy 2d!
Konstruktor parametrowy 3d!
                            DESTRUKTORY NAJPIERW 3D, POTEM 2D
Destruktor 3d!
Destruktor 2d!

Destruktor 3d!
Destruktor 2d!

Destruktor 2d!

zadanie 6:

Dla punkt2d.distance(punkt3d) policzona odleglosc tylko miedzy pierwszymi dwoma wspolrzednymi
Dla punkt3d.distance(punkt3d) policzona odleglosc miedzy wszystkimi trzema wspolrzednymi
*/
