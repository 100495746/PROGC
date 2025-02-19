//
// Created by Raúl Armas Seriñá on 6/2/24.
//
#include <stdio.h>
#include <stdlib.h>

int main() {

    char name[22];

    //we first declare the variable type, then the name of the var
    //The '[]' basically tells c that there are going to be several chars inside the var.
    printf("Enter your name: ");
    scanf("%s", &name);
    printf("\nHello, %s", name); // always end an instruction with ';'

    return 0;
}ok