//
// Created by Raúl Armas Seriñá on 5/2/24.
//
#include <stdio.h>

double cube(double num) {
    double result = num * num * num;
    return result;

}


int main() {

    printf("Answer: %f", cube(3.0));
    return 0;

}
