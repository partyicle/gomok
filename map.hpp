#pragma once
#include <vector>

using namespace std;

class Map {
private:
    vector< vector<player> > map;
    int size_x;
    int size_y;

public:
    bool setSize(int x, int y);
    bool initialize();
    void printMap();
};