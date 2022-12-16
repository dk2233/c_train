
typedef struct {
int x;
int y;
} Point;

typedef struct employee {
    char name[10];
    float age;
    int id;
} Employee;

extern  void define_Point_struct(void );

extern Employee * define_employee_array(int elements);

extern void  define_employee_array2(int elements, Employee **employers_db);

extern void show_employee_array(int size, Employee *emp_db);