#ifndef DIFFERENT_FUNC_H
#define DIFFERENT_FUNC_H
/*
 * =====================================================================================
 *
 *       Filename:  different_functions.h
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
#include <stdio.h>
#include <time.h>

extern void sum_to_int ( void *, void* );
extern void string_read_line(void * file_handler, void * return_str);
extern 
long int read_one_line_from_file(FILE * file_handler, char* line);

extern double time_measurement(void);

extern void argument_array(char * argv_parameter);
extern void argument_file_read_point(char * argv_parameter);
extern void argument_hashes(char * argv_parameter);
extern void argument_file_read(char * argv_parameter);
#endif
