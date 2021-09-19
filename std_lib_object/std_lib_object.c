/*
 * =====================================================================================
 *
 *       Filename:  std_lib_object.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  09/19/21 14:29:24
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */
#include "std_lib_object.h"

std_object_type std_objects = 
{
    .compare_strings = &strcmp,
};
