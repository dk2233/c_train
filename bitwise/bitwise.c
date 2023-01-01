/*

file to test some bitwise solutions


*/

#include <stdio.h>
#include "bitwise.h"
#include "defines.h"
#include "func_pointers.h"




void test_different_bitwise(void)
{
    /* here static is required to be sure 
    this varibale has its own address*/
    static char a = 9;
    static char b = 5;
    char minus_a = -9;
    char a1 = a;
    static int a_int = 9;

 function_ptr_def fptr_array[] = 
{
    {.func_union.function_ptr_int=&make_not_int, (void*)&a_int, NULL, NULL, (int)INT_TYPE},
    {.func_union.function_ptr_int=&make_not_int, (void*)&a, NULL, NULL, (int)CHAR_TYPE},
    {.func_union.function_ptr_int=&make_not_int, (void*)&b, NULL, NULL, (int)CHAR_TYPE},
    {.func_union.function_ptr_int=&make_not_int, (void*)&a_int, NULL, NULL, (int)INT_TYPE},
    {.func_union.function_ptr_int=&print_binary, (void*)&a_int, NULL, NULL, (int)INT_TYPE},
    {.func_union.function_ptr_int=&print_binary, (void*)&a, NULL, NULL, (int)CHAR_TYPE},
    {.func_union.function_ptr_int=&print_binary, (void*)&a_int, NULL, NULL, (int)INT_TYPE},
};

 function_ptr_struct_composition fptr_struct= {
    .elements_number = 7,
    &fptr_array[0]
};

    /*
    
    if we want to show hex value of not we need to specify its size
    char is hh
    */
    
    char not_a = ~a;
    char and_a_b = a & b;
    int int_enum = (int)INT_TYPE;
    printf("var is equal to %d and NOT is %d hex %hhX\n",a, not_a, not_a);
    printf("var is equal to %d and AND with b is %d hex %hhX\n",a, (char)and_a_b, and_a_b);

    make_not((void *)&a1, CHAR_TYPE);
    make_not((void *)&a1, SHORT_TYPE);
    make_not((void *)&a1, INT_TYPE);
    make_not((void *)&int_enum, INT_TYPE);
    printf("minus var is  %d not %hhx\n",minus_a, ~minus_a );


    call_all_function(&fptr_struct);
    call_all_function(&fptr_struct);

}

/* cast what you want to not
and also cast return to same size*/
void make_not(void * var, enum TYPES_C var_type)
{
    if (var_type == CHAR_TYPE)
    {
        printf("Function: \n char var is equal to %d ",*(char*)var);
        *(char *)var = ~*((char*)var);
        printf("and NOT is %d hex %hhX\n", *(char*)var, *(char*)var);
    }
    else if (var_type == INT_TYPE)
    {
        printf("Function: \n int var is equal to %d ",*(int*)var);
        *(int *)var = ~*((int*)var);
        printf("and NOT is %d hex %X\n", *(int*)var, *(int*)var);
    }
    else if (var_type == SHORT_TYPE)
    {
        printf("Function: \n short var is equal to %d ",*(short*)var);
        *(short *)var = ~*((short*)var);
        printf("and NOT is %d hex %hX\n", *(short*)var, *(short*)var);
    }

}
/* translation to different function usage*/
void make_not_ptr(void * var, void * var_type_ptr)
{
    make_not(var, *(enum TYPES_C *)var_type_ptr );
}

void make_not_int(void * var, int var_type_int)
{
    enum TYPES_C en1 = (enum TYPES_C) var_type_int;
    make_not(var, (enum TYPES_C)var_type_int);
}

void print_binary(void * value, int type_of_var)
{
    int size = 0;
    
    if (type_of_var == (int) CHAR_TYPE)
    {
        size = sizeof(char) * 8;        
        char var = *(char*) value;
        printf("%d 0b",var);

        for ( int i = (size - 1); i >= 0; i--)
        {
            unsigned int mask = 1 << i;

            printf("%d", CHECK_BIT_VALUE(mask & var) );
        }
    }
    else if (type_of_var == (int) SHORT_TYPE)
    {
        size = sizeof(short) * 8 ;
        short var = *(short*) value;
        printf("%d 0b",var);
        for ( int i = (size - 1); i >= 0; i--)
        {
            unsigned int mask = 1 << i;

            printf("%d", CHECK_BIT_VALUE(mask & var));
        }
    }
    else if (type_of_var == (int)INT_TYPE)
    {
        size = sizeof(int) * 8;
        int var = *(int*) value;
        printf("%d 0b",var);
        for (int i = (size - 1); i >= 0; i--)
        {
            unsigned int mask = 1 << i;

            printf("%d", CHECK_BIT_VALUE(mask & var));
        }
    }

    printf("\n");


}
