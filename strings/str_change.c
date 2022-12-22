#include <string.h>
#include <stdio.h>
#include "func_pointers.h"
#include "defines.h"
#include "str_change.h"
#include <stdlib.h>
#include "console-colors.h"

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

    char string_changable[] = "this can be changed You can try on your own. can!";

    string_changable[0] = 'T';

    cc_fprintf(CC_BG_GREEN, stdout, " give string:");

    scanf("%[^\n]s",string_to_change);

    uint32_t * tab =  string_find_string(string_changable, string_to_change);

    printf("%s have been found in idx %d in %s\n", string_to_change, tab[0], string_changable);

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
    string_concat(&str2, " _ ");
    int final_len = string_concat(&str2, string_to_change);
    printf("%s \n", str2);

    free(str1);
    free(str2);
}

/*
function to measure str length*/
uint32_t string_length(char* str)
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
int string_concat(char** dest, char * src)
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

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  str_op_find_char
 *  Description:  
 * =====================================================================================
 */
void string_operation_find_char(void *str_in, void *char_in)
{
    char *str1 =(void *)str_in;
    char searched = *((char *) char_in );

    for( char letter = *str1; letter != '\0' ; str1++, letter = *str1)
    {
        if (letter == searched)
        {
            printf("found letter %c in %s \n",searched, (char*)str_in);
            return;

        }

    }
    printf("NOT found letter %c in %s \n",searched, (char *)str_in);

}		/* -----  end of function str_op_find_char  ----- */


uint32_t * string_find_string(char* string, char* str_searched)
{
    uint32_t * index = calloc(1, sizeof(uint32_t));
    uint32_t j = 0;
    uint32_t ind_start = 0;
    uint32_t last_found_idx = 0;
    uint32_t searched_len = string_length( str_searched);

    index[last_found_idx] = -1;
    
    for(unsigned int i = 0; i < string_length(string) ; i++)
    {

        if (string[i] == str_searched[j])
        {
            if (j == 0)
            {
                ind_start = i;
            }
            j++;
            if (j == searched_len)
            {
                printf("found %s in index %d \n", str_searched, ind_start);
                j = 0 ;
                index[last_found_idx++ ] = ind_start;

                index = realloc(index, last_found_idx * sizeof(uint32_t));
                
                index[last_found_idx] = -1;

            }
        }
        else
        {
            j = 0;

        }

    }
    return index;

}