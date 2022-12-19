/*


Files

playground
opening, closing files



*/

#include <stdio.h>
#include <stdlib.h>
#include "std_lib_object.h"
#include "defines.h"
#include "different_functions.h"

void files_playground(void)
{
    
    /*  opening file in c */
    char *file_name = "cscope.files";
    FILE *file_hd;
    file_hd = fopen(file_name,"r");

    char *str_from_file = calloc(1000U, sizeof(char));
    if (NULL != file_hd)
    {
        str_line((void *)file_hd,(void *) str_from_file);
        printf("1. first line %s \n", str_from_file) ;
        fclose(file_hd);

        if (str_from_file != NULL)
        {
            free(str_from_file);
        }
    }
    else
    {
        printf(" there is no such file %s \n",file_name);
    }

    /* also play with my std_objects struct of function pointers*/
    char *str2 = "Makefile";

    std_objects.open_file(str2, "r",  &file_hd);

    int size_of_file = (int)std_objects.file_size(file_hd);
    printf("file size of Makefile %d \n",size_of_file) ;

    str_from_file = calloc(MAX_LINE_SIZE, sizeof(char));
    if ((file_hd != NULL) && (str_from_file != NULL))
    {
        if (std_objects.read_line_from_file(file_hd, str_from_file) == 0)
        {
            printf("second  %s \n", str_from_file) ;

        }
        str_line((void *)file_hd,(void *) str_from_file);
        printf("first  %s \n", str_from_file) ;

    }
    if (str_from_file != NULL)
    {
        free(str_from_file);
    }
    if (file_hd != NULL)
    {
        fclose(file_hd);
    }

    //"---------------------------------------------------
    char *str3 = "find_linux.sh";
    std_objects.open_file(str3, "r",  &file_hd);

    if (file_hd != NULL)
    {
        size_of_file = (int)std_objects.file_size(file_hd);
        printf(" file size of %s %d \n",str3,size_of_file) ;
        char *tab_str = calloc(size_of_file, sizeof(char));

        if (
                (tab_str != NULL) &&
                (0 == std_objects.copy_file_to_string(file_hd, tab_str ))
           )
        {
            printf("data taken from file %s: \n%s\n", str3, tab_str);
        }
        if (tab_str != NULL)
            free(tab_str);
        fclose(file_hd);
    }

    /* added from std_objects o
     * examples of using function pointers gather into one object */

    char * text = "cscope.files";
    if (0 == std_objects.compare_strings(file_name, text))
    {
        printf(" %s and %s same \n",file_name, text);
    }

    char * ret_loc;
    char *searched_str = ".fil";
    ret_loc = std_objects.find_string(file_name,searched_str );

    if (NULL != ret_loc)
    {

        printf("found searched string %s in %d\n", searched_str,(unsigned int) ( ret_loc - file_name));
    }

}