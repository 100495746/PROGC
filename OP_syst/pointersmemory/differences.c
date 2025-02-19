//
// Created by Raúl Armas Seriñá on 6/5/24.
//
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char *argv[]){
    int a = 5;
    //size_t is an unsigned integer type of at least 16 bit (llu or zu)
    int arr[10]= {3,9,10}; //->int*
    int* arrp = arr; //array pointer, points to the first element of the array
    //a pointer is a variable that stores the memory address of another variable
    // in this case its size is 8 bytes (64 bit machine)
    printf("Number of elems in array: %llu\n", sizeof(arr)/sizeof(int));  //number of elems
    printf("Size of array: %llu\n", sizeof(arr)); //size of the array in bytes
    printf("Size of pointer to array: %llu\n", sizeof(arrp)); //size of the pointer in bytes
    printf("Size of int: %llu\n", sizeof(sizeof(int))); //size of an int in bytes
    return 0;

}
