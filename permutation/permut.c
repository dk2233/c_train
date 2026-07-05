#include <stdio.h>
#include <string.h>
#include "different_functions.h"




/*
 * return 0 if end of permutation
 * return 1 if still more permutation
 */
int next_perm_pandita(int n, char** s)
{
    int i,  j = 0, cond = 0, ex = 0;;

    for(i = n-2; i >=0 && ex == 0; i--)
    {
        /*
         * 1. Find the largest index i such that s[i] < s[i + 1]. start from max list index -1 (right-hand side)
         */
        if (strcmp(s[i], s[i+1]) < 0) 
        {
            cond = 1;
            /*
             * 2. Find the largest index j greater than i such that a[i] < a[j]. Find the element in the right-hand side of the array.
             */

            for( j = n - 1 ; j >= 0; j--)
            {
                if (strcmp(s[i], s[j]) < 0) {
                    swap(&s[i], &s[j]);

                   /* reverse elements from i+1 to  the end of strings
                    *
                    */

                    int start = i + 1; int end = n-1;

                    while(start < end)
                    {
                        swap(&s[start++], &s[end--]);

                    }
                    //ex = 1;
                    break;
                }
            }
            break;
        }

    }

    
    return cond;
}
