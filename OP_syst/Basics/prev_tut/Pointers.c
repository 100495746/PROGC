//
// Created by Raúl Armas Seriñá on 5/2/24.
//
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main() {
    // pointers are basically just a memory address in RAM, we can think of them as a type of data that we can work with
    // in our programs (instead of being an int, float... etc. It is just a memory address)
    int age = 30; // this will get stored in the RAM of our computer at a specific address
    double gpa = 3.4;
    char grade = 'A';
    // just as we stored ints, chars... into different variables, we could do so with pointers
    // we don't know the number of an specific address, so to create a pointer variable we want to store the memory addr
    // of a variable.
    int *pAge = &age;// we set it to the address of Age
    double *pGpa = &gpa;
    char *pGrade = &grade; // we have set pointer variables, we put the 'Type' of the original variable

    printf("age memory address: %p\n", &age); //&age is a pointer, it is basically the address of the variable "age"
    //%p is for pointers, we tell printf to print a pointer (a physical memory address)
    // with '&' we are able to access pointers for different variables
    // int age = 30;-> We have an integer variable and this int var stores an int val of 30


    return 0;
}