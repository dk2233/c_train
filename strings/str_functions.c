
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "str_functions.h"


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

char * string_copy(char * dst, char * copied_string)
{
    uint32_t i = 0;
    while(copied_string[i] != '\0')
    {
        dst[i] = copied_string[i];
        i++;
    }
    dst[i] = '\0';
    return dst;
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
 *
 split line with strings seperated with space
 * return number of read words
 */
int split_word_to_char_array(char * line, char ** tab_s)
{
    int k = 0, pos_space = 0, word_start = 0;

    int length = strlen(line);
    while(word_start < length)
    {
        int new_word_len = 0;
        char * point_word_end = strchr(&line[word_start], ' ');

        if (point_word_end == NULL) point_word_end = strchr(&line[word_start], '\n');
        if (point_word_end == NULL) point_word_end = strchr(&line[word_start], '\0');

        if (point_word_end != NULL){
            pos_space =  point_word_end - &line[0]; //position of space for current word
            new_word_len = point_word_end - &line[word_start] ;
        }
        else break;

        if (tab_s != NULL) {
            tab_s[k] = calloc(new_word_len+1, sizeof(char));
            sscanf(&line[word_start], "%s", tab_s[k++] );
            
            while( (pos_space < length) && (line[pos_space] == ' '))  { pos_space++;}

            if (line[pos_space] == '\0') break;
            word_start = pos_space;
            
        }
        else return -1;
    }

    return k;
}
