#include "arg_parse.h"
#include "arguments_functions.h"

argument_config_t arg_config[1] = {
    {"-a" , .function_to_parse.function_arg_array = argument_array},
};
