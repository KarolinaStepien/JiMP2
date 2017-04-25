//
// Created by stepkaro on 11.04.17.
//

#include "Point3D.h"

int main(void){
    Point punkt2d(2,3);
    Point3D punkt3d(2,7,1);
    Point3D punkt3d2(2,10,5);
    cout << endl << "Odległość między punktami 2d (2,3) i 3d (2,7,1) wynosi " << punkt2d.Distance(punkt3d) <<
         " <- liczy tylko pierwsze 2 wspolrzedne" << endl;
    cout << "Odległość między dwoma punktami 3d (2,7,1) i (2,10,5) wynosi " << punkt3d.Distance(punkt3d2) <<
         " <- liczy wszystkie 3 wspolrzedne" << endl << endl;
    Point3D punkt3d3;
    cout << endl << "Wpisz wspolrzedne punktu w formie (a,b,c):" << endl;
    cin >> punkt3d3; //przeciazony operator istream
    cout << "Odległość między dwoma punktami 3d wynosi " << punkt3d2.Distance(punkt3d3) << " <- dziala OK" << endl;
    cout << "Punkt 3d2 ma wspolrzedne: " << punkt3d2 << endl << endl; //przeciazony operator ostream
    return 0;
}

/*zadanie 5:
                            KONSTRUKTORY NAJPIERW 2D, POTEM 3D,
                            poniewaz obiekty klasy Point3D sa rownoczesnie obiektami klasy Point, po ktorej dziedzicza
Konstruktor parametrowy 2d!

Konstruktor parametrowy 2d!
Konstruktor parametrowy 3d!
                            DESTRUKTORY NAJPIERW 3D, POTEM 2D,
                            czyli usuwanie wykonuje sie w odwrotnej kolejnosci niz konstruowanie
Destruktor 3d!
Destruktor 2d!

Destruktor 2d!

zadanie 6:

Dla punkt2d.distance(punkt3d) policzona odleglosc tylko miedzy pierwszymi dwoma wspolrzednymi
Dla punkt3d.distance(punkt3d) policzona odleglosc miedzy wszystkimi trzema wspolrzednymi

zadanie 7:

Wypisanie cout << punkt3d2; daje w efekcie pierwsze 2 wspolrzedne punktu 3d w postaci (a,b)
*/
