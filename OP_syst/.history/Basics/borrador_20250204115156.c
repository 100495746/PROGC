#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Student{
    char name[20];
    int age;
    float grade;
};

int main() {
    int number;
    fprint("Enter number of students: ");
    scanf("%d", number);

    for (int i=1; i<=number; ++i){
        struct Student student1;
        fprint("Enter details of student %d", i);
        fprint("Name: ");
        scanf("%c",)
    }
    
    

    return 0;
}