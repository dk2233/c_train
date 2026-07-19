#include "maps.h"
#include "hash_calc.h"
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#define MAP1_SIZE  2048u 
#define MAP2_SIZE  2400u 

static map_element_t map1_data[MAP1_SIZE] = {0u}; 

void maps_playground(void)
{

    map_t map1 = {0};

    map1.map = map1_data;

    map_init(&map1, MAP1_SIZE);



   (void) map_insert(&map1, 100, 10);
   (void) map_insert(&map1, 9, 1234);

   /* this will work only if map_find_key return valid index 
    */
   printf("map element %d \n", map1.map[map_find_key_id(&map1, 100)].value);
    
   for(int i = 0; i < MAP1_SIZE; i++)
   {
       if ( -1 == map_insert(&map1, i, i)) printf("cannot insert element fill is %d, max size %d \n",map1.number_of_occupied, map1.max_number_of_element );
   }

   display_map(&map1);

   printf("map element %d \n",*((int*)map_get_key_value(&map1, 100)));


   map_t map_heap = {0};
   map_init_heap(&map_heap, MAP1_SIZE);
    
   for(int i = 0; i < MAP2_SIZE ; i++)
   {
       map_insert_heap(&map_heap, i, i);
   }

   display_map(&map_heap);

   for(int i = 0; i < map_heap.number_of_occupied; i++)
   {
       if ( map_heap.map[i].used == EMPTY) continue;
       int v = *(int *)map_get_key_value(&map_heap, i);
       if (v != i) 
       { 
           printf("unexpected value v %d should be i %d  \n", v, i);
       }
   }

   printf(" Give key to check manually : ");
   uint32_t key;
   scanf("%d",&key);
   
   int * val  = (int*)map_get_key_value(&map_heap, key);

   if (NULL != val)  printf("Key %d value %d \n", key, *val);
   else 
       printf("cannot find key %d in map \n", key);
   if (map_heap.map != NULL)
       free(map_heap.map);
}
