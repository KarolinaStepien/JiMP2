//
// Created by Admin on 2017-04-18.
//

#include "Shape.h"

int main(){
    Shape * tab[10]; //tablica wskaznikow na obiekty klas
    srand( time( NULL ) ); //uzupelniania losowymi ksztaltami
    for(int i=0; i<10; i++){
        int number = rand()%4+1;
        Shape * shape;
        switch (number){
            case 1:
                shape = new Circle();
                tab[i] = shape;
                break;
            case 2:
                shape = new Square();
                tab[i] = shape;
                break;
            default:
                shape = new BrokenHeart();
                tab[i] = shape;
                break;
        }
    }
    //rysowanie elementow tablicy
    for(int j=0; j<10; j++){            //Dla kazdego elementu tablicy funkcja Draw rysuje
        tab[j]->Draw();                 //dany obiekt, inny dla kazdej klasy
    }
    //zwalnianie pamieci
    for(int k=0; k<10; k++){
        delete tab[k];
    }
    delete[] tab;

    /*Shape * shape1 = new Circle(), * shape2 = new Square(), * shape3 = new BrokenHeart();
    shape1->Draw();
    shape2->Draw();
    shape3->Draw();
    delete shape1;
    delete shape2;
    delete shape3;*/

    return 0;
}