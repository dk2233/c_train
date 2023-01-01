#ifndef BITWISE_H
#define BITWISE_H
#include "defines.h"
extern void test_different_bitwise(void);

extern void make_not(void * var, enum TYPES_C var_type);

extern void make_not_ptr(void * var, void * var_type_ptr);

extern void make_not_int(void * var, int var_type_int);

#endif