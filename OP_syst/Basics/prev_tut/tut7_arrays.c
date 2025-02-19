//
// Created by Raúl Armas Seriñá on 5/2/24.
//
#include <stdio.h>

int main() {
    int luckyNumbers[] = {4, 8, 15, 16, 23, 42}; // this is an array
    luckyNumbers[1] = 200; // this modifies the arrays content located in position 1
    printf("%d", luckyNumbers[1]);

    char phrase[] = "Array";
    printf("%c", phrase[0]);
    return 0;
}