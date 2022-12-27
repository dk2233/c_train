/*


structs playing



*/
#include "structs.h"
#include <stdlib.h>
#include <stdio.h>

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


    Point1 point1_1 = { 90, 90.56, 91};
    Point2 point2_1 = { 90, 90, 91};

    printf("Point1 has size %ld \n That is because the last element is aligned to the biggest data type of struct\n", sizeof(point1_1));
    printf("Point2 has size %ld \n That is because the last element is aligned to the biggest data type of struct\n", sizeof(point2_1));

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