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
#include "defines.h"

typedef union
{
    void (*function_p)(void*, void*);

    void (*function_point_point_p)(void*, void**);

    void (*function_3_arg_point_point_doublepoint_p)(void*, void*, void**);

    void (*function_ptr_int)(void*, int);

} union_func_pointers_type;

typedef struct _function_ptr_def
{
    //void (*function_p)(void* , void * );
    union_func_pointers_type func_union;
    void* argument1;
    void* argument2a;
    void** argument2b;
    int arg_int;
} function_ptr_def;

/*
this is the simple approach to do not have flexible
array struct member
we could use ptr here to function_ptr_def
such approach is primitvie but fast and easy to implement*/
typedef struct 
{
    int elements_number;
    function_ptr_def *func_array;

} function_ptr_struct_composition;


typedef struct 
{
    int elements_number;
    function_ptr_def *func_array;

} function_pointers_definition_ptr;

extern void call_one_function_pointer ( void  (*function)(void *, void *), int  a, int  b );

extern void call_all_function ( function_ptr_struct_composition *struct_of_func  );

extern void function_pointer_playground(void);

#endif
