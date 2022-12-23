#include <stdint.h>

#define MAX_LETTERS_FROM_KB   100U

extern int string_concat(char** dest, char * src);

extern uint32_t * string_find_string(char* string, char* str_searched);

extern char * string_copy(char * dst, char * copied_string);

extern uint32_t string_length(char* str);