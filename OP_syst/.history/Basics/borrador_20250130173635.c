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
    if (ptr == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }
    for (int i=0; i<quantity; ++i){
    char *char_ptr = (char *)malloc(quantity * sizeof(char));
    if (char_ptr == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        free(ptr);
        return 1;
    }
        scanf("%d", &ptr[i]);
    };

    char *char_ptr = (char *)malloc(quantity * sizeof(char));
        char *temp_ptr = (char *)realloc(char_ptr, space);
        if (temp_ptr == NULL) {
            printf("Memory reallocation failed\n");
            free(char_ptr);
            free(ptr);
            return 1;
        char temp[20]; // temporary buffer to hold the string representation of the number
        sprintf(temp, "%d", ptr[i]);
        strcat(char_ptr, temp);
        char_ptr = temp_ptr;
    int buffer;
    for (int i=0; i<quantity; ++i){
        buffer= digit_counter(ptr[i])*sizeof(char);
        space = space + buffer;
        char_ptr = (char *)realloc(char_ptr, space);
        sprintf(buffer, "%d", ptr[i]);
        strcat(char_ptr, buffer);

    }
    printf("Stored values: %s", char_ptr);


    return 0;
}



