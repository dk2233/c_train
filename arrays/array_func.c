#include "array_func.h"
#include "stdlib.h"
#include "stdio.h"


unsigned int tab_a[ARRAY_SIZE];
unsigned int * array_p;

# define VAR_A   10U


uint8_t arra[][4] =
{
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

    for(i=0; i<nr_element; i++)
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

void check_array_argument(int tab[FUNCTION_ARGUMENT])
{
    int iter = 0;
    for(; iter < FUNCTION_ARGUMENT; iter++)
    {
        printf("tab[%d] %d\n", iter, tab[iter]);
    }

}
/*
this function allocates array and returns its pointer **

if call second time it should free buffer
*/
bool create_array(void ** tab, int size_of_array, size_t size_of_one_element )
{
    bool state = false;

    if ((*tab == NULL) && (size_of_array > 0))
    {
        *tab = calloc(size_of_array, size_of_one_element);
        if (*tab != NULL)
        {
            printf("array allocated %p \n", *tab);
            state = true;
        }
        else
        {
            printf("error\n");
            state = false;
        }
    }
    else
    {
    free(*tab);
    }

    return state;

}






