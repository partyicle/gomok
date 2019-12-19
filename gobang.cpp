#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include "head.hpp"
#include "gobang.hpp"

using namespace std;
bool Gobang::initialize(){
    this->turn = BLACK;
    this->turnCount = 0;

    return this->initMap();
}

void Gobang::flipTurn(){
    if (this->turn == BLACK) this->turn = WHITE;
    else this->turn = BLACK;
    this->turnCount++;
}

bool Gobang::setStone(int x,int y){
    if (x < 0 || y < 0 || x >= this->size_x || y >= this->size_y) { return false;}
    if (this->map[x][y] != EMPTY) { return false; }

    this->map[x][y] = this->turn;
    return true;
}

bool Gobang::initMap(){
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
        cout << "resize failed";
        return false;
    } 

    return true;
}

bool Gobang::inputStone(){
    int a,b;

    while(true){
        cout << (this->turn==BLACK ? "Black" : "White") << " Turn.\n";
        cout << "X:";
        cin >> a;
        cout << "Y:";
        cin >> b;

        if(this->setStone(a,b)){ break; }
        else { cout << "Invalid input" << "\n"; }
    }

    return true;
}

bool Gobang::isWinner_linear(vector<player> line){
    int nowCombo=0;
    vector<int> combo;

    for(size_t i=0; i<line.size(); i++){
        if(line[i] == this->turn) {
            nowCombo++;
        }else{        
            combo.push_back(nowCombo);
            nowCombo=0;
        }
    }
    combo.push_back(nowCombo);
    sort(combo.begin(), combo.end(), greater<int>());

    if(combo[0] >= WIN_COMBO) { return true;}
    return false;
}

bool Gobang::isWinner(){
    vector<player> checkLine;
    checkLine.resize(0);

    //横
    for(int y=0 ; y < this->size_y ; y++){
        for(int x=0 ; x < this->size_x ; x++){
            checkLine.push_back(this->map[x][y]);
        }
        if(isWinner_linear(checkLine)) {return true;}
        checkLine.resize(0);
    }

    //縦
    for(int x=0 ; x < this->size_x ; x++){
        for(int y=0 ; y < this->size_y ; y++){
            checkLine.push_back(this->map[x][y]);
        }
        if(isWinner_linear(checkLine)) {return true;}
        checkLine.resize(0);
    }

    //右下-左辺
    for(int y=0 ; y < this->size_y ; y++){
        for(int x=0 ; x < this->size_x && y+x < this->size_y; x++){
            checkLine.push_back(this->map[x][y+x]);
        }
        if(isWinner_linear(checkLine)) {return true;}
        checkLine.resize(0);
    }
    //右下-上辺
    for(int x=1 ; x < this->size_x ; x++){
        for(int y=0 ; y < this->size_y && x+y < this->size_x; y++){
            checkLine.push_back(this->map[x+y][y]);
        }
        if(isWinner_linear(checkLine)) {return true;}
        checkLine.resize(0);
    }

    //右上-左辺
    for(int y=0 ; y < this->size_y ; y++){
        for(int x=0 ; (x < this->size_x) && (y-x >= 0); x++){
            checkLine.push_back(this->map[x][y-x]);
        }
        if(isWinner_linear(checkLine)) {return true;}
        checkLine.resize(0);
    }
    //右上-下辺
    for(int x=1 ; x < this->size_x ; x++){
        for(int y=this->size_y - 1 ; (y >= 0) && (y-x >= 0); y--){
            checkLine.push_back(this->map[x][y-x]);
        }
        if(isWinner_linear(checkLine)) {return true;}
        checkLine.resize(0);
    }
    return false;
}

bool Gobang::judgeWin(){
    if(!this->isWinner()) { return false; }

    this->printMap();
    cout << (this->turn==BLACK ? "Black" : "White") << " Win!\n";
    return true;
}