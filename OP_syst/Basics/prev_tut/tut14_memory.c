//
// Created by Raúl Armas Seriñá on 5/2/24.
//
#include <stdlib.h>
#include <printf.h>
#include <string.h>


int main() {

    int age = 30; // this will get stored in the RAM of our computer at a specific address
    double gpa = 3.4; // we access vars by their names, but c accesses these values through their addresses
    char grade = 'A';

    printf("age: %p\ngpa: %p\ngrade: %p", &age, &gpa, &grade); // this prints the memory address of the variable
    // these addreses



    return 0;
}