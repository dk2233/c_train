#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include "arg_parse.h"
#include "str_functions.h"

void parser_arguments(int argc, char * argv[])
{
    for(int i = 0; i < argc; i++)
    {

        for (int arg = 0; arg < NR_OF_ARG_TABLE; arg++)
        {
            uint32_t *found = string_find_string(argv[i], arg_config[arg].parameter);

            if (found[0] != -1)
            {
                char *number = calloc(string_length((char *)&argv[i][1]) + 1, sizeof(char));

                number = string_copy(number, (char *)&argv[i][2]);

                arg_config[arg].function_to_parse.function_arg_array(number);
            }
        }
    }
}