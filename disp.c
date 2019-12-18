#include "disp.h"
#include <stdio.h>

void drawMap(map_t* map){

    int x=0,y=0;

    for(y=0 ; y < map->size_y ; y++){
       for(x=0 ; x < map->size_x ; x++){
           switch(map->map[y * map->size_x + x]){
                case BLACK:
                    printf("黒");
                    break;

                case WHITE:
                    printf("白");
                    break;
                    
                case EMPTY:
                    if     (x==0 && y==0)                           printf("┌");
                    else if(x==map->size_x-1 && y==0)               printf("┐");
                    else if(x==0             && y==map->size_y-1)   printf("└");
                    else if(x==map->size_x-1 && y==map->size_y-1)   printf("┘");
                    else if(y==0)                                   printf("┬");
                    else if(y==map->size_y-1)                       printf("┴");
                    else if(x==0)                                   printf("├");
                    else if(x==map->size_x-1)                       printf("┤");
                    else                                            printf("┼");
           }


        }
        printf("\n");
    }

};
