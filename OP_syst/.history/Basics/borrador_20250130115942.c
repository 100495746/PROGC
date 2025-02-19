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
    int x[5] = {1, 2, 3, 4, 5};
    int *ptr = &x;
    for (int i=0; i<sizeof(x); i+=sizeof(int)){
        printf("Value at ptr:");
    }
    return 0;
    
}


