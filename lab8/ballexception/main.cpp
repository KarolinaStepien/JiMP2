//
// Created by stepkaro on 25.04.17.
//

#include <iostream>

using namespace std;

class CircleException{
    // Oznacza ze nie mozna wyrysowac kola
};

class BallException : public CircleException{
    // Oznacza ze nie mozna wyrysowac kuli
};

void drawBall() {
    throw BallException();
}

int main(){
    try{
        drawBall();
    }catch(BallException b){
        cout << "Blad podczas rysowania kuli" << endl;
    }catch(CircleException a){
        cout << "Blad podczas rysowania kola" << endl;
    }
}

