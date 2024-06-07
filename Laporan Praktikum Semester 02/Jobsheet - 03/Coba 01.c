#include <stdio.h>
#include <stdlib.h>

typedef struct employee_st {
    char name[40];
    int id;
} Employee; 

int main() { 
    int myInt;
    Employee john; 
    
    printf("Size of int is %lu bytes\n", sizeof(myInt)); 
    printf("Size of Employee is %lu bytes\n", sizeof(Employee)); 
    printf("Size of john is %lu bytes\n", sizeof(john)); 
    printf("Size of char is %lu byte\n", sizeof(char)); 
    printf("Size of short is %lu bytes\n", sizeof(short)); 
    printf("Size of int is %lu bytes\n", sizeof(int)); 
    printf("Size of long is %lu bytes\n", sizeof(long)); 
    printf("Size of float is %lu bytes\n", sizeof(float)); 
    printf("Size of double is %lu bytes\n", sizeof(double)); 
    
    return 0;
}
