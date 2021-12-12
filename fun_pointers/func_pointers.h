#ifndef FUNC_POINTERS_H
#define FUNC_POINTERS_H
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
#define HOW_MANY_FUNCTION 3U
typedef union
{
    void (*function_p)(void*, void*);

    void (*function_point_point_p)(void*, void**);

    void (*function_3_arg_point_point_doublepoint_p)(void*, void*, void**);

} union_func_pointers_type;

typedef struct
{
    //void (*function_p)(void* , void * );
    union_func_pointers_type func_union;
    void* argument1;
    void* argument2a;
    void** argument2b;
} one_func_pointer_def;


typedef struct 
{
    int elements_number;
    one_func_pointer_def func_array[HOW_MANY_FUNCTION];

} function_pointers_definition;


extern void call_one_function_pointer ( void  (*function)(void *, void *), int  a, int  b );

extern void call_all_function ( function_pointers_definition *struct_of_func  );

#endif
