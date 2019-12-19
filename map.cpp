#include <iostream>
#include <vector>
#include "head.hpp"

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

bool Map::initialize(){
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
    for(int y=0 ; y < this->size_y ; y++){
       for(int x=0 ; x < this->size_x ; x++){
           switch(this->map[x][y]){
                case BLACK:
                    cout << "黒";
                    break;

                case WHITE:
                    cout << "白";
                    break;
                    
                case EMPTY:
                    if     (x==0 && y==0)                           cout << "┌";
                    else if(x==this->size_x-1 && y==0)              cout << "┐";
                    else if(x==0              && y==this->size_y-1) cout << "└";
                    else if(x==this->size_x-1 && y==this->size_y-1) cout << "┘";
                    else if(y==0)                                   cout << "┬";
                    else if(y==this->size_y-1)                      cout << "┴";
                    else if(x==0)                                   cout << "├";
                    else if(x==this->size_x-1)                      cout << "┤";
                    else                                            cout << "┼";
           }

        }
        cout << "\n";
    }
}
