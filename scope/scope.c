#include <stdio.h>

int a  = 500;

static void global_scope();

static void global_scope()
{
    printf("global value from function all %d\n", a);
}

void scope_blocks(void)
{
    int a = 20;

    {
        int a = {40};
        printf("local variable in block %d\n",a);

    }
    printf("local variable outside block %d\n", a);
    {
        printf("local variable in 2nd block %d\n",a);

    }

    global_scope();
}