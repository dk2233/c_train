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
#include <time.h>
#include "structs.h"
#include "files.h"

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

    double time = time_measurement();

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

    printf("Time measured %lf \n", time_measurement());
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

    char * file_name_points = "file1.bin";
    FILE * file1 = file_binary_open(file_name_points);

    Point *array_of_points;
    int nr = define_Point_struct(&array_of_points);

    size_t how_many_was_written = fwrite((const void*)array_of_points, sizeof(Point), nr, file1);
    printf("%ld point structs were written to %s\n", how_many_was_written, file_name_points );

    free(array_of_points);
    fclose(file1);


}



long int file_length(FILE *file_hd)
{
    long int file_size = 0UL;

    if (file_hd != NULL)
    {
        printf("actual location %ld ",ftell(file_hd));

        if(0 == fseek(file_hd, 0U, SEEK_END ))
        {

            file_size = ftell(file_hd);

            printf("actual location %ld ",ftell(file_hd));

        }
        /*  We need to return position to beginnin of file */
        fseek(file_hd, 0U, SEEK_SET );
        printf("actual location %ld \n",ftell(file_hd));
    }
    return file_size; 
}


void func_open_file(char * name, char * mode, FILE ** file_hd)
{
    /* open file in given mode */
    *file_hd = fopen((char*)name,(const char *)mode);

    if (NULL == *file_hd)
    {
        printf(" file: %s cannot be open\n",(char*)name);
    }
}

void func_open_file_FILE(void * name, void ** file_handler )
{
    /*  this type of function to return FILE pointer
     *  cannot work
     *  we need to use here ** double pointer
     *  to be able to return a pointer to changed pointer to FILE */
    FILE **file_hd = (FILE **)file_handler;

    *file_hd = fopen((char*)name, "r") ;

    if (NULL != *file_hd)
    {
        printf("file handler address %p\n",file_hd);
        char char1 = fgetc(*file_hd);
        printf("line from file: %s\n",(char*)name);
        while( (char1 != '\n' ) && (char1 != '\0'))   
        { 
            char1 = fgetc(*file_hd);
            printf("%c",char1);
        }
    }
}


int whole_file_to_one_str( FILE *file_handler, char *table )
{
    int is_it_ok = 0;

    if ((file_handler != NULL) && (table != NULL))
    {

        char character;
        do 
        {
            character = fgetc(file_handler);
            if ( (character != '\0') &&(character >-1 ) )
            {
            *(table++) = character;
            }
        }
        while( (character != '\0') &&(character >-1 ) );

    }
    else
    {
    is_it_ok = 1;
    }

    return is_it_ok;


}

FILE * file_binary_open(char* file_name)
{
    FILE * file1 = fopen(file_name, "rb+");

    if (file1 == NULL)
    {
        /* there is no such file
        create new*/

    file1 = fopen(file_name, "w+b");
    }


    return file1;

}