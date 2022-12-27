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
#include "arg_parse.h"
#include "console-colors.h"


static int tab_test[FUNCTION_ARGUMENT] =
{
    1, 102, 3, 5, 78, 200, 56, 89, 99, 0

};


int main(int argc,char *argv[])
{
    int *tab;
    uint8_t i=0;
    int nr;
    int * new_tab = NULL;
    char a1, a2, a3;

    //to check variables alignement
    //and their address
    a1 = 1;
    a2 = 2;
    a3 = 3;


    if (1<argc)
    {
        parser_arguments(argc, argv);
    }
    else
    {
        printf("Give as argument number of array items\n");
        nr = 10U;
    }

    /*
    menu of tests*/

    char option[5];
    do
    {
        cc_fprintf(CC_FG_BLUE, stdout, "************************************************\n");
        cc_fprintf(CC_BG_CYAN, stdout, "> s\\S strings \n");
        printf("> a\\A arrays \n");
        printf("> b\\B structs \n");
        printf("> f\\F function pointers \n");
        printf("> g\\G files \n");
        printf("> r\\R recursion \n");
        cc_fprintf(CC_BG_GRAY, stdout, "> q\\Q EXIT \n");
        // option = getchar();
        scanf("%s", option);
        //there is still an enter pressed
        getchar();

        switch (option[0])
        {
        case 'q':
        case 'Q':
            /* code */
            break;
        case 's':
        case 'S':
            /*
            strings tests
            */
            string_different_tests();
            break;

        case 'a':
        case 'A':
            /*
            arrays tests
            */
            check_possibility_of_not_defining_size();

            check_array_argument(tab_test);
            break;

        case 'b':
        case 'B':
            /*
            structs / unions
            */
            struct_playground();
            break;
        case 'f':
        case 'F':
            /*
            function pointers
            */
            call_one_function_pointer(&sum_to_int, 3, 4);
            function_pointer_playground();
            break;
        case 'g':
        case 'G':    
            files_playground();
            break;

        case 'r':
        case 'R':    
            recursion_playground();
            break;

        default:
            break;
        }


        /* code */
    } while (option[0] != 'q');
    



/*
 *"---------------------------------------------------
 */

    return 0;
}

