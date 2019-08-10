#include "array_func.h"	
#include "stdlib.h"

unsigned int tab_a[ARRAY_SIZE];
unsigned int * array_p;

//added some lines

int * array_parse(int nr_element)
{
    static int *array_a;
    uint8_t i;

    array_a =malloc(nr_element* sizeof(int));
 
    for(i=0;i<nr_element ; i++)
    {
        array_a[i]=2+i;
    }
    return array_a;

}








