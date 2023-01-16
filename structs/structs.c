/*


structs playing



*/
#include "structs.h"
#include "defines.h"
#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <stddef.h>

/*
this function shows how to allocate structure of
some type
*/
int define_Point_struct(
    Point ** points_array)
{
    int nr_elements = 0;

    printf("give nr of elements \n");
    scanf("%d",&nr_elements);

    *points_array = malloc(sizeof(Point) * nr_elements);

    if (*points_array != NULL)
    {
        for (int i = 0; i < nr_elements; i++)
        {
            printf("give x and y for %d element\n", i);
            scanf("%d", &(*points_array)[i].x);
            scanf("%d", &(*points_array)[i].y);
        }

        for (int i = 0; i < nr_elements; i++)
        {
            printf("point %d %d \n", (*points_array)[i].x, (*points_array)[i].y);
        }
    }

    return nr_elements;

}

/*
function that allocates new structure
and returns it for further use outside of function
*/
Employee * define_employee_array(int elements)
{
    Employee * employers_db = malloc(sizeof(Employee) * elements);

    if (employers_db != NULL)
    {
        for(int i = 0; i < elements; i++)
        {
            printf("give employee name max 10 letters \n");
            scanf("%s", (char*)&employers_db[i].name );
            printf("give employee age  \n");
            scanf("%f", &employers_db[i].age );
            printf("give employee id \n");
            scanf("%d", &employers_db[i].id );

        }
    }
    return employers_db;
}

/*
function that allocates new structure
and returns it through argument for further use outside of function
*/
void  define_employee_array2(int elements, Employee **employers_db)
{
     *employers_db = malloc(sizeof(Employee) * elements);

    if (*employers_db != NULL)
    {
        for(int i = 0; i < elements; i++)
        {
            printf("give employee name max 10 letters \n");
            scanf("%s", (char*)&(*employers_db)[i].name );
            printf("give employee age  \n");
            scanf("%f", &(*employers_db)[i].age );
            printf("give employee id \n");
            scanf("%d", &(*employers_db)[i].id );

        }
    }
}

void show_employee_array(int size, Employee *emp_db)
{
    if (emp_db != NULL)
    {
        for(int i = 0; i < size ; i++)
        {
            printf("%d Id %d Name %s age %f \n", i ,emp_db[i].id, emp_db[i].name, emp_db[i].age);
        }
    }
}


void struct_playground(void)
{
    typedef struct point1
    {
        char x;
        double y;
        char z;
    } Point1;

    typedef struct point2
    {
        char x;
        int y;
        char z;
    } Point2;

    use_struct_flexible_array(4);

    Point1 point1_1 = { 90, 90.56, 91};
    Point2 point2_1 = { 90, 90, 91};

    printf("Point1 has size %ld \n That is because the last element is aligned to the biggest data type of struct\n", sizeof(point1_1));
    printf("Point2 has size %ld \n That is because the last element is aligned to the biggest data type of struct\n", sizeof(point2_1));


    emp_t test1 = {0};

    check_size_and_offset(test1);


    Point *point_table;
    (void)define_Point_struct(&point_table);

    free(point_table);


    Employee * arrayEmp;
    int nr1 = 3;
    arrayEmp = define_employee_array(nr1);

    show_employee_array(nr1, arrayEmp);
    free(arrayEmp);

    Employee * arrayEmp2;
    int nr2 = 2;
    define_employee_array2(nr2, &arrayEmp2);

    show_employee_array(nr2, arrayEmp2);
    free(arrayEmp2);
}

void check_size_and_offset(emp_t test_struct)
{
    /* here I use a std lib approach*/
    printf("size of emp_name %ld offset %ld \n", sizeof(test_struct.emp_name), offsetof(emp_t, emp_name));
    /* here simple macro that subtracts both entities*/
    printf("size of emp_id %ld offset %ld \n", sizeof(test_struct.emp_id), OFFSET(test_struct, test_struct.emp_id));
    printf("size of age %ld offset %ld \n", sizeof(test_struct.age), OFFSET(test_struct, test_struct.age));
    printf("size of *mgr %ld offset %ld \n", sizeof(test_struct.mgr), OFFSET(test_struct, test_struct.mgr));
    printf("size of *mgr %ld offset alternative calculated %ld \n", sizeof(test_struct.mgr), OFFSET_NULL(emp_t, mgr));
    printf("size of salary %ld offset %ld \n", sizeof(test_struct.salary), OFFSET_NULL(emp_t, salary));
}

void use_struct_flexible_array( int size_of_struct)
{
    struct array_with_flexible {
        int value;
        char tab[];
        };
/*
debug this procedure
*/
    struct array_with_flexible * flex1 =  malloc( sizeof(char[size_of_struct]) + sizeof(struct array_with_flexible));    

    int i = 0;
    for( ; i < size_of_struct; i++)
    {
        flex1->tab[i] = 1 + i*2;
    }
    flex1->value = i;

    free(flex1);

    struct array_points_flexible {
        int nr;
        Point point_table[];
    };


    struct array_points_flexible * flex2 = malloc(sizeof(Point[size_of_struct]) + sizeof(struct array_points_flexible));
    i = 0 ;
    for(; i < size_of_struct; i++)
    {
        flex2->point_table[i].x = 0.1*i + 1.5 * i;
        flex2->point_table[i].y = -0.1*i + 1.5 * i;
    }
    flex2->nr = i;

    free(flex2);

}



void linked_list_init(linked_list_t ** p_list, int input_data)
{

    *p_list = calloc(1, sizeof(linked_list_t));

    (*p_list)->next_list = NULL;
    (*p_list)->data = input_data;

}

void linked_list_find_last(linked_list_t ** p_list)
{
    while((*p_list)->next_list != NULL)
    {
        *p_list = (*p_list)->next_list;
    }
}
void linked_list_add(linked_list_t * head, int input_data)
{
    /* creating new list and allocate memory to it*/
    linked_list_t * p_list = calloc(1, sizeof(linked_list_t)); 
    linked_list_t * p_list2 = head;

    linked_list_find_last(&p_list2);


    p_list2->next_list = p_list;
    p_list->next_list = NULL;
    p_list->data = input_data;
}

void linked_list_lists(linked_list_t *head)
{
    linked_list_t * list = head;

    do {

        printf("list %p data = %d\n",list, list->data);
        if (NULL == list->next_list )
        {
            break;
        }
        list = list->next_list;

    }
    while(1);
}

void linked_list_free(linked_list_t *head)
{
    linked_list_t * p_list = head;

    do {
        if (NULL == head)
        {
            break;
        }

        head = head->next_list;
        free(p_list);
        p_list = head;
    }
    while(1);

}

void init_dictionary()
{
    
}