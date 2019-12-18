#include "main.h"
#include <stdio.h>
#include <stdlib.h>


int main(void){

    map_t map;

    printf("mapsize X:");
    scanf("%d",&map.size_x);
    printf("mapsize Y:");
    scanf("%d",&map.size_y);

    if (initializeMap(&map) == FALSE){
        puts("malloc failed");
        return 1;
    } 

    while(1){
        drawMap(&map);

        break;
    }

    free(map.map);
    return 0;
};