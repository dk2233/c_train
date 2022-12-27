#include "arg_parse.h"
#include "arguments_functions.h"

argument_config_t arg_config[] = {
    {"-a" , .function_to_parse.function_arg_array = argument_array},
    {"-rb" , .function_to_parse.function_arg_array = argument_file_read_point},
    {"", NULL}, /* this line is a marker of last element*/

};
