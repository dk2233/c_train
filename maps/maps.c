#include <stdint.h> 
#include <stdio.h>
#include <stdlib.h>
#include "maps.h"
#include "hash_calc.h"
#include <string.h>


void display_map(map_t *map)
{
    for(int i = 0; i < map->max_number_of_element; i++)
    {
        printf("i %d key %d -> value %d \n", i , map->map[i].key, map->map[i].value);
    }
}


/* return id in map array for specific key *
 */
uint32_t map_find_key_id(map_t * map, int key)
{
    uint32_t start_id = hash_knuth(key) & map->mask_of_hash;
    uint32_t id = start_id;
    
    do {
        if (map->map[id].used != USED) return map->max_number_of_element;
        if (map->map[id].key == key) return id;

        id = (id + 1) & (map->max_number_of_element - 1) ;

        if (id == start_id) return map->max_number_of_element; 

    }  while(1);
        
    return start_id;
}

uint32_t find_empty_map(map_t * map, int key)
{
    uint32_t id = hash_knuth(key) & map->mask_of_hash;
    while(map->map[id].used == USED)  
    { 
        id = (id + 1) & (map->max_number_of_element -1 );
    }

    return id;
}

/* return -1 if cannot insert
 *
 */
int map_insert(map_t *map, int key, int value)
{
    if (map->number_of_occupied > map->limit_of_fill)
        return -1;

    uint32_t i = find_empty_map(map, key);

    map->map[i].key = key;
    map->map[i].value = value;
    map->map[i].used = 1;
    map->number_of_occupied++;
    
    return 0;

}

void map_rehash(map_t *map)
{
    map_element_t * new_map_data = calloc(map->max_number_of_element*2 , sizeof(map_element_t));
    map_t new_map = {0};

    new_map.max_number_of_element = map->max_number_of_element * 2;
    new_map.mask_of_hash = new_map.max_number_of_element - 1;
    new_map.map = new_map_data;
    new_map.limit_of_fill = new_map.max_number_of_element * LIMIT_OF_MAP_FILL;



    for(int i = 0; i < map->max_number_of_element ; i++)
    {
        if (map->map[i].used == USED)
            (void)map_insert(&new_map, map->map[i].key, map->map[i].value);
    }
    map->max_number_of_element = new_map.max_number_of_element ;
    map->mask_of_hash = new_map.mask_of_hash;
    map->limit_of_fill = new_map.limit_of_fill;
    map->number_of_occupied = new_map.number_of_occupied;
    free(map->map);
    map->map = new_map_data;

}

void * map_get_key_value(map_t *map, int key)
{

    uint32_t i = map_find_key_id(map, key);
    if (i == map->max_number_of_element) return NULL;
    return (void *)&(map->map[i].value);

}

/* return -1 if cannot insert
 *
 */
int map_insert_heap(map_t *map, int key, int value)
{
    if (map->number_of_occupied >= (map->max_number_of_element * LIMIT_OF_MAP_FILL)) 
    {
        map_rehash(map);

    }
    uint32_t i = find_empty_map(map, key);

    map->map[i].key = key;
    map->map[i].value = value;
    map->map[i].used = 1;
    map->number_of_occupied++;
    
    return 0;

}

void map_init(map_t *map, uint32_t max_number)
{
    if ( (max_number & (max_number -1)) ==  0)
    {

        map->mask_of_hash = max_number - 1;
        map->max_number_of_element = max_number;
        map->limit_of_fill = LIMIT_OF_MAP_FILL * max_number;
        map->number_of_occupied = 0u;
        memset(map->map, EMPTY, map->max_number_of_element * sizeof(map_element_t));
    }
    else 
        printf("wrong max number of elements\n");


}

/* here we need max_number to be power of 2 - 2, 4, 8, 16, 32 ...
 *
 */
void map_init_heap(map_t * map, uint32_t max_number)
{
    map->map = calloc(max_number, sizeof(map_element_t)  );
    
    map_init(map, max_number);

}


int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
        *returnSize = 2;
         int *result = calloc(*returnSize, sizeof(int));
         map_t * map = calloc(MAX_NUMS, sizeof(map_t));

         memset(map, 0, MAX_NUMS*sizeof(map_t));

    for (int i = 0; i < numsSize; i++) {
        int diff = target - nums[i];

        uint32_t id = map_find_key_id(map, diff);

        if (id != map->max_number_of_element) 
        {
            
            result[0] = i;
            //result[1] = map[id].value;
            free(map);
            return result;
        }

        uint32_t new_hash = find_empty_map(map, nums[i]);

        //map[new_hash].value = i;
        //map[new_hash].key = nums[i];
        //map[new_hash].used = USED;
        // for (int j = i + 1; j < numsSize; j++) {
        //     if (nums[i] + nums[j] == target) {
            
           
        //         result[0] = i;
        //         result[1] = j;
        //         *returnSize = 2;
        //         return result;
        //     }
        



    }
    return result;
}




