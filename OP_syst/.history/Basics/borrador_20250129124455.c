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

    struct Student students[3];
    
    
    for (int i=0; i<3; ++i ){
        printf("Student %d\n", i+1);
        printf("Enter student name: ");
        scanf("%50s", students[i].name);
        
        printf("Enter student age: ");
        scanf("%d", &students[i].age);
        
        printf("Enter student grade: ");
        scanf("%f", &students[i].grade);
        }
     
    for (int i=0; i<3; ++i){
        printf("Student details: \nName: %s\nAge: %d\nGrade: %.2f\n", students[i].name, students[i].age, students[i].grade);
    }
    return 0;
  
}


