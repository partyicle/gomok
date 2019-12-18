#include "init.h"
#include <stdlib.h>


/* map領域動的確保、失敗でfalse
 */
bool_t initializeMap(map_t *map){
    map->map = (player_t *)malloc(sizeof(player_t)*(map->size_x * map->size_y));

    if(map->map == NULL) return FALSE;
    return TRUE;
}
