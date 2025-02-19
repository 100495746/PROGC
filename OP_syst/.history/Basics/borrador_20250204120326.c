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

    struct Student student[number];

    for (int i=0; i<number; ++i){
        fprint("Enter details of student %d", i+1);
        fprint("Name: ");
        scanf("%c", student[i].name);
        fprint("Age: ");
        scanf("%d", student[i].age);
        fprint("Grade: ");
        scanf("%f", student[i].name);
    }
    
    FILE *file = fopen("fichero2", "w");
    fwrite(student, number*sizeof(struct Student), number ,file);
    
    

    return 0;
}