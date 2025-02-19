#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>
#include <stdlib.h> // Required for malloc()

int digit_counter(int num){
    int digits=0;
    do{
        digits++;
    }while(abs(num)/10>=1);

    return digits;

}



int main() {
    int quantity;
    printf("Enter the number of elements: ");
    scanf("%d", quantity);
    unsigned long space;
    int *ptr= (int *)malloc(quantity*sizeof(int));
    for (int i=0; i<quantity; ++i){
        printf("Enter the element in position %d: ", i);
        scanf("%d", ptr[i]);
    };
        arr = (int *)realloc(arr, 10 * sizeof(int)); // Expands array to hold 10 integers

    char *char_ptr = (char *)malloc(quantity * sizeof(char));
    space=0;
    for (int i=0; i<quantity; ++i){
        space = space +digit_counter(ptr[i])*sizeof(char)
        char_ptr = (char *)realloc(char_ptr, digit_counter(ptr[i])*sizeof(char));
        char_ptr


        

    }
    printf("Stored values: %s");


    return 0;
}



