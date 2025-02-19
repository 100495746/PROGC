//
// Created by Raúl Armas Seriñá on 6/5/24.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


//operations with memory, memory manipulation/comparison functions

int main(int argc, char *argv[]){
    //////////////FIRST FUNCTION/////////////////////
    //memcmp compares two memory blocks, byte by byte
    printf("MEMCMP\n");
    int arr_a[] = {1,2}; //0001  0002
    short int arr_b[] = {1,2};//01 02
     // if we have to compare two different types of arrays, we have to pass the size of the shorter array
    //memcmp compares two memory blocks, byte by byte
    if (memcmp(arr_a, arr_b, 2 * sizeof(short int))==0)
        // the third argument tells how much memory to compare
        //compares two arrays, takes void pointers
        //returns 0 if they are equal
        //returns a number different from 0 if they are different
    {
        printf("Arrays are equal\n");
    } else {
        printf("Arrays are different\n");
    }
        // even though the arrays have the same values,
        // they are different because they are different types (the size of the elements is different)
        // so the comparison would be like: 0001 != 0102

    //////////////NEXT FUNCTION/////////////////////
    //memcopy copies memory from one location to another, faster than a loop
    printf("MEMCPY\n");
    int arr1[] = {3,4};
    int arr2[] = {1,2};
    memcpy(arr1, arr2, 2 * sizeof(int)); //1º destination, 2º source, 3º size, returns destination
    //copies the memory of arr2 to arr1, a total of 2* sizeof(int) bytes= 8 bytes = 2 elements
    printf("%d %d\n", arr1[0], arr1[1]); //prints 1 2

    //////////////NEXT FUNCTION/////////////////////
    //memset sets a block of memory to a certain value
    printf("MEMSET\n");
    int arr3[] = {3,4};
    int arr4[] = {1,2};
    memset(arr3, 1, 2 * sizeof(int)); //1º destination, 2º value, 3º size
    //instead of setting every element to 1, it sets every byte to 1, getting a weird number
    //hexadecimal representation of 1 is 01, we get 01010101 (4 elements all set to 1; 1 = 0001binary-> 01hexadecimal)
    //sets the memory of arr3 to 1, a total of 2* sizeof(int) bytes= 8 bytes = 2 elements

    printf("%d %d\n", arr3[0], arr3[1]); //we get a weird number-> it sets every byte to 1


    //////////////NEXT FUNCTION/////////////////////
    //memchr searches for a character in a block of memory, similar to strchr which searches for a character in a string
    printf("MEMCHR\n");
    //returns a pointer to the first occurrence of the character in the block of memory
    int arr5[] = {3,4}; // 0003 0004
    int arr6[] = {1,2}; // 0001 0002
    memchr(arr5, 0, 2 * sizeof(int)); //1º block of memory, 2º character to find, 3º size of search block
    if (memchr(arr5, 0, 2 * sizeof(int))!=NULL){
        printf("Byte found\n");

    } else{
        printf("Byte not found\n");
        //NULL means that the character was not found


    };
    return 0;
}