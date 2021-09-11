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

void sum_to_int(int* a, int* b)
{
    printf("sum =  %d \n",*a + *b);  


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
