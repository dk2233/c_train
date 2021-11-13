/*
 * =====================================================================================
 *
 *       Filename:  std_lib_object.h
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  09/19/21 16:02:38
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */
#include    <string.h>
#include "stdio.h"

//---------------------------------------------------
typedef struct 
{
    int (*compare_strings)(const char* , const char *);
    char * (*find_string)(const char*, const char * );
    void (*open_file_and_copy_to_str)(char *name, FILE** file_handler);

} std_object_type;

extern std_object_type std_objects;
