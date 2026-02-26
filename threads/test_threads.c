#include "test_threads.h"
#include "stdint.h"
#include "stdio.h"


uint32_t shared_resource = 0u;

int func1(void * arg); 


int func1(void *arg)
{
    //thrd
    
    for(uint32_t i = 0u; shared_resource < *(uint32_t *)arg; i++)
    {
        shared_resource++;
        printf("%ld iteration %d -> shared %d \n", thrd_current() ,  i, shared_resource);
    }

    return 0;
}


void test_c11_threads(void)
{
    test_thread_func_t threds_a[MAX_THREADS] = {{.arg = 200}, {.arg = 200}};


    for(uint8_t iter = 0; iter < MAX_THREADS ; iter++)
    {
        if (thrd_success == thrd_create(&(threds_a[iter].thread), &func1,(void *) &threds_a[iter].arg))
        {

            printf("thread created \n");
        }
    }

    for(uint8_t iter = 0; iter < MAX_THREADS ; iter++)
    {

        thrd_join(threds_a[iter].thread, NULL );
    }
    

}