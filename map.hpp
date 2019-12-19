#pragma once
#include <vector>

using namespace std;

class Map {
protected:
    vector< vector<player> > map;
    int size_x;
    int size_y;

    bool setSize(int x, int y);
    bool resizeMap();
public:
    virtual bool initMap();
    virtual void printMap();
    virtual bool isWinner() = 0;
};