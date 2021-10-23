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
#include "stdio.h"
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


