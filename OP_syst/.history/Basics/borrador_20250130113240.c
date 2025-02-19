#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>

struct Student{
    char name[50];
    int age;
    float grade;
};

int main() {
    int x =10;
    int *p = &x;
    printf("Address of x: %p\n", p);
    printf("Value of x using pointer: %d", *p);
    *p = *p +10;
    printf("Modified value of x through pointer: %d")
    return 0;
    
}


