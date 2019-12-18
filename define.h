#pragma once

#define MAP_SIZE 9


typedef enum Player_e {EMPTY,BLACK,WHITE} player_t;
typedef enum Bool_e {FALSE,TRUE} bool_t;

typedef struct Map {
    player_t *map;
    int size_x;
    int size_y;
} map_t;