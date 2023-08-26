

#include "pthread.h"
#include "recur.h"
#include "stdio.h"
#include "stdint.h"

void * function_4_thread(void * input);
void * threads_loop(void * input);
void * fun_thread1(void *arg);
void *fun_ch1_thread(void *arg);
void pthread_challenge1(void);
void *fun_ch2_thread(void *arg);
void pthread_challenge2(void);

#define MAX_THREADS   5u
#define CH1_THREADS_NUMBER 10u

static int result = 0;
static pthread_mutex_t lock_mutex;
static pthread_cond_t condition_var;
static int counter_ch1 = 0;


void * fun_thread1(void *arg)
{
    /* check the order */
    printf("2.Jason \n");
    pthread_exit("Bye");
}

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
    /* disable this line to see a mixed work of both pthread
    
    in case this line exists - first thread locks and make second thread to be halted*/
    pthread_mutex_lock(&lock_mutex);
    
    for(uint32_t i = 0u; i< *(uint32_t *) input ; i++ )
    {
        j++;
        if (j % 1000 == 0)
        {
            printf(" thread %ld, input %d,  i = %d\n", pthread_self(), *(uint32_t *) input, i);
        }


    }
    pthread_mutex_unlock(&lock_mutex);

}

void pthread_test(void)
{
     pthread_t pthread1[MAX_THREADS];
     int return_value = 0;
     int *return_value_p = &return_value;
     int data = 24;
     uint32_t how_many_repeats[2u] = {5000u, 20000u} ;
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
   pthread_mutex_init(&lock_mutex, NULL);

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


    if (pthread_create(&(pthread1[2]), NULL, fun_thread1, NULL) != 0)
    {
        perror("pthread_create error \n");
    }
    printf("1.Fedin \n");

    if (pthread_join(pthread1[2], NULL) != 0)
    {
        perror("pthread_join error");
    }    

    pthread_challenge1();
    pthread_challenge2();

}

void *fun_ch1_thread(void *arg)
{
    printf("message %d, thread %ld, read counter %d\n", *(uint16_t *)arg, pthread_self(), counter_ch1 );
    counter_ch1++;
    printf("read counter after increased %d \n", counter_ch1);
}

void *fun_ch2_thread(void *arg)
{
    pthread_mutex_lock(&lock_mutex);
    printf("message %d, thread %ld, read counter %d\n", *(uint16_t *)arg, pthread_self(), counter_ch1 );
    counter_ch1++;
    printf("read counter after increased %d \n", counter_ch1);
    pthread_mutex_unlock(&lock_mutex);
}
/*

this function shows that in such case like defined here
global counter change will not have any specific order every time
you run function again - you should never expect any specific behaviour with threads

unless you use them in specific way

*/
void pthread_challenge1(void)
{
    pthread_t pthread_ch1_a[CH1_THREADS_NUMBER] = {0u};
    static uint16_t message_array[CH1_THREADS_NUMBER] = {0u};
    static uint16_t i = 0u;
    counter_ch1 = 0u;

    perror("\nchallenge1\n");
    for(i = 0u; i < CH1_THREADS_NUMBER; i++)
    {
        message_array[i] = i;
        if (pthread_create(&(pthread_ch1_a[i]), NULL, fun_ch1_thread, (void*)&(message_array[i])  ) != 0)
        {
            printf("problem creating thread %d\n",i);
        }
    }


    for( i = 0u; i < CH1_THREADS_NUMBER ; i++)
    {
        if (pthread_join(pthread_ch1_a[i], NULL) != 0)
        {
            printf("problem joining %d",i);
        }
    }


}

void pthread_challenge2(void)
{
    pthread_t pthread_ch2_a[CH1_THREADS_NUMBER] = {0u};
    static uint16_t message_array[CH1_THREADS_NUMBER] = {0u};
    static uint16_t i = 0u;
    counter_ch1 = 0u;

    perror("\nchallenge 2\n");
    for(i = 0u; i < CH1_THREADS_NUMBER; i++)
    {
        message_array[i] = i;
        if (pthread_create(&(pthread_ch2_a[i]), NULL, fun_ch2_thread, (void*)&(message_array[i])  ) != 0)
        {
            printf("problem creating thread %d\n",i);
        }
    }


    for( i = 0u; i < CH1_THREADS_NUMBER ; i++)
    {
        if (pthread_join(pthread_ch2_a[i], NULL) != 0)
        {
            printf("problem joining %d",i);
        }
    }
}