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
    unsigned long space = 0;
    int *ptr= (int *)malloc(quantity*sizeof(int));

    //checker
    if (ptr == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }
    for (int i=0; i<quantity; ++i){
        printf("Enter element at %d\n", i);
         scanf("%d", &ptr[i]);


    };



    char *char_ptr = (char *)malloc(1);
    if (char_ptr == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        free(ptr);
        return 1;
    }

    char_ptr[0] = '\0';
    for (int i = 0; i < quantity; ++i) {
        int buffer = digit_counter(ptr[i]) + 1; // +1 for null terminator
        space = space + buffer + sizeof(", ");
        char_ptr = (char *)realloc(char_ptr, space);

        if (char_ptr == NULL) {
            fprintf(stderr, "Memory reallocation failed\n");
            free(ptr);
            return 1;
        }

        char temp[buffer];
        sprintf(temp, "%d", ptr[i]);
        strcat(temp, "");
        strcat(char_ptr, temp);
        
    }
    printf("Stored values: %s", char_ptr);
    free(char_ptr);


    }
   