#include <stdio.h>
#include "c_types.h"



type_and_size_t type_tosize[] = 
{
    {"char", sizeof(char)},
    {"signed char", sizeof(signed char)},
    {"unsigned char", sizeof(unsigned char)},
    {"short", sizeof(short)},
    {"void", sizeof(void)},
    {"int", sizeof(int)},
    {"long int", sizeof(long int)},
    {"unsigned int", sizeof(unsigned int)},
    {"long long int", sizeof(long long int)},
    {"float", sizeof(float)},
    {"double", sizeof(double)},
    {"long double", sizeof(long double)},
    {"_Bool", sizeof(_Bool)},
    {"",0    }
};



void show_all_defined_types(type_and_size_t *table)
{

    int i = 0 ;
    while( table[i].type_name != "")
    {
        printf("%d -> %s  its size in bytes : %ld\n",i, table[i].type_name, table[i].size_of_type);
        i++;
    }


}