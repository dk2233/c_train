#include <stdio.h>
#include <stdint.h>

#define MAX_TEST_WITH_CAST 5U

static short int tab_with_test[MAX_TEST_WITH_CAST] = 
{
    127U,
    INT16_MIN,
    INT16_MAX/2,
    INT16_MAX+1,
    INT16_MIN-1,

};


unsigned short int cast_uint_to_int(short int a, short int b)
{
    unsigned short int ret_val;

    printf("bf cast %d ",a);
    ret_val = (unsigned short int)a;
    printf(" and after %u \n",ret_val);

    return ret_val;
}

void loop_all_tests(void)
{
    for( unsigned int i = 0U; i < MAX_TEST_WITH_CAST; i++)
    {
        cast_uint_to_int( tab_with_test[i] , 0);   
    }
}
