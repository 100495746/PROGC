#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>

int main() {
    int numbers[5], sum=0;
    printf("Enter 5 numbers: ");
    for (int i =0; i<sizeof(numbers)/size; ++i){
        printf("Number %d: ", i+1);
        scanf("%d", numbers[i]);
    }
     for (int i =0; i<=sizeof(numbers)/sizeof(int); ++i){
        sum = sum + numbers[i];
    }

}