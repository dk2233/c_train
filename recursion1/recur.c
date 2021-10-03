#include "recur.h"

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
