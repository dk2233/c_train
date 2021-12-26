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
    void (*open_file)(char *name, char *file_mode,  FILE** file_handler);
    long int (*file_size)(FILE* file_handler);
    void (*open_file_and_copy_to_str)(char *name, char *file_mode, FILE** file_handler);
    int (*read_line_from_file)(FILE * file_handler, char * read_line);
    int (*copy_file_to_string)(FILE * file_handler, char * big_string);

} std_object_type;

extern std_object_type std_objects;
