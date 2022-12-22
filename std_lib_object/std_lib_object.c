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
#include "different_functions.h"
#include "files.h"

std_object_type std_objects = 
{
    .compare_strings = &strcmp,
    .find_string = &strstr,
    .open_file = &func_open_file,
    .file_size = &file_length,
    .open_file_and_copy_to_str = &func_open_file,
    .read_line_from_file = &read_one_line_from_file,
    .copy_file_to_string = &whole_file_to_one_str,
};
