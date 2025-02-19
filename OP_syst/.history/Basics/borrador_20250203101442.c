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
    //the pointer points to an address, so without the "*" it gives whatever is stored at the address
    if(file== NULL){
        printf("File not found");

    } // open file with name "name" in read mode ("r")


    //!!! pointers--> & "address of" operator
    // pointer declaration---> int x = 10; int *ptr = &x;. ptr now holds the address of x
    // dereference: *---> gives access to the value stored in the address pointed by the pointer: ex int value= *ptr -->(*ptr=5; ptr= 0x002A554122... (address))

    fclose(file);


    }
   