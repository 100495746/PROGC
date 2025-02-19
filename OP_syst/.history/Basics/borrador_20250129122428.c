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
    struct Student st1;
    {
        /* data */
    };
    
    for (int i=0; i<3; ++i ){
        switch(i){
            case 0:
                printf("Enter student name: ");
                scanf("%50s", st1.name);
                break;
             case 1:
                printf("Enter student age: ");
                scanf("%d", &st1.age);
                break;
             case 2:
                printf("Enter student grade: ");
                scanf("%f", &st1.grade);
                break;
        }
     
    }

    printf("Student details: \nName: %s\n Age: %d\n Grade: %.2f\n", st1.name, st1.age, st1.grade);
    return 0;
  
}

