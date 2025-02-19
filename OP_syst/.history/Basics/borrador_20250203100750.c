#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>
#include <stdlib.h> // Required for malloc()



int main() {
    char name[20];
    printf("Enter file name: ");
    scanf("%s", name);
    FILE *file = fopen(name, "r");
    //the pointer points to address, so without the "*" it gives whatever is stored at the address
    if(file== NULL){
        printf("File not found");

    } // open file with name "name" in read mode ("r")

    fclose(file);


    }
   