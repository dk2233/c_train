#include <stdio.h>
#include <stdlib.h>
#include "array_func.h"
#include "str_change.h"
#include "func_pointers.h"
#include "different_functions.h"
#include "recur.h"
#include "defines.h"


struct how_many_bits
{
    int number;
    unsigned int count;
};

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
        nr = 10U;
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
    if (NULL != file_hd)
    {
        str_line((void *)file_hd,(void *) str_from_file);
        printf("1. first line %s \n", str_from_file) ;
        fclose(file_hd);
    }
    else
    {
        printf(" there is no such file %s \n",file_name);
    }

    FILE *file_hd2;
    function_pointers_definition functions_def_struct = 
    {
        .elements_number = HOW_MANY_FUNCTION,
        .func_array[0] = 
        {
            &sum_to_int,
            (void *)&a ,
            (void *)&b,
                NULL,
        },
        .func_array[1] = 
        {
            &str_op_find_char,
            (void * )str1,
            (void*)&sss,
            NULL
        },
        /*  this method of using pointer to return File will not work
         *  every time we open file we also change structure address
         *  so we should use here ** pointer that can be changed were it is pointing to */
        .func_array[2] ={ .func_union.function_point_point_p =  &func_open_file_FILE,  (void *)file_name, NULL,  (void **)&file_hd2}, 

    };

    call_all_function( &functions_def_struct);

    printf("file handler bef  wrong one %ld \n", (long)file_hd2);
/*      THIS_DOES_NOT_WORK read_one_line_from_file(file_name, file_hd2);*/
    /*  file_hd2 is pointing to wrong address */
    //func_open_file_FILE((void*)file_name, &file_hd2);
    
    read_one_line_from_file(file_name, file_hd2);


    printf("file handler 2 %ld \n", (long)file_hd2);

    str_from_file = calloc(1000U, sizeof(char));
    if (file_hd2 != NULL)
    {
        str_line((void *)file_hd2,(void *) str_from_file);
        printf("2. first line %s \n", str_from_file) ;
        fclose(file_hd2);
    }


    free(str_from_file);


    printf(" ones in %d is %d\n            ", nr, bitCount(nr));
    
    typedef struct  
    {
        int base;
        int power_to;
    }type_numbers;

    type_numbers tab_numbers[] = 
    {
        { 2, 5},
        {2, 3},
        {2, 8}

    };

    for ( unsigned char i = 0; i < (sizeof(tab_numbers)/ sizeof( type_numbers)); i++)
    {

    printf(" %d to the power  %d is %d\n ", 
            tab_numbers[i].base ,
            tab_numbers[i].power_to,  
            power_of_2(tab_numbers[i].base,tab_numbers[i].power_to));
    }


    struct how_many_bits numbers_struct = {0, 0};

    numbers_struct.number = 127;
    numbers_struct.count = bitCountShift(numbers_struct.number);


    numbers_struct.number = 1000;
    numbers_struct.count = bitCountShift(numbers_struct.number);


    return 0;
}

