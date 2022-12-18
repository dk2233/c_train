#ifndef DEFINES_H
#define DEFINES_H

#include "stdint.h"


#define THIS_DOES_NOT_WORK  

#define MAX_LINE_SIZE   (1000U)


#define check_type(x) _Generic( (x), \
const int: "const int", \
char: "char",   \
char*: "char pointer *",    \
uint8_t: "uint8_t", \
int: "int",     \
default: "I am not sure")

#endif /* COMPONENT_H */

