/*

file to test some bitwise solutions


*/

#include <stdio.h>
#include "bitwise.h"
#include "defines.h"

void test_different_bitwise(void)
{
    char a = 9;
    char b = 5;
    char minus_a = -9;
    char a1 = a;

    /*
    
    if we want to show hex value of not we need to specify its size
    char is hh
    */
    
    char not_a = ~a;
    char and_a_b = a & b;
    printf("var is equal to %d and NOT is %d hex %hhX\n",a, not_a, not_a);
    printf("var is equal to %d and AND with b is %d hex %hhX\n",a, (char)and_a_b, and_a_b);

    make_not((void *)&a1, CHAR_TYPE);
    printf("minus var is  %d not %hhx\n",minus_a, ~minus_a );
}

/* cast what you want to not
and also cast return to same size*/
void make_not(void * var, enum TYPES_C var_type)
{
    if (var_type == CHAR_TYPE)
    {
        printf("Function: \n var is equal to %d ",*(char*)var);
        *(char *)var = ~*((char*)var);
        printf("and NOT is %d hex %hhX\n", *(char*)var, *(char*)var);
    }


}