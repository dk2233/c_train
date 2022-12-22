/*
 * =====================================================================================
 *
 *       Filename:  different_function.c
 *
 *    Description:  different function usage
 *
 *        Version:  1.0
 *        Created:  09/05/21 12:59:03
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */
#include <stdlib.h>
#include <stdio.h>

void sum_to_int(void* a, void* b)
{
    printf("sum =  %d \n",*(int *)a + *(int *)b);  
}




int read_one_line_from_file(FILE * file_handler, char * line)
{
    int return_value = -1;
    if (NULL != file_handler)
    {
        char char1;
        do
        { 
            char1 = fgetc(file_handler);
            *(line++) = char1;
        }
        while((char1 != '\n' ) && (char1 != '\0'));   

        return_value = 0;
    }
    else
    {
        printf(" There is no such file as you gave \n");
    }
    return return_value;
}



void str_line(void * file_handler, void * return_str)
{
    if ((file_handler != NULL) && (return_str != NULL ))
    {
        printf("file handler id %p\n",file_handler);
        int letter = fgetc((FILE*)file_handler);
        char *str_tmp;
        str_tmp = (char *)return_str;
        while((letter != '\n') && (letter != '\0') && (letter > -1) )
        {
            *(str_tmp++) = letter;
            letter = fgetc((FILE*) file_handler);
        }

        return_str = (void *)str_tmp;
    }
    else    
   {
        if (file_handler == NULL)
            printf("ERROR file not opened \n");

        if (return_str == NULL)
            printf("ERROR  return_str not allocated! \n");
    }
}
