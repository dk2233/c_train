#include "arg_parse.h"
#include "arguments_functions.h"

argument_config_t arg_config[] = {
    {"-a" , .function_to_parse.function_arg_array = argument_array, "give an array size to be listed"},
    {"-rb" , .function_to_parse.function_arg_array = argument_file_read_point, "read file -rb<file name>"},
    {"-hash=",.function_to_parse.function_arg_array = argument_hashes, "calculate hash using dbj"},
    {"", NULL, NULL}, /* this line is a marker of last element*/

};
