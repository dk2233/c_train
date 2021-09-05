/*
 * =====================================================================================
 *
 *       Filename:  func_pointers.h
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  09/05/21 12:05:02
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */
typedef struct
{
    void (*function_p)(void* );
    void* argument;
} one_func_pointer_def;


typedef struct 
{
    int elements_number;
    one_func_pointer_def func_array[];

} function_pointers_definition;




extern void call_one_function_pointer ( void  (*function)(int, int), int a, int b );
