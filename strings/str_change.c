#include <string.h>
#include <stdio.h>
#include "func_pointers.h"
#include "defines.h"
#include "str_change.h"
#include <stdlib.h>

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


void string_different_tests(void)
{
    char string_to_change[40];
    char * str_not_changable = "if you try to change this string it will not work you will see core dump\n";
    uint8_t i = 0 ;


    /*
    string cannot be changed - it points to read only memory
    */
    //str_not_changable[0] = 'a';

    char string_changable[] = "this can be changed";

    string_changable[0] = 'T';

    printf(" give string:");

    scanf("%[^\n]s",string_to_change);

    printf("check_type of string array %s \n", check_type( string_to_change));
    printf("check_type of variable i is %s \n", check_type( i));

    string_letter_replace(string_to_change);
    printf("%s\n",string_to_change);


    printf("string %s has length %d\n", string_to_change,  string_length(string_to_change));

    char *str1 = calloc(MAX_LINE_SIZE, sizeof(char));
    printf("give second string >");
    scanf("%s",str1);

    /* here new str2 is allocated that will keep exact str size that was given from keyboard*/
    char *str2 = calloc(string_length(str1), sizeof(char));

    strcpy(str2, str1);
    strig_concat(&str2, " _ ");
    int final_len = strig_concat(&str2, string_to_change);
    printf("%s \n", str2);

    free(str1);
    free(str2);
}

/*
function to measure str length*/
int string_length(char* str)
{
    int l = 0;
    while(str[l] != '\0')
    {
        l++;
    }

    return l;

}

/*
this also automaticaly realloc char* to cover
new string size
1. it checks length of dest and src
2. assumption is dst has exact length how many letters is in there
3. then it calculates the sum of dest and src
4. realloc dst to has required size */
int strig_concat(char** dest, char * src)
{

    int str_len_dest = string_length(*dest) ;
    int str_len_src = string_length(src);

    *dest = realloc(*dest, sizeof(char)* (str_len_dest + str_len_src + 1));
    int i = 0;
    while(i < str_len_src)
    {
        (*dest)[str_len_dest + i] = src[i];
        i++;
    }
    (*dest)[str_len_dest + i] = '\0';

    return str_len_dest + str_len_src;
}