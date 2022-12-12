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
