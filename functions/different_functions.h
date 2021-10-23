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

extern void sum_to_int ( void *, void* );
extern  void str_op_find_char ( void * str_in, void * char_in  );
extern void func_open_file(void * name, void * file_handler);
extern void str_line(void * file_handler, void * return_str);
extern 
void func_open_file_FILE(void * name, void ** file_handler);
extern 
void read_one_line_from_file(char* name, FILE * file_handler);

#endif
