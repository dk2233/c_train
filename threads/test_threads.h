#include "threads.h"
#include "stdint.h"

#define MAX_THREADS   2u

#define CH1_THREADS_NUMBER 10u

typedef struct 
{
    thrd_t thread;
    uint32_t arg;
    /* data */
} test_thread_func_t;

extern void test_c11_threads(void);