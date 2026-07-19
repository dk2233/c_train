#ifndef HASH_CALC_H
#define HASH_CALC_H
#include <stdint.h>

typedef struct 
{
    int key;
    int value;

} map_int_data_t;



uint32_t hash_knuth(int key) ;
extern unsigned long
    hash_dbj2(unsigned char *str);

#endif /* HASH_CALC_H*/
