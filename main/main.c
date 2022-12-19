#include <stdio.h>
#include <stdlib.h>
#include "array_func.h"
#include "str_change.h"
#include "func_pointers.h"
#include "different_functions.h"
#include "recur.h"
#include "defines.h"
#include "std_lib_object.h"
#include "structs.h"
#include "files.h"


static int tab_test[FUNCTION_ARGUMENT] =
{
    1, 102, 3, 5, 78, 200, 56, 89, 99, 0

};

struct how_many_bits
{
    int number;
    unsigned int count;
};

int main(int argc,char *argv[])
{
    int *tab;
    uint8_t i=0;
    int nr;
    int * new_tab;
    char a1, a2, a3;

    a1 = 1;
    a2 = 2;
    a3 = 3;


    if (1<argc)
    {
        nr=atoi(argv[1]);
        if (nr>0)
        {
            printf("array size %d \n",nr);

            tab =array_parse(nr);

            for(; i<nr; i++)
            {
                printf("nr %d %d\n",i,tab[i]);
            }

            if (create_array( (void **) &new_tab, nr, sizeof(int)  ) == true)
            {
                new_tab[0] = 10;
            }
        }
    }
    else
    {
        printf("Give as argument number of array items\n");
        nr = 10U;
    }

    /*
    strings tests
    */

    string_different_tests();

    /*
    arrays tests
    */
    check_possibility_of_not_defining_size();

    check_array_argument(tab_test);

    /*
    function pointers
    */

    call_one_function_pointer(&sum_to_int, 3, 4);

    function_pointer_playground();

    files_playground();

    printf(" ones in %d is %d\n            ", nr, bitCount(nr));

    typedef struct
    {
        int base;
        int power_to;
    } type_numbers;

    type_numbers tab_numbers[] =
    {
        { 2, 5},
        {2, 3},
        {2, 8}

    };

    for ( unsigned char i = 0; i < (sizeof(tab_numbers)/ sizeof( type_numbers)); i++)
    {

        printf(" %d to the power  %d is %d\n ",
               tab_numbers[i].base,
               tab_numbers[i].power_to,
               power_of_2(tab_numbers[i].base,tab_numbers[i].power_to));
    }


    struct how_many_bits numbers_struct = {0, 0};

    numbers_struct.number = 127;
    numbers_struct.count = bitCountShift(numbers_struct.number);


    numbers_struct.number = 1000;
    numbers_struct.count = bitCountShift(numbers_struct.number);


/*
 *"---------------------------------------------------
 */



    /*
    structs / unions

    */

    struct_playground();


    return 0;
}

