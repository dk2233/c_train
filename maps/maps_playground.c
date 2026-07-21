#include "func_pointers.h"
#include "maps.h"
#include "hash_calc.h"
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAP1_SIZE  2048u 
#define MAP2_SIZE  2400u
#define MAX_NUMS   2048u


static map_element_t map1_data[MAP1_SIZE] = {0u}; 



/* find in array two sum that will give target
 */
int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    *returnSize = 2;
    int *result = calloc(*returnSize, sizeof(int));

    map_t map = {EMPTY}; 

    //map_element_t * map_data = calloc(MAX_NUMS, sizeof(map_t));

    //memset(map, 0, MAX_NUMS*sizeof(map_t));
    map_init_heap(&map, numsSize);

    for (int i = 0; i < numsSize; i++) 
    {
        int diff = target - nums[i];

        uint32_t id = map_find_key_id(&map, diff);

        if (id != map.max_number_of_element) 
        {
            
            result[0] = i;
            result[1] = map.map[id].value;
            if (map.map != NULL)  { 
                free(map.map);
                map.map = NULL;
            }

            return result;
        }

        map_insert_heap(&map, nums[i], i);

        //uint32_t new_hash = find_empty_map(map, nums[i]);
        //map[new_hash].value = i;
        //map[new_hash].key = nums[i];
        //map[new_hash].used = USED;
        //
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


void two_number_sum_tests(void)
{
     
   int array[] = {2,7,11,15};


   int *size_of_ret_array;
   int sum = 9;
   int * ret_arr = twoSum(array, sizeof(array)/sizeof(int), sum,  size_of_ret_array);

   if (ret_arr != NULL)
   {
       printf("sum %d => index %d,  %d values %d, %d \n", sum, ret_arr[0], ret_arr[1], array[ret_arr[0]], array[ret_arr[1]]);

       free(ret_arr);
       ret_arr = NULL;
   }
   
   const int TWO_NO_SUM_TEST2_ARRAY_SIZE = 10000; 
   int array2[TWO_NO_SUM_TEST2_ARRAY_SIZE] ;

   for(int i = 0; i <  TWO_NO_SUM_TEST2_ARRAY_SIZE; i++)
   {
       array2[i] = i;
   }

   sum = 9999;
   ret_arr = twoSum(array2, (int)TWO_NO_SUM_TEST2_ARRAY_SIZE, sum, size_of_ret_array);

   if (ret_arr != NULL)
   {
       printf("sum %d => index %d,  %d values %d, %d \n", sum, ret_arr[0], ret_arr[1], array2[ret_arr[0]], array2[ret_arr[1]]);

       free(ret_arr);
   }
   sum = 19997;
   ret_arr = twoSum(array2, (int)TWO_NO_SUM_TEST2_ARRAY_SIZE, sum, size_of_ret_array);

   if (ret_arr != NULL)
   {
       printf("sum %d index %d,  %d values %d, %d \n", sum, ret_arr[0], ret_arr[1], array2[ret_arr[0]], array2[ret_arr[1]]);

       free(ret_arr);
   }

}

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
       if ( -1 == map_insert(&map1, i, i)) printf("cannot insert element %d fill is %d, max size %d \n",i, map1.number_of_occupied, map1.max_number_of_element );
   }

   printf("\nthis is static map and it cannot be easily increased with heap allocation \n");
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
   
   two_number_sum_tests();

}
