#include "sorts.h"
#include <stdio.h>
#include "different_functions.h"

int compare_int_raise(const void *a , const void *b)
{
    if (*(int*)a < *(int*)b ) return -1;
    else if (*(int*)a == *(int*)b ) return 0;
    else return 1;
}

void print_int(void *data)
{
    printf("%d ",*(int *)data); 
}

void sort_test(void)
{
    int  tab[] ={567, 2,456, -10, 2000, -1000, 23455 };

    int n = sizeof(tab)/ sizeof(int);

    show_base_array(n, (void *)tab, sizeof(int), print_int  );
    sort_bubble((void *)tab, sizeof(tab)/ sizeof(int), sizeof(int),  compare_int_raise);

    show_base_array(n, (void *)tab, sizeof(int), print_int  );


}
