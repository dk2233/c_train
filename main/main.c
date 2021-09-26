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

    /*  opening file in c */
    char *file_name = "cscope.files";
    FILE *file_hd; 
    file_hd = fopen(file_name,"r");
    char *str_from_file = calloc(1000U, sizeof(char));
    str_line((void *)file_hd,(void *) str_from_file);
    printf("1. first line %s \n", str_from_file) ;

    FILE * file_hd2;
    function_pointers_definition functions_def_struct = 
    {
        .elements_number = HOW_MANY_FUNCTION,
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

        },
        .func_array[2] ={ &func_open_file,  (void *)file_name, (void *)file_hd2}, 
    };

    call_all_function( &functions_def_struct);

    printf("file handler %ld \n", *(long *)file_hd2);

    str_from_file = calloc(1000U, sizeof(char));
    str_line((void *)file_hd2,(void *) str_from_file);
    printf("2. first line %s \n", str_from_file) ;

    fclose(file_hd);
    fclose(file_hd2);

    free(str_from_file);

/* added pointers play */
    int var_a = 100;
    const int * pointer_to_const;
    pointer_to_const = &var_a;

    /*  here pointer with uncheangable address is created  */
    int * const const_pointer = &var_a;
    /* this will create an error  
     *   const_pointer = &var_a;
     */

    /*  this is fine */
    pointer_to_const = &var_a;

    var_a++;
    pointer_to_const++;
    /*  this below will not work
     *  constant address of pointer was defined*/
//    const_pointer++;

    var_a++;
    /*this will not work*/  
 //(*pointer_to_const)++;


    return 0;
}

