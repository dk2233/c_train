
#include <stdio.h>

#define ARRAY_SIZE 4u

void check_alignas(void)
{
    /* this is to verify alignas work in C11 or C22*/

    char a_char = 0;
    _Alignas(4) char a_align = 12;
    _Alignas(4) char a_align2 = 12;
    _Alignas(8) char tab[ARRAY_SIZE] = {2,3,4,5};


    printf("sizeof normal char %ld compared to align variable bytes %ld\n",sizeof(a_char), sizeof(a_align)  );
    printf("addresses of normal and align one %p \n %p && %p\n", &a_char, &a_align, &a_align2);

    for(int i = 0; i< ARRAY_SIZE; i++)
    {
        printf("%d address %p\n",i, &tab[i]);
    }

}