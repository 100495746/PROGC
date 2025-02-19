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
    scanf("%d", &quantity);
    unsigned long space;
    int *ptr= (int *)malloc(quantity*sizeof(int));
    for (int i=0; i<quantity; ++i){
        printf("Enter the element in position %d: ", i);
        scanf("%d", &ptr[i]);
    };

    char *char_ptr = (char *)malloc(quantity * sizeof(char));
    space=0;
    int buffer;
    for (int i=0; i<quantity; ++i){
        buffer= digit_counter(ptr[i])*sizeof(char);
        space = space + buffer;
        char_ptr = (char *)realloc(char_ptr, space);
        sprintf(digit_counter(ptr[i])*sizeof(char), "%d", ptr[i]);
        strcat(char_ptr, (char)ptr[i]);

    }
    printf("Stored values: %s", char_ptr);


    return 0;
}



