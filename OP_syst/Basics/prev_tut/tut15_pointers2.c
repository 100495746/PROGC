//
// Created by Raúl Armas Seriñá on 5/2/24.
//
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

// dereferencing pointers
int main() {
    int age = 30; // this will get stored in the RAM of our computer at a specific address
    int *pAge = &age;// we set it to the address of Age
    // with pointers, essentially we are going to the memory address of a pointer and grabbing the piece of
    // info from there. When we dereference a pointer, we go to that address and get the info (value) stored inside,
    printf("%p", pAge); // prints address ( like &age)

    printf("%d", *pAge); // this basically 'dereferences' pAge (converts it into the int value that was at the address
    // (pAge holds no longer an address)

    printf("%d", *&age); // *& will dereference the entire thing,


    printf("%d", *&*&age); // basically, & gives an address, and * gives the value stored there



    return 0;
}