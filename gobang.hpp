#pragma once

#include "map.hpp"
#include "head.hpp"
#include <vector>

using namespace std;

class Gobang : public Map {
private:
    player turn = BLACK;
    int turnCount = 0;

    bool setStone(int,int);
    bool initMap();
    bool isWinner();
    bool isWinner_linear(vector<player>);
    
public:
    bool initialize();
    bool inputStone();
    bool judgeWin();
    void flipTurn();
    
};