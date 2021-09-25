#include <stdio.h>
#include <stdint.h>

#define MAX_TEST_WITH_CAST 7U

static short int tab_with_test[MAX_TEST_WITH_CAST] = 
{
    127U,
    INT16_MIN,
    INT16_MAX,
    INT16_MAX+1,
    INT16_MIN-1,
    -3,
    INT16_MIN + 10,
};


static unsigned short  int tab_with_test_unsigned[MAX_TEST_WITH_CAST] = 
{
    UINT16_MAX,
    UINT16_MAX-1,
    INT16_MAX,
    INT16_MAX+1,
    INT16_MIN-1,
    3,
    INT16_MIN + 10,
};
unsigned short int cast_uint_to_int(short int a, short int b)
{
    unsigned short int ret_val;

    printf("bf cast %d ",a);
    ret_val = (unsigned short int)a;
    printf(" and after %u \n",ret_val);

    return ret_val;
}

 short int cast_int_to_uint(unsigned short int a, short int b)
{
     short int ret_val;

    printf("bf cast %u ",a);
    ret_val = ( short int)a;
    printf(" and after %d` \n",ret_val);

    return ret_val;
}

void loop_all_tests(void)
{
    printf("size of short int %ld \n", sizeof(short int));
    for( unsigned int i = 0U; i < MAX_TEST_WITH_CAST; i++)
    {
        cast_uint_to_int( tab_with_test[i] , 0);   
    }

}


void loop_all_tests_int(void )
{
    printf("size of unsigned short int %ld \n", sizeof(unsigned short int));
    for( unsigned int i = 0U; i < MAX_TEST_WITH_CAST; i++)
    {
        cast_int_to_uint( tab_with_test_unsigned[i] , 0);   
    }

}


