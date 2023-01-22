#include "recur.h"
#include <stdio.h>
#include <assert.h>

#define BYTE_SIZE   8U

static int count_bits = 0;

static struct byte_structure result = {0, 0};


struct byte_structure bitCount(int val) {
    static int count_repeat = 0;
    static struct byte_structure byte_data = {0, 0};
    
    if (0 == count_repeat )
    {
        byte_data.bits_cnt = 0;
        byte_data.ones_cnt = 0;

    }

   if (val>0)
      {
       byte_data.bits_cnt++;
       if (val % 2) byte_data.ones_cnt++;
       val = val / 2;

      } 
   count_repeat++;
//    printf("repeat %d val %d \n",count_repeat, val);     
   if (val > 0)  bitCount(val);

    count_repeat = 0;
   
   return byte_data;
}


int bitCountShift(int value)
{
    int count = 0;
    while(value > 0)
    {
        if (value & 1) count++;

        value >>= 1;
    }
    return count;
}

int rec_mul(int input)
{

    static int result;
    if (input > 0)
    {
        result = rec_mul(input) + 2U;
        input--;
    }

    return result;
}

int power_of_2(int base, int input)
{
    /*  2^2 - 2 + 2
     *  2^3 - (2 + 2) + (2 + 2) 
     *
     *  */
    static int result = 1;

    input--;
    if (input > 0)
    {
        result = base + base;

        result = power_of_2(result, input);
    }
    return result;
}


void recursion_playground(void)
{

    struct how_many_bits
    {
        int number;
        unsigned int count;
    };

    typedef struct
    {
        int base;
        int power_to;
    } type_numbers;

    type_numbers tab_numbers[] =
    {
        { 2, 5},
        {2, 3},
        {2, 8}

    };
    int nr;
#ifdef TESTS
/*
simple unit tests*/
struct byte_structure test_43445 = { 9, 16 };
struct byte_structure test_64 = { 1, 7 };


assert( (bitCount(64)).ones_cnt == test_64.ones_cnt);
assert( (bitCount(64)).ones_cnt == test_64.ones_cnt);
assert( (bitCount(43445)).bits_cnt == test_43445.bits_cnt);
assert( (bitCount(43445)).bits_cnt == test_43445.bits_cnt);
#endif

    printf("podaj liczbe:");
    scanf("%d", &nr);
    struct byte_structure result = bitCount(nr);
    printf(" ones in %d is %d\n bits position %d\n", nr, result.ones_cnt, result.bits_cnt);


    for ( unsigned char i = 0; i < (sizeof(tab_numbers)/ sizeof( type_numbers)); i++)
    {

        printf(" %d to the power  %d is %d\n ",
               tab_numbers[i].base,
               tab_numbers[i].power_to,
               power_of_2(tab_numbers[i].base,tab_numbers[i].power_to));
    }


    struct how_many_bits numbers_struct = {0, 0};

    numbers_struct.number = 127;
    numbers_struct.count = bitCountShift(numbers_struct.number);


    numbers_struct.number = 1000;
    numbers_struct.count = bitCountShift(numbers_struct.number);

}