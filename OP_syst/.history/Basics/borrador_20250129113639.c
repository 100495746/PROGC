#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>

int sum(a,b){
    
}

int main() {
    int numbers[2];
    printf("Enter 2 numbers:\n");
    for (int i =0; i<sizeof(numbers)/sizeof(int); ++i){
        printf("Number %d: ", i+1);
        scanf("%d", &numbers[i]);
    }
    printf("The sum is: %d \n", sum);
    return 0;
}

