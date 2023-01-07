#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include "arg_parse.h"
#include "str_functions.h"

void parser_arguments(int argc, char * argv[])
{
    for(int i = 1; i < argc; i++)
    {

        for (int arg = 0; (arg_config[arg].function_to_parse.function_arg_array != NULL); arg++)
        {
            int32_t *found = string_find_string(argv[i], arg_config[arg].parameter);

            if (found[0] != -1)
            {
                char *number = calloc(string_length((char *)&argv[i][0]) + 1 , sizeof(char));

                if (number != NULL)
                {
                    char *parameter_begin = (char *)argv[i] + string_length(arg_config[arg].parameter);
                    number = string_copy(number, parameter_begin);

                    arg_config[arg].function_to_parse.function_arg_array(number);
                    free(number);
                }
            }
        }
    }

    if (argc < 2)
    {
        int i = 0;
        while(arg_config[i].function_to_parse.function_arg_array != NULL)
        {
            printf("%s %s\n",arg_config[i].parameter,arg_config[i].help_str);
            i++;

        }

    }
}