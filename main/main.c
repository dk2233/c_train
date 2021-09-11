#include <stdio.h>
#include <stdlib.h>
#include "array_func.h"
#include "str_change.h"
#include "func_pointers.h"
#include "different_functions.h"


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


    check_possibility_of_not_defining_size();

    call_one_function_pointer(&sum_to_int, 3 , 4);



    int a =2;
    int b = 5;
    char *str1 = "tekst - testowy !? nie!@";
    char sss = '?';
    function_pointers_definition functions_def_struct = 
    {
        .elements_number = 2U,
        .func_array[0] = 
        {
            &sum_to_int,
            (void *)&a ,
            (void *)&b
        },
        .func_array[1] = 
        {
            &str_op_find_char,
            (void * )str1,
            (void*)&sss,

        }

    };

    call_all_function( &functions_def_struct);

    return 0;
}

