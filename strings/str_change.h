#ifndef STR_CHANGES_H
#define STR_CHANGES_H
/*
 * file with procedure to change 
 * some letters in string
 *
 */


extern void string_letter_replace(char *input_string);

extern void string_different_tests(void);

extern uint32_t string_length(char* str);

extern void string_operation_find_char ( void * str_in, void * char_in  );

extern int string_concat(char** dest, char * src);

extern uint32_t * string_find_string(char* string, char* str_searched);

extern char * string_copy(char * dst, char * copied_string);

#endif
