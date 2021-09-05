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
/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  call_all_function
 *  Description:  
 * =====================================================================================
 */
    void
call_all_function ( function_pointers_definition *array_of_func(void* input_paramter), size_t elements_nr  )
{
    for(unsigned int i = 0; i < elements_nr; i++)
    {
        array_of_func; 

    }
}		/* -----  end of function call_all_function  ----- */


/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  call_one_function_pointer
 *  Description:  
 * =====================================================================================
 */
    void
call_one_function_pointer ( void  (*function)(int, int), int a, int b )
{
    function(a,b);
    return ;
}		/* -----  end of function call_one_function_pointer  ----- */
