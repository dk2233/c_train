#ifndef STRUCT_H
#define STRUCT_H

typedef struct {
int x;
int y;
} Point;

typedef struct employee {
    char name[10];
    float age;
    int id;
} Employee;

typedef struct emp_ {
    char emp_name[30];
    unsigned int emp_id;
    unsigned int age;
    struct emp_ *mgr;
    float salary;
} emp_t;

typedef struct _linked_list
{
    struct _linked_list * next_list;
    // linked_list_t * prev_list;
    int data;

} linked_list_t;


extern void check_size_and_offset(emp_t test_struct);

extern Employee * define_employee_array(int elements);

extern void  define_employee_array2(int elements, Employee **employers_db);

extern void show_employee_array(int size, Employee *emp_db);

extern void struct_playground(void);

extern void use_struct_flexible_array( int size_of_struct);

extern int define_Point_struct(Point ** points_array);

extern void linked_list_init(linked_list_t ** p_list, int input_data);

extern void linked_list_add(linked_list_t * head, int input_data);

extern void linked_list_lists(linked_list_t *head);

extern void linked_list_free(linked_list_t *head);

extern void linked_list_find_last(linked_list_t ** p_list);

#endif