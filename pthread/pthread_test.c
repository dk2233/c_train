

#include "pthread.h"
#include "recur.h"
#include "stdio.h"

void * function_4_thread(void * input);

#define MAX_THREADS   5u

static int result = 0;

void * function_4_thread(void * input)
{
    static int value = 9;
    int number = 30;
    printf("thread %ld \n", pthread_self());
    if (NULL != input )
    {
        printf(" %ld \n", power_of_2(2, *(int*) input ));

    }
    else 
    {
        printf(" %ld \n", power_of_2(2, number));
    }
    value++;

    return (void *)&value;

}


void pthread_test(void)
{
     pthread_t pthread1[MAX_THREADS];
     int return_value = 0;
     int *return_value_p = &return_value;
     int data = 24;

    /* 
    
    this creates a simple thread 
    third arguments is a function run in this thread


    */
    if (pthread_create(&(pthread1[0]), NULL, &function_4_thread, NULL) != 0)
    {
        printf("problem with thread creating\n");
        
    }
    
    if (pthread_create(&(pthread1[1]), NULL, &function_4_thread, (void*) &data ) != 0)
    {
        printf("problem with thread creating\n");
        
    }
    /* this line is needed to wait untill process is finished*/
    pthread_join(pthread1[0],(void**)&return_value_p);
    printf("ret value %d \n",*return_value_p);
    pthread_join(pthread1[1],(void**)&return_value_p);
    printf("ret value %d \n",*return_value_p);
}


