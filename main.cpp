#include "main.hpp"
#include <iostream>

using namespace std;


int main(void){

    Map field;
    int a,b;

    while(true){
        cout << "mapsize X:";
        cin >> a;
        cout << "mapsize Y:";
        cin >> b;

        if(field.setSize(a,b)){ break; }
        else { cout << "Invalid input"; }
    }

    if (!field.initialize()){
        cout << "malloc failed";
        return 1;
    } 

    while(true){
        field.printMap();
        break;
    }

    return 0;
};