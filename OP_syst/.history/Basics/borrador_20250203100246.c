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
    if(fopen(name,  "r")== NULL){
        printf("File not found");

    } // open file with name "name" in read mode ("r")

    fclose()


    }
   