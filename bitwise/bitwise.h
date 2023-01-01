#ifndef BITWISE_H
#define BITWISE_H
#include "defines.h"

#define CHECK_BIT_VALUE(x) ((x)? 1 : 0)

extern void test_different_bitwise(void);

extern void make_not(void * var, enum TYPES_C var_type);

extern void make_not_ptr(void * var, void * var_type_ptr);

extern void make_not_int(void * var, int var_type_int);

extern void print_binary(void * value, int type_of_var);

#endif