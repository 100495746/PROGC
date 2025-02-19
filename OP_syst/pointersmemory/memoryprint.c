//
// Created by Raúl Armas Seriñá on 6/5/24.
//
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//print byte by byte the memory from a struct

typedef struct{
    int test; //4 bytes
    char k; //1 byte
    char str[10]; //10 bytes
    int* p; //8 bytes
    short sh; //2 bytes
    //25 bytes total
} Thing;

int main(int argc, char *argv[]){
    int i;
    Thing t = {12, 'k', "testing", &i, 256};
    printf("sizeof t: %llu", sizeof(t)); // sizeof returns an unsigned integer
    unsigned char data;
    printf("\n");
    for(i = 0; i < sizeof(t); i++){
        if (i %4==0){
            printf("\n");
        }
        data = *(((unsigned char*)&t)+i);
        printf("%02x ", data);
        // the sum to pointer is the same as the sum to the address
        // it is the same as t + i, it would be the same as t[i]
        //we had to cast to unsigned char because we want to print the byte in hexadecimal
        // *(((unsigned char*)&t)+i) means dereference t, cast it to unsigned char, add i to the address
        //printf("%02x ", ((char*)&t)[i]); // we print in hexadecimal

        // we will be getting the memory inside t (as it is allocated and how it works
        // the first line is the address of the first byte of the struct (test)
        // the system is little-endian (the least significant byte is stored first)
        // so 0c00 00 00 is 12 (big endian would be 00 00 00 0c)
        // it is 12 because test = 12
        // we have the next line, which is the address of the second byte of the struct (k) 6b (k in ascii)
        // then we have the address of the third byte of the struct (str) 74 (t in ascii)
        // then we have the address of the fourth byte of the struct (str) 65 (e in ascii)
        // and so on...
        // we get null terminators because the string is null terminated
        // then we have the address of i (&i) 34 35 66 6b
        // then th short sh 00 01-> little-endian (01 00)=> 1 * 16^2 = 256
        // then 256 is 00 00 01 00
        // we still have some extra 0's but it is just the compiler adding padding to the struct

    }
    printf("\n\n");
    for(i = 0; i < sizeof(t); i++) {
        if (i % 4 == 0) {
            printf("\n");
        }
        data = *(((unsigned char *) &t) + i);
        printf("%c ", data); // we print in decimal
    }
    return 0;
}