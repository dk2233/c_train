#include <stddef.h>


typedef struct _type_and_size
{
    char* type_name;
    size_t size_of_type;

} type_and_size_t;

extern type_and_size_t type_tosize[];


extern void show_all_defined_types(type_and_size_t *table);