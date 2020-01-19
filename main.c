#include <stdio.h>
#include <stdlib.h>
#include "array_func.h"
#include "str_change.h"


int main(int argc ,char *argv[])
{
    int *tab;
    char string_to_change[40];
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
    printf(" give string:");

    scanf("%[^\n]s",string_to_change);

    string_letter_replace(string_to_change);
    printf("%s\n",string_to_change);


	return 0;
}

