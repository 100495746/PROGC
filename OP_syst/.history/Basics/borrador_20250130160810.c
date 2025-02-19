#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>



int main() {
    void *ptr;
    int integer=1;
    float decimal=1.12;
    char string[6]="HELLO";

    ptr = &integer;
    printf("Integer: %d\n", *(int *)ptr);

    ptr = &decimal;
    printf("Float: %.2f\n", *(float *)ptr);
    // *(float *) float *  --> converts void pointer (void *ptr) to a float pointer (float *ptr)
    // the * left dereferences the pointer ( so it is its )

    ptr = string; //A string really is an address to its first element so no need to reference
    printf("String: %s\n", (char *)ptr);


   
    return 0;
    
}



