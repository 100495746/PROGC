#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>

swap(int *a, int*b)

int main() {
    int x[5] = {1, 2, 3, 4, 5};
    int *ptr = x;
    for (int i=0; i<sizeof(x)/sizeof(int); ++i){
        printf("Value at ptr: %d\n", x[i]);
        printf("Value at ptr: %d\n", *(x+i));
        ptr++; // Do this to traverse... no need to add the size directly
    }
    return 0;
    
}


