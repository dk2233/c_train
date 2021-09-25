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

int bitCount2(int value)
{
    for(unsigned int i = 0U; i<BYTE_SIZE ; i++)
    {

    } 
}

int rec_mul(int input)
{

    static int result;
    if (input > 0)
    {
        result = rec_mul(input) + 2U;
        input--;
    }
}
