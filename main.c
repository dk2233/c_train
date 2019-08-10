#include <stdio.h>
#include "array_func.h"



int main(int argc ,char *argv[])
{
    int *tab;
    uint8_t i=0;
    int nr;

    if (1<argc)
    {
        nr=atoi(argv[1]);
        if (nr>0)
        {
            printf("array size %d \n",nr);

            tab =array_parse(10);

    for(;i<nr;i++)
    {
        printf("nr %d %d\n",i,tab[i]);
    }
        }
    }
    else
    {
        printf("Give as argument number of array items\n");
    }

    
	return 0;
}

