/**
 * @file
 * @brief general details of file
 */

#ifndef RECUR_H
#define RECUR_H

struct byte_structure 
{
    int ones_cnt;
    int bits_cnt;

};

extern struct byte_structure bitCount(int val) ;

extern int bitCountShift(int val);

extern long int power_of_2(int base, int input);

extern 
void recursion_playground(void);

#endif /*  */

