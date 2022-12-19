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


int main(int argc,char *argv[])
{
    int *tab;
    uint8_t i=0;
    int nr;
    int * new_tab;
    char a1, a2, a3;

    //to check variables alignement
    //and their address
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


/*
 *"---------------------------------------------------
 */



    /*
    structs / unions

    */

    struct_playground();

    recursion_playground();

    return 0;
}

