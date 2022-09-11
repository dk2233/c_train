#ifndef ARRAY_FUNC_H
#define ARRAY_FUNC_H

#include <stdint.h>

#define ARRAY_SIZE	4U

#define FUNCTION_ARGUMENT 10U

extern int * array_parse(int nr_element);

extern int check_possibility_of_not_defining_size(void);

extern void check_array_argument(int tab[FUNCTION_ARGUMENT]);

#endif
