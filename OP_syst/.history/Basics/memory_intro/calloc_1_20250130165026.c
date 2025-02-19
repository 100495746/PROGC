//calloc(n, size) allocates memory and initializes all values to 0.
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>
#include <stdlib.h> // Required for malloc()

int main() {
    int *arr = (int *)calloc(5, sizeof(int)); // Allocates space for 5 integers (all initialized to 0)
    // meanwhile, malloc does NOT initiallize all values to 0
}
