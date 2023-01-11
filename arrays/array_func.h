#ifndef ARRAY_FUNC_H
#define ARRAY_FUNC_H

#include <stdint.h>
#include "stdbool.h"
#include "stddef.h"

#define ARRAY_SIZE	4U

#define FUNCTION_ARGUMENT 10U

extern int * array_parse(int nr_element);

extern int check_possibility_of_not_defining_size(void);

extern void check_array_argument(int tab[FUNCTION_ARGUMENT]);

extern bool create_array(void ** tab, int size_of_array, size_t size_of_one_element );

extern void check_char_array(void); 

#endif
