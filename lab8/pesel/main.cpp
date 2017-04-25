//
// Created by stepkaro on 25.04.17.
//

#include "Pesel.h"

int main(){
    std::string nana = "971122a4203";
    try{
        PESEL moj(nana);
    }catch(PeselLength a) {
        std::cout << "Blad dlugosci peselu" << std::endl;
    }catch(PeselNumbers b){
        std::cout << "Blad numerkow peselu" << std::endl;
    }catch(...){
        std::cout << "Inny blad" << std::endl;
    }
    return 0;
}