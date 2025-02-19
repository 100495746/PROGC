#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>
#include <stdlib.h> // Required for malloc()

int main() {
    int quantity;
    printf("Enter the number of elements: ");
    scanf("%d", quantity);
    int *ptr= (int *)malloc(quantity*sizeof(int));
    for (int i=0; i<quantity; ++i){
        printf("Enter the element: ");
        scanf("%d", ptr[i]);
        
    }


    return 0;
}



