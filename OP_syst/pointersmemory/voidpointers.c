//
// Created by Raúl Armas Seriñá on 6/5/24.
//
# include <stdio.h>
# include <stdlib.h>
# include <string.h>


//we want this function to print any type ,as bytes, of array
//for this, we use void pointers, as they point to any type, but we have to cast them
void printBytes(void* arr, int n){
    for(int i = 0; i < n; i++){

        //arr[i] is dereferencing a void pointer, which is not allowed
        //if we are printing 1 sinkle byte, it means we are printing 2 base 16 digits
        printf("%02x ", ((char*)arr)[i]); //prints each elem of the array in hexadecimal
        //%x->hexadecimal; 8->8 digits (8 characters); 0->fill with 0s empty spaces
        // we put  %02x because the size of a byte is 8 bits, so we need 2 base 16 digits to represent it
    }
}

int main(int argc, char *argv[]){
    long long arr[]= {1,2,3,4,5}; // 32 bytes, we need to send 32 bytes  to printBytes
    printBytes(arr, 4 * sizeof(long long)); // 4 * sizeof(long long) = 32 bytes (long = 4; long long = 8)
    return 0;
}