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
    printf("Integer: %d\n", ptr);

    ptr = &decimal;
    printf("Float: %d", ptr);

    ptr = &string;
    printf("Char: %d", ptr);


   
    return 0;
    
}



