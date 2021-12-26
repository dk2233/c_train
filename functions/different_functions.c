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


void func_open_file(char * name, char * mode, FILE ** file_hd)
{
    /* open file in given mode */
    *file_hd = fopen((char*)name,(const char *)mode);

    if (NULL == *file_hd)
    {
        printf(" file: %s cannot be open\n",(char*)name);
    }
}

void func_open_file_FILE(void * name, void ** file_handler )
{
    /*  this type of function to return FILE pointer
     *  cannot work
     *  we need to use here ** double pointer
     *  to be able to return a pointer to changed pointer to FILE */
    FILE **file_hd = (FILE **)file_handler;

    *file_hd = fopen((char*)name, "r") ;

    if (NULL != *file_hd)
    {
        printf("file handler address %ld\n",(long)file_hd);
        char char1 = fgetc(*file_hd);
        printf("line from file: %s\n",(char*)name);
        while( (char1 != '\n' ) && (char1 != '\0'))   
        { 
            char1 = fgetc(*file_hd);
            printf("%c",char1);
        }
    }
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
    printf("file handler id %ld\n",(long)file_handler);
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

long int file_length(FILE *file_hd)
{
    long int file_size = 0UL;

    if (file_hd != NULL)
    {
        printf("actual location %ld ",ftell(file_hd));

        if(0 == fseek(file_hd, 0U, SEEK_END ))
        {

            file_size = ftell(file_hd);

            printf("actual location %ld ",ftell(file_hd));

        }
        /*  We need to return position to beginnin of file */
        fseek(file_hd, 0U, SEEK_SET );
        printf("actual location %ld \n",ftell(file_hd));
    }
    return file_size; 
}

int whole_file_to_one_str( FILE *file_handler, char *table )
{
    int is_it_ok = 0;

    if (file_handler != NULL)
    {

        char character;
        do 
        {
            character = fgetc(file_handler);
            if ( (character != '\0') &&(character >-1 ) )
            {
            *(table++) = character;
            }
        }
        while( (character != '\0') &&(character >-1 ) );

    }
    else
    {
    is_it_ok = 1;
    }

    return is_it_ok;


}
