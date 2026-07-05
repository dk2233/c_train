#include "permut.h"
#include "different_functions.h"
#include "str_functions.h"
#include "files.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE 1024
int compare_strings(const void *a, const void *b) 
{
    return strcmp(*(const char **)a, *(const char **)b);
}

void permutation_test(void)
{

    FILE * file_handler; 
    char buffer[MAX_LINE] = {};

    func_open_file("../permutation/tests.txt", "r", &file_handler);

    if (file_handler != NULL) 
    {
        int n, n2;
        char ** test_s = NULL;
        int i = 0, k = 0, pos_space = 0, word_start = 0;
        while(fgets(buffer, MAX_LINE, file_handler))
        {
            buffer[strcspn(buffer, "\n")] = ' ';
            if (i % 2 == 0) {
                n = -1;
                sscanf(buffer, "%d", &n );
                if (n == -1) break;
                test_s = calloc(n, sizeof(char *));
            }
            else {

                n2 = split_word_to_char_array(buffer, test_s);
                if (n2 == n ){

                    int r = 1;

                    qsort(test_s, n, sizeof(char *) , compare_strings);
                    
                    int perm_nr = 0;
                    while(r == 1) 
                    {
                        show_char_array(n, test_s);

                        r = next_perm_pandita(n, test_s);
                        perm_nr++;
                    }
                    printf("Permutation number %d\n", perm_nr);
                }
                else 
                {
                    show_char_array(n2, test_s);
                    fprintf(stderr, " wrong number of words!\n"); 
                }

                for(k = 0; k < n2; k++)
                {
                    free(test_s[k]);
                }

                free(test_s);
            }
            i++;
        }

    fclose(file_handler);
    }




}
