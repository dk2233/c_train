#include <string.h>
#include <stdio.h>
#include "func_pointers.h"

typedef struct{
    char searched;
    char new_letter;
}letter_change_t;

static const letter_change_t letter_change_a[]=
{
    {'m','e'},
    {'n','l'},
    {'t','n'},
    {'i','a'},
    {'q','i'},
    {'v','t'},
    {'j','h'},
    {'u','m'},
    {'w','s'}
};

#define NR_LETTER_TO_CHANGE sizeof(letter_change_a)/sizeof(letter_change_t)


void string_letter_replace(char *input_string)
{
    char *a_p;

    printf("%s\n",input_string);
    //for(char i=0;i<strlen(input_string);i++)
    {
        for(unsigned int letter_iter=0;letter_iter<NR_LETTER_TO_CHANGE; letter_iter++)
        {
            do
            {
                a_p=strchr((const char *)input_string,letter_change_a[letter_iter].searched);

                if (NULL !=a_p)
                    a_p[0]=letter_change_a[letter_iter].new_letter;
            }while(a_p !=NULL);
            /*if (letter_change_a[letter_iter].searched==input_string[i])
              input_string[i]=letter_change_a[letter_iter].new_letter;*/
        }
    }
}

