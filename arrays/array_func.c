#include "array_func.h"
#include "defines.h"
#include "stdlib.h"
#include "stdio.h"
#include <stddef.h>
#include <string.h>


unsigned int tab_a[ARRAY_SIZE];
unsigned int * array_p;

# define VAR_A   10U

/*
 * array without definition of how many rows - but it has how many columns
 */
uint8_t arra[][4] =
{
    { 0,3},
    {3,5,6, 67},
    {1}

};
/*
 * check to create an array that will allocate on heap, initialize and return pointer
 *  problem - it let to create only int type
 */
int * array_int_heap_create(int nr_element)
{
    /*
     *  is it possible to return internal array_a
     *  and have access to it after leaving this function?*/
    static int *array_a;
    int i;

    array_a =malloc(nr_element* sizeof(int));

    for(i=0; i<nr_element; i++)
    {
        array_a[i]=2+i;
    }
    return array_a;
}


/*check if when no explicitly define size of array
 * it still works fine
 * however it may depend on used compiler
 * on gcc it is fine
 * */
int check_possibility_of_not_defining_size(void)
{
    printf(" DEFINITION %d \n",VAR_A);
    printf(" size of %ld \n",sizeof(arra)/sizeof(arra[0]));

    for(uint8_t iter1 = 0U; iter1 < (sizeof(arra)/sizeof(arra[0])); iter1++ )
    {
        for(uint8_t iter2 = 0U; iter2 < (sizeof(arra[0])); iter2++ )
        {
            printf("%d ",arra[iter1][iter2]);
        }
        printf("\n");
    }
    return 0;
}

/* simple array displaying of one type */
void display_array(int * tab, size_t size)
{
    int iter = 0;
    for(; iter < size; iter++)
    {
        printf("tab[%d] %d\n", iter, tab[iter]);
    }

}
/*
this function allocates array and returns its pointer **

if call second time it should free buffer
*/
bool create_array(void ** tab, int size_of_array, size_t size_of_one_element )
{
    bool state = false;

    if ((*tab == NULL) && (size_of_array > 0))
    {
        *tab = calloc(size_of_array, size_of_one_element);
        if (*tab != NULL)
        {
            printf("array allocated %p \n", *tab);
            state = true;
        }
        else
        {
            printf("error\n");
            state = false;
        }
    }
    else
    {
    free(*tab);
    }

    return state;

}

void char_array_malloc(char ** tab_array, int size)
{

    printf("lets do some malloc playtime\n");

    for(int i = 0 ; i < size; i++)
    {
        printf("give word %d/%d:",i+1,size);
        tab_array[i] = calloc(1000, sizeof(char));
        scanf("%s",tab_array[i]);

    }
    for(int i = 0; i < size; i++)
    {
        printf("%p -> %s\n", &tab_array[i], tab_array[i]);
    }
    printf("*********END Test array char **********\n");


    for(int i = 0 ; i < size; i++)
    {
        free(tab_array[i]);
    }
}


char **** split_string_paragraph_sentence_word(char * str)
{
    char **** doc = calloc(1, sizeof(char***));

    int p = 0 , s = 0, w = 0;
    int i = 0, w_i = 0;
    char c = str[i]; 
    char buffor[MAX_LINE_SIZE] = "\0";
    
    //new sentence
    doc[p] = calloc(1, sizeof(char **));
    doc[p][s] = calloc(1, sizeof(char *));

    while(c != '\0')
    {
        if ( (c == ' ') || (c == '.') || (c== '\n') )
        {
           buffor[w_i] = '\0'; 

           if (w_i > 0)  {
               w_i++;

               if (w > 0)      doc[p][s] = realloc(doc[p][s], (w+1)*sizeof(char*));
               

               doc[p][s][w] = calloc(w_i, sizeof(char)) ;
               strcpy(doc[p][s][w], buffor);
               w++;

               printf("\"%s\" ", buffor); 
           }

           w_i = 0;

           if (c == '.') { 

               //one adiotional word to hold NULL
               doc[p][s] = realloc(doc[p][s], (w+1)*sizeof(char*));
               doc[p][s][w] = NULL;

               s++;
               doc[p] = realloc(doc[p],(s+1)*(sizeof(char**)));
               doc[p][s] = calloc(1, sizeof(char *));

               printf(".\n");
                w = 0;

           }
           else if (c == '\n') {
               doc[p] = realloc(doc[p],(s+1)*(sizeof(char**)));
               doc[p][s] = NULL;

               p++;
               w = 0;
               s = 0;
               doc = realloc(doc, (p+1)*(sizeof(char***) ));
               doc[p] = calloc(1, sizeof(char**));
               doc[p][s] = calloc(1, sizeof(char *));

               printf("\nEnter\n");

           }
        }
        else 
        {
            buffor[w_i++] = c;
        }


        c = str[++i];
    }
    doc[p] = NULL;
    return doc;
}

void sandbox_char_array(void)
{
    #define TAB_ARRAY_SIZE 4u

    void *vp;

    /* 
     *
     * array of char * words
     */
    char * tab_array[TAB_ARRAY_SIZE] = {"word1", "word2", "alpha1", "::bvxc"};
    printf("********* Test array char **********\nThis here shows addresses based on const pointers char:\n");

    for(int i = 0; i < TAB_ARRAY_SIZE; i++)
    {
        printf("%p -> %s\n", &tab_array[i], tab_array[i]);
    }

     char **pp_char = &tab_array[1];
     char *p_char = *pp_char;
     vp = (void*)p_char;

     int *(p_int) = (int*)vp;
     p_int++;

    /* where this pp_char points to */
    pp_char++;
    p_char++;
    /* and now where*/


    //char_array_malloc(tab_array,TAB_ARRAY_SIZE);


    char  text[2500] = "\“Po tym, jak Elfarran i Morred zginęli, a wyspa Solea zatonęła pod falami, Rada Mędrców władała w imieniu chłopca Serriadha, póki ten nie objął tronu. Panował mądrze, lecz krótko, po nim zaś na Enladzie nastało siedmiu królów. Kraina bogaciła się i żyła w pokoju. I wtedy zjawiły się smoki, najeżdżające zachodnie ziemie. Czarnoksiężnicy na próżno próbowali je powstrzymać. Król Akambar przeniósł dwór z Berili na Enladzie do miasta Havnor. Stamtąd wyruszył na czele floty przeciw najeźdźcom z Krain Kargadzkich i wyparł ich na wschód. Oni jednak nadal wysyłali łupieżcze statki, które zapuszczały się nawet na Morze Najgłębsze. Ostatni z królów, Maharion, zawarł pokój ze smokami i Kargami, zapłacił jednak olbrzymią cenę, kiedy zaś Pierścień Runiczny został złamany, Erreth-Akbe zginął w walce z wielkim smokiem, a Maharion Śmiały padł ofiarą zdrady, zdawało się, że na Archipelagu niepodzielnie zapanowało zło.\nWielu próbowało objąć tron Mahariona, nikt jednak nie zdołał go utrzymać, a spory pretendentów podzieliły kraj. Miejsce wspólnoty i sprawiedliwości zajęły kaprysy możnowładców. Szlachetnie urodzeni, kupcy i piraci, każdy, kto mógł sobie pozwolić na wynajęcie żołnierzy i czarnoksiężników, ogłaszał się władcą wybranych ziem i miast. Wodzowie czynili z pokonanych niewolników, lecz najemni chłopi także byli niewolnikami, albowiem tylko panowie bronili ich przed innymi wodzami łupiącymi wyspy i piratami nękającymi porty, a także bandami nieszczęsnych banitów, których głód popychał do rabunku\".\nKsięga Mroku powstała pod koniec czasów, o których traktuje. To zbiór wzajemnie sprzecznych opowieści, częściowych biografii i zniekształconych legend. Jest jednym z nielicznych reliktów pochodzących z Mrocznych Lat, gdyż złaknieni pochwał, nie prawdziwych historii wodzowie palili książki, z których jakiś pozbawiony władzy biedak mógł nauczyć się, jak ją zdobyć.\n";


    //printf("%s\n",text);
    //
    char **** tab = split_string_paragraph_sentence_word(text);

    int w = 0;
    int s = 0;
    int p = 0;
    while(tab[p] != NULL)
    {
        while(tab[p][s] != NULL){
            while(tab[p][s][w] != NULL)
            {
                printf("%s ", tab[p][s][w]);
                free(tab[p][s][w++]);


            }

            w=0;
            free(tab[p][s]);
            printf(". ");
            s++;
        }
        
        s=0; w=0;
        free(tab[p]);
        printf("\n");
        p++;
    }
    free(tab);


}




