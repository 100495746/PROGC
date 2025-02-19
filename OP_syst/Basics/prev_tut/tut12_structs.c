//
// Created by Raúl Armas Seriñá on 5/2/24.
//
// inside a struct, we can store several different types of vars inside it

#include <stdlib.h>
#include <printf.h>
#include <string.h>

struct Student {
    char name[50];
    char major[50];
    int age;
    double gpa;
    // we basically created a new datatype "student" with several attributes
};


int main() {
    struct Student student1;// we create a container and give it a name (like an array)
    student1.age = 22; // we access the containers attributes with container.attribute
    student1.gpa = 3.2;
    strcpy(student1.name, "Jim");// first param is the destination, second param is the value
    strcpy(student1.major, "Business");

    struct Student student2;// we create a container and give it a name (like an array)
    student1.age = 20; // we access the containers attributes with container.attribute
    student1.gpa = 2.5;
    strcpy(student1.name, "Pam");// first param is the destination, second param is the value
    strcpy(student1.major, "Art");

    printf("%s", student1.name);
    printf("%s", student2.name);


    return 0;
}