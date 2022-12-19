#include "recur.h"
#include <stdio.h>

#define BYTE_SIZE   8U

int result=0;

int bitCount(int val) {
/*    if (val==0)  result;
 */
   if (val==1)  result++;
   if (val>=2)
      {
      val=val-2;
       result++;
      }   
   if (val > 0)  bitCount(val);
   return result;
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
    scanf("%d", &nr);
    printf(" ones in %d is %d\n            ", nr, bitCount(nr));


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