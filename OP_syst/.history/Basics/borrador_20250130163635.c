#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>
#include <stdlib.h> // Required for malloc()

int main() {
    int *ptr = (int *)malloc(sizeof(int)); // Allocates memory for one integer
    // declare in pointer int *ptr;
    // (int *) --> malloc returns a void pointer, so we convert it into the type we want
    // malloc allocates an specific number of bytes in memory and returns pointer to the beggining of the block
    // !!! we dont put int *ptr = (int *)malloc(sizeof(int)
    if (ptr == NULL) { // Check if allocation was successful
        printf("Memory allocation failed!\n");
        return 1;
    }

    *ptr = 42; // Assign a value
    printf("Value stored: %d\n", *ptr);

    free(ptr); // Free the allocated memory
    return 0;
}



