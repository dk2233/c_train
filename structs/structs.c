/*


structs playing



*/
#include "structs.h"
#include <stdlib.h>
#include <stdio.h>


void define_Point_struct(
    void
    )
{
    int nr_elements = 0;

    printf("give nr of elements \n");
    scanf("%d",&nr_elements);

    Point * points_array = malloc(sizeof(Point) * nr_elements);

    if (points_array != NULL)
    {
        for (int i = 0; i < nr_elements; i++)
        {
            printf("give x and y for %d element\n", i);
            scanf("%d", &points_array[i].x);
            scanf("%d", &points_array[i].y);
        }

        for (int i = 0; i < nr_elements; i++)
        {
            printf("point %d %d \n", points_array[i].x, points_array[i].y);
        }
    }
}


Employee * define_employee_array(int elements)
{
    Employee * employers_db = malloc(sizeof(Employee) * elements);

    if (employers_db != NULL)
    {
        for(int i = 0; i < elements; i++)
        {
            printf("give employee name max 10 letters \n");
            scanf("%s", &employers_db[i].name );
            printf("give employee age  \n");
            scanf("%f", &employers_db[i].age );
            printf("give employee id \n");
            scanf("%d", &employers_db[i].id );

        }
    }
    return employers_db;
}

void  define_employee_array2(int elements, Employee **employers_db)
{
     *employers_db = malloc(sizeof(Employee) * elements);

    if (*employers_db != NULL)
    {
        for(int i = 0; i < elements; i++)
        {
            printf("give employee name max 10 letters \n");
            scanf("%s", &(*employers_db)[i].name );
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