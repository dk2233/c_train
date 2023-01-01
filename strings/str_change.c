#include <string.h>
#include <stdio.h>
#include "func_pointers.h"
#include "defines.h"
#include "str_change.h"
#include <stdlib.h>
#include "console-colors.h"
#include "str_functions.h"

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
    this string cannot be changed - it points to read only memory
    */
    //str_not_changable[0] = 'a';

    char string_changable[] = "this can be changed You can try on your own. can!";

    string_changable[0] = 'T';

    cc_fprintf(CC_BG_GREEN, stdout, " give string:");

    scanf("%[^\n]s",string_to_change);

    uint32_t * tab =  string_find_string(string_changable, string_to_change);

    cc_fprintf(CC_FG_DARK_GREEN, stdout, "%s have been found in idx %d in \'%s\'\n", string_to_change, tab[0], string_changable);

    printf("check_type of string array %s \n", check_type( string_to_change));
    printf("check_type of variable i is %s \n", check_type( i));

    string_letter_replace(string_to_change);
    printf("%s\n",string_to_change);


    printf("string %s has length %d\n", string_to_change,  string_length(string_to_change));

    char *str1 = calloc(MAX_LETTERS_FROM_KB, sizeof(char));
    printf("give second string >");
    scanf("%s",str1);

    printf("str len %ld %d \n",strlen(str1), string_length(str1));
    /* here new str2 is allocated that will keep exact str size that was given from keyboard*/
    char *str2 = calloc(string_length(str1) + 1, sizeof(char));

    string_copy(str2, str1);
    string_concat(&str2, " _ ");
    int final_len = string_concat(&str2, string_to_change);
    printf("%s \n", str2);

    free(str1);
    free(str2);
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


