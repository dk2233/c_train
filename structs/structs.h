
typedef struct {
int x;
int y;
} Point;

typedef struct employee {
    char name[10];
    float age;
    int id;
} Employee;

extern int define_Point_struct(
    Point ** points_array);


extern Employee * define_employee_array(int elements);

extern void  define_employee_array2(int elements, Employee **employers_db);

extern void show_employee_array(int size, Employee *emp_db);

extern void struct_playground(void);