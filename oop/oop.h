#ifndef  OOP_H
#define OOP_H

struct Base {
    void (*class_method)(struct Base * s);
};

typedef struct Base Base_t;

typedef struct Class_Derived1{
    Base_t base;
    int data1;
} Class_Derived1_type;

typedef struct Class_Derived2 {
    Base_t base; 
    float data_f2;
} Class_Derived2_type;



Class_Derived1_type * Class1_Construct( int a);

Class_Derived2_type * Class2_Construct( int a);

void oop_simulation(void );
#endif
