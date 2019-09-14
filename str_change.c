#include <string.h>
#include <stdlib.h>

typedef struct{
    char searched;
    char new_letter;
}letter_change_t;

static const letter_change_t letter_change_a[]={
    {'m','e'},
    {'n','l'}
};

#define NR_LETTER_TO_CHANGE sizeof(letter_change_a)/sizeof(letter_change_t)



void string_letter_replace(char *input_string)
{
    char *a_p;
    
    printf("%s\n",input_string);
    //for(char i;i<sizeof(input_string);i++)
    {
        //printf("%d, ",i);

        for(char letter_iter=0;letter_iter<NR_LETTER_TO_CHANGE; letter_iter++)
        {
            do
            {
                a_p=strchr(input_string,letter_change_a[letter_iter].searched);

                if (NULL !=a_p)
                    *a_p=letter_change_a[letter_iter].new_letter;
                printf("%s\n",input_string);
            }while(a_p !=NULL);


        }
    }

}

