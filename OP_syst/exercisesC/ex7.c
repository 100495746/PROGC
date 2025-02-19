//
// Created by Raúl Armas Seriñá on 17/3/24.
//
#include <stdlib.h>
#include <stdio.h>
float sum(float* num1, float* num2){
    return (*num1 + *num2);
}
int main(){
    float num1, num2;
    float result;
    printf("Enter number1: ");
    scanf("%f", &num1);
    printf("Enter number 2: ");
    scanf("%f", &num2);
    result = sum(&num1, &num2);
    printf("The result is: %.3f", result);
    return 0;
}