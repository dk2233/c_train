
#include <stdio.h>
#include "different_functions.h"
void sort_bubble(void * base, size_t num, size_t one_el_size, int (*comp_func)(const void *a, const void *b))
{
    int result = 0, cond = 0; 

    while(cond == 0)
    {
        cond = 1;

        for(int i = 0; i < num-1; i++)
        {

            /*
             * char has one byte so it is calculated with how many bytes per one elements
             */
            //printf("%d\n", *(char *)(base + one_el_size*i));
           int comp = comp_func(base+one_el_size*i , base + one_el_size*(i+1));
            
            if (comp > 0) { generic_swap( (base+one_el_size*i) , (base + one_el_size*(i+1)), one_el_size ) ;
                cond = 0;
            }
        }
    }

}
