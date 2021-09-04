#include "array_func.h"	
#include "stdlib.h"

unsigned int tab_a[ARRAY_SIZE];
unsigned int * array_p;

# define VAR_A   10U

uint8_t arra[][4] = { 
    { 0,3},
    {3,5,6, 67},
    {1}

};

int * array_parse(int nr_element)
{
    /*  
     *  is it possible to return internal array_a
     *  and have access to it after leaving this function?*/
    static int *array_a;
    uint8_t i;

    array_a =malloc(nr_element* sizeof(int));

    for(i=0;i<nr_element ; i++)
    {
        array_a[i]=2+i;
    }
    return array_a;
}


int check_possibility_of_not_defining_size(void)
{
    /*check if when no explicitly define size of array 
     * it still works fine
     * however it may depend on used compiler
     * on gcc it is fine
     * */
    printf(" DEFINITION %d \n",VAR_A);
    printf(" size of %ld \n",sizeof(arra)/sizeof(arra[0]));

    for(uint8_t iter1 = 0U; iter1 < (sizeof(arra)/sizeof(arra[0])); iter1++ )
    {
        for(uint8_t iter2 = 0U; iter2 < (sizeof(arra[0])); iter2++ )
        {
            printf("%d ",arra[iter1][iter2]);
        }
        printf("\n");
    } 
    return 0;
}






