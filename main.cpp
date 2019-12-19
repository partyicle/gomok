#include "main.hpp"
#include <iostream>

using namespace std;


int main(void){

    Gobang field;

    if(!field.initialize()) {return 1;}

    while(true){
        field.printMap();
        field.inputStone();
        if(field.judgeWin()){break;}
        field.flipTurn();
    }

    return 0;
};