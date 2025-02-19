#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>

struct Student
{
    char name[15];
    float grade;
};

void gradechange(struct Student *stdt, float newgrade){
    stdt->grade = newgrade;
    return;

}

int main() {
     struct Student student1;
     student1.grade = 8.5;
     strcpy(student1.name, "John");
     gradechange(&student1, 9.2);



   
    return 0;
    
}



