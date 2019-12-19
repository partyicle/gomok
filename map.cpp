#include <iostream>
#include <vector>
#include "head.hpp"
#include "map.hpp"

using namespace std;

bool Map::setSize(int x, int y){
    try{
        if(x <= 0 || y <= 0) throw "underflow";
        if(x >= MAP_MAX_X || y >= MAP_MAX_Y) throw "overflow"; 

        this->size_x = x;
        this->size_y = y;
        return true;
    }
    catch(...){ return false; }
}

bool Map::resizeMap(){
    try{
        map.resize(this->size_x ,  vector<player>(this->size_y));

        for(size_t i=0; i<map.size(); i++){
            map[i % this->size_x][i / this->size_y] = EMPTY;
        }
    }
    catch(...) { return false; }

    return true;
}

void Map::printMap() {
    for(int x=0 ; x < this->size_x ; x++){
        cout << x;
    }
    cout << "\n";

    for(int y=0 ; y < this->size_y ; y++){
       for(int x=0 ; x < this->size_x ; x++){
           switch(this->map[x][y]){
                case BLACK:
                    cout << "O";
                    break;

                case WHITE:
                    cout << "X";
                    break;
                    
                case EMPTY:
                    cout << "┼";
           }

        }
        cout << " " << y << " \n";
    }
}

bool Map::initMap(){
    int a,b;

    while(true){
        cout << "mapsize X:";
        cin >> a;
        cout << "mapsize Y:";
        cin >> b;

        if(this->setSize(a,b)){ break; }
        else { cout << "Invalid input" << "\n"; }
    }

    if (!this->resizeMap()){
        cout << "malloc failed";
        return false;
    } 

    return true;
}
