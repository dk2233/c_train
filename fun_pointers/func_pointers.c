/*
 * =====================================================================================
 *
 *       Filename:  func_pointers.c
 *
 *    Description: file with func pointers plays
 *
 *        Version:  1.0
 *        Created:  09/05/21 11:40:10
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:   kucharsd (),
 *   Organization:
 *
 * =====================================================================================
 */
#include <stdlib.h>
#include "func_pointers.h"
#include <stdio.h>
#include "different_functions.h"
#include "defines.h"
#include "files.h"
#include "str_change.h"
/*
 * ===  FUNCTION  ======================================================================
 *         Name:  call_all_function
 *  Description:
 * =====================================================================================
 */
void
call_all_function ( function_pointers_definition *struct_of_func   )
{
    printf("call_all_function\n");

    for(unsigned int i = 0; i < struct_of_func->elements_number; i++)
    {
        if (struct_of_func->func_array[i].argument2a != NULL)
        {
            struct_of_func->func_array[i].func_union.function_p( struct_of_func->func_array[i].argument1, struct_of_func->func_array[i].argument2a);

        }
        else
            //(struct_of_func->func_array[i].argument2b != NULL)
        {
            struct_of_func->func_array[i].func_union.function_point_point_p( struct_of_func->func_array[i].argument1, struct_of_func->func_array[i].argument2b);

        }


    }
}		/* -----  end of function call_all_function  ----- */


/*
 * ===  FUNCTION  ======================================================================
 *         Name:  call_one_function_pointer
 *  Description:
 * =====================================================================================
 */
void
call_one_function_pointer ( void  (*function)(void *, void *), int a, int b )
{
    printf("call_one_function_pointer\n");
    (*function)(&a,&b);
    return ;
}		/* -----  end of function call_one_function_pointer  ----- */



void function_pointer_playground(void)
{
    
    int a =2;
    int b = 5;
    char *str1 = "tekst - testowy !? nie!@";
    char sss = '?';
    char *file_name = "cscope.files";

    FILE *file_hd2;
    function_pointers_definition functions_def_struct =
    {
        .elements_number = HOW_MANY_FUNCTION,
        .func_array[0] =
        {
            &sum_to_int,
            (void *)&a,
            (void *)&b,
            NULL,
        },
        .func_array[1] =
        {
            &string_operation_find_char,
            (void * )str1,
            (void*)&sss,
            NULL
        },
        /*  this method of using pointer to return File will not work until we use ** pointer
         *  every time we open file we also change structure address
         *  so we should use here ** pointer that can be changed were it is pointing to */
        .func_array[2] ={ .func_union.function_point_point_p =  &func_open_file_FILE,  (void *)file_name, NULL,  (void **)&file_hd2},

    };

    call_all_function( &functions_def_struct);

    printf("file handler bef  wrong one %p \n", file_hd2);
    /*      THIS_DOES_NOT_WORK read_one_line_from_file(file_name, file_hd2);*/
    /*  file_hd2 is pointing to wrong address */
    //func_open_file_FILE((void*)file_name, &file_hd2);

    printf("file handler 2 %p \n", file_hd2);

    char * str_from_file;
    str_from_file = calloc(MAX_LINE_SIZE, sizeof(char));
    if (file_hd2 != NULL)
    {
        str_line((void *)file_hd2,(void *) str_from_file);
        printf("2. first line %s \n", str_from_file) ;
        fclose(file_hd2);
    }


    free(str_from_file);

}