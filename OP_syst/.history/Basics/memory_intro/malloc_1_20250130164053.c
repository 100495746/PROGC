#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>
#include <stdlib.h> // Required for malloc()
/* 


 */
int main() {
    int *ptr = (int *)malloc(sizeof(int)); // Allocates memory for one integer
    // declare in pointer int *ptr;
    // (int *) --> malloc returns a void pointer, so we convert it into the type we want
    // malloc allocates an specific number of bytes in memory and returns pointer to the beggining of the block
    // !!! we dont put int *ptr = &(int *)malloc(sizeof(int));, as malloc already returns an address
    if (ptr == NULL) { // Check if allocation was successful
        printf("Memory allocation failed!\n");
        return 1;
    }

    *ptr = 42; // Assign a value (dereferenced pointer)
    printf("Value stored: %d\n", *ptr);

    free(ptr); // Free the allocated memory (avoid memory leaks, use  free once we finish using the variable)
    return 0;
}