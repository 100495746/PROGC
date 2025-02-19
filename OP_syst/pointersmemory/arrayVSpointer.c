//
// Created by Raúl Armas Seriñá on 6/5/24.
//
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int example(int* l){
    l = l+1;
    return 0;
}
int main(int argc, char *argv[]) {
    //difference between array and pointer (array vs allocating memory to pointer)


    // due to the way it is defined, the array occupies memory but can not do so dynamically
    // the size of the array has to be known at compile time, to solve that we use pointers (malloc)

    int arr[] = {1,2,3};
    //behind the scenes, the compiler reserves a block of memory of the size of the array
    //basically the same as int arr[3] = {1,2,3};

    // a pointer however, doesn't allocate memory by itself (it doesn't have a size, it's just a memory address)
    // it points to a memory address that has to be allocated by the programmer
    // of course it occupies memory, but it's just the size of the memory address 8 bytes in a 64 bit machine

    int* arrp = arr; // array pointer, points to the first element of the array,
    //it has the "ability" of converting to a pointer to the first element of the array
    int* p = malloc(3*sizeof(int)); // malloc returns a void pointer, so we have to cast it,
    // what malloc does is to reserve a block of memory of the size of the argument
    // this is useful when we don't know the size of the array at compile time
    p[0]=1;
    p[1]=2;
    p[2]=3;
    //p = p+1; // we can move the pointer to the next element of the array
    // however, I cant do this with an array, because it's a constant pointer
    printf("%p %p\n", arr, p); //prints the memory address of the first element of the array
    // pointers have a property where if we add 1 to them, they will point to the next element of the array

    // what we can do to solve the problem of the array is to use a pointer to the first element of the array
    // this way we can move the pointer to the next element of the array

    arrp = arrp + 1; // we can move the pointer to the next element of the array

    //arr decayed to a pointer, then it got passed to the function
    example(arr);
    printf("%p %p %p\n", arr, arrp, p);
    printf("%llu, %llu\n", sizeof(arr), sizeof(p)); // size of the array and pointer in bytes
    //pointers are 8 bytes.... but with our array, we have 12 bytes, because the array is 12 bytes (3 ints*4bytes)

    free(p); // we have to free the memory allocated by malloc
    return 0;
}
