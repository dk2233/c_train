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


/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  str_op_find_char
 *  Description:  
 * =====================================================================================
 */
    void
str_op_find_char ( void * str_in, void * char_in  )
{
    char *str1 =(void *)str_in;
    char searched = *((char *) char_in );

    for( char letter = *str1; letter != '\0' ; str1++, letter = *str1)
    {
        if (letter == searched)
        {
            printf("found letter %c in %s \n",searched, (char*)str_in);
            return;

        }

    }
    printf("NOT found letter %c in %s \n",searched, (char *)str_in);

}		/* -----  end of function str_op_find_char  ----- */

void func_open_file(void * name, void * file_handler)
{
    /*  this type of function to return FILE pointer
     *  cannot work
     *  we need to use here ** double pointer
     *  to be able to return a pointer to changed pointer to FILE */
    FILE* file_hd;
    file_hd = fopen(name,"r");

    printf("%ld\n",(long*)file_hd);
    
    char char1 = fgetc(file_hd);
    printf("line from file: %s\n",name);
    while(char1 != '\n')
    {
        char1 = fgetc(file_hd);
        printf("%c",char1);
    }
    file_handler = (void*) file_hd;
}


void func_open_file_FILE(void * name, FILE ** file_handler)
{
    *file_handler = fopen((char*)name,"r");

    printf("file handler address %ld\n",(long*)*file_handler);
    
    char char1 = fgetc(*file_handler);
    printf("line from file: %s\n",(char*)name);
    while( (char1 != '\n' ) && (char1 != '\0'))   
    { 
        char1 = fgetc(*file_handler);
        printf("%c",char1);
    }
}

void read_one_line_from_file(char* name, FILE * file_handler)
{
    char char1 = fgetc(file_handler);
    printf("line from file: %s\n",(char*)name);
    while( (char1 != '\n' ) && (char1 != '\0'))   
    { 
        char1 = fgetc(file_handler);
        printf("%c",char1);
    }
}

void str_line(void * file_handler, void * return_str)
{
    printf("%ld\n",(long*)file_handler);
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
