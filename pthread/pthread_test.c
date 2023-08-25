

#include "pthread.h"
#include "recur.h"
#include "stdio.h"
#include "stdint.h"

void * function_4_thread(void * input);

#define MAX_THREADS   5u

static int result = 0;

void * function_4_thread(void * input)
{
    static int value = 9;
    int number = 30;


    printf("thread %ld  \n", pthread_self());
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

void * threads_loop(void * input)
{

    uint32_t j = 0u;
    for(uint32_t i = 0u; i< *(uint32_t *) input ; i++ )
    {
        j++;
        if (j % 1000 == 0)
        {
            printf(" thread %ld, input %d,  i = %d\n", pthread_self(), *(uint32_t *) input, i);
        }


    }

}

void pthread_test(void)
{
     pthread_t pthread1[MAX_THREADS];
     int return_value = 0;
     int *return_value_p = &return_value;
     int data = 24;
     uint32_t how_many_repeats[2u] = {2000u, 20000u} ;
    size_t stack_size;


    pthread_attr_t attr_pthread_local;
    pthread_attr_init(&attr_pthread_local);
    pthread_attr_getstacksize( &attr_pthread_local, &stack_size);

    printf("attribute stack size %ld \n", stack_size );
    pthread_attr_setstacksize(&attr_pthread_local, 10000000);
    pthread_attr_getstacksize( &attr_pthread_local, &stack_size);
    printf("attribute stack size %ld \n", stack_size );

    /* 
    
    this creates a simple thread 
    third arguments is a function run in this thread


    */
    if (pthread_create(&(pthread1[0]), &attr_pthread_local , &function_4_thread, NULL) != 0)
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

    /* here function may be same and only run differently in each of threads
    
    each of function has to be call with different variables - given via references*/
    if (pthread_create(&(pthread1[0]), NULL, &threads_loop, (void *) &how_many_repeats[0]) != 0)
    {
        printf("problem with thread creating\n");
    }
    
    if (pthread_create(&(pthread1[1]), NULL, &threads_loop, (void*) &how_many_repeats[1]) != 0)
    {
        printf("problem with thread creating\n");
    }

    pthread_join(pthread1[0], NULL);
    pthread_join(pthread1[1], NULL);

    

}


