

#include "pthread.h"
#include "recur.h"
void * function_4_thread(void * input)
{
    printf(" %d \n",power_of_2(2,30));


}

void pthread_test(void)
{
     pthread_t pthread_test;

    pthread_create(&pthread_test, NULL, &function_4_thread, NULL);
}


