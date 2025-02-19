//
// Created by Raúl Armas Seriñá on 5/2/24.
//
#include <stdio.h>
#include <stdlib.h>

void sayHi();

int main() {
    printf("Top");
    sayHi("Tom", 23); // We call the function
    printf("bottom");
    return 0;
}

void sayHi(char name[], int age) {
    printf("Hello %s you are %d\n", name, age);
    // we first tell what type the function will return,
    // void if it returns nothing
    //we tell the functions arguments
}


