#include "oop.h"
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>


void get_class1_data(Base_t *base){

    Class_Derived1_type *cl1 =  (Class_Derived1_type *) base;

    printf("Class 1 data is %d \n " , cl1->data1);
}

void get_class2_data(Base_t *base){

    Class_Derived2_type *cl2 =  (Class_Derived2_type *) base;

    printf("Class 2 data is double %f \n " , cl2->data_f2);
}

Class_Derived1_type * Class1_Construct( int a)
{
    Class_Derived1_type * ptr = malloc(sizeof(Class_Derived1_type));
    if (ptr == NULL) return NULL;
    ptr->data1 = a;
    ptr->base.class_method = get_class1_data;

    return ptr;
}

Class_Derived2_type * Class2_Construct( int a)
{
    Class_Derived2_type * ptr = malloc(sizeof(Class_Derived2_type));
    if (ptr == NULL) return NULL;
    ptr->data_f2 = a;
    ptr->base.class_method = get_class2_data;

    return ptr;
}

void oop_simulation(void )
{

    Class_Derived1_type cl1 = {} ;

    cl1.data1 = 50;
    cl1.base.class_method = get_class1_data;


    Class_Derived2_type cl2 = {};

    cl2.data_f2 = 7.8;
    cl2.base.class_method = get_class2_data;

    Base_t * classes[3] = {(Base_t * )&cl1, (Base_t *)&cl2, NULL};

    Class_Derived1_type *cl1_a = Class1_Construct( 20);

    classes[2] = (Base_t*)cl1_a;

    for(size_t i = 0 ; i < 3 ; i++)
    {
        classes[i]->class_method(classes[i]);

    }

    free(cl1_a);

}

