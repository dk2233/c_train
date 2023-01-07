#ifndef ARG_PARSE_H 
#define ARG_PARSE_H

typedef struct argument_config_structure
{
    char * parameter;
    union {
        void (*function_arg_array) (char *argv_parameter); 
        } function_to_parse;
    char * help_str;


}
argument_config_t; 

extern argument_config_t arg_config[];

extern void parser_arguments(int argc, char * argv[]);

#endif