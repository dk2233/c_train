#include <stdint.h>

#define MAX_NUMS  32768u

#define LIMIT_OF_MAP_FILL  0.6f
#define USED   1
#define EMPTY 0

typedef struct 
{
    int key;
    int value;
    int used;
} map_element_t;

typedef struct 
{
    map_element_t * map;
    uint32_t number_of_occupied;
    uint32_t max_number_of_element;
    uint32_t limit_of_fill;
    uint32_t mask_of_hash;
} map_t;

uint32_t map_find_key_id(map_t * map, int key);

int map_insert(map_t *map, int key, int value);

int map_insert_heap(map_t *map, int key, int value);

void map_init_heap(map_t * map, uint32_t max_number);

void map_init(map_t * map, uint32_t max_number);

void maps_playground(void);

void display_map(map_t *map);

void * map_get_key_value(map_t *map, int key);
