#include <stdint.h>

unsigned long
    hash_dbj2(unsigned char *str)
    {
        unsigned long hash = 5381;
        int c;

        while (c = *str++)
            hash = ((hash << 5) + hash) + c; /* hash * 33 + c */

        return hash;
    }


uint32_t hash_knuth(int key) {
    uint32_t k = (uint32_t)key;
    // 2654435761 to liczba pierwsza bliska (2^32 / złoty podział)
    return (k * 2654435761u); 
}



