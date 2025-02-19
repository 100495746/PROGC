//
// Created by Raúl Armas Seriñá on 6/5/24.
//
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


//declaring pointers etc
int main(int argc, char *argv[]){
    int* p; // also int *p; or int * p;
    int* p2, p3; // p2 is a pointer, p3 is an int, to solve this: int *p2, *p3;

    // another issue is dealing both pointers and array in the same line
    char* str[20]; // array of 20 pointers to char, the brackets
    // are whatever the type is, in this case, declared as pointers
    printf("%llu\n", sizeof(str)); // size of the array in bytes
    return 0;
}