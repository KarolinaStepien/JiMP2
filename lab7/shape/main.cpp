//
// Created by Admin on 2017-04-18.
//

#include "Shape.h"

int main(){
    list <Shape *> list; //lista wskaznikow na obiekty klas
    srand( time( NULL ) ); //uzupelniania losowymi ksztaltami
    for(int i=0; i<10; i++){
        int number = rand()%4+1;
        Shape * shape;
        switch (number){
            case 1:
                shape = new Circle();
                break;
            case 2:
                shape = new Square();
                break;
            default:
                shape = new BrokenHeart();
                break;
        }
        list.push_back(shape);
    }
    //rysowanie elementow tablicy
    for(Shape * j : list){            //Dla kazdego elementu listy funkcja Draw rysuje
        j->Draw();                    //dany obiekt, inny dla kazdej klasy
    }
    //czyszczenie listy
    list.clear();

    return 0;
}