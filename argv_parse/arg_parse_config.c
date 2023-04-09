#include "arg_parse.h"
#include "arguments_functions.h"

argument_config_t arg_config[] = {
    {"-a" , .function_to_parse.function_arg_char = argument_array, "give an array size to be listed", 0, 0},
    {"-rb" , .function_to_parse.function_arg_char = argument_file_read_point, "read file -rb<file name>", 0, 0},
    {"-hash=",.function_to_parse.function_arg_char = argument_hashes, "calculate hash using dbj", 0, 0},
    {"-file=",.function_to_parse.function_arg_char = argument_file_read, "open text file and read some line",0 ,0},
    {"-fs=",.function_to_parse.function_arg_char = argument_file_size,"check file size with time measurement",0 ,0},
    {"", NULL, NULL, 0, 0}, /* this line is a marker of last element*/

};
