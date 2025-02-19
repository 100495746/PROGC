//
// Created by Raúl Armas Seriñá on 6/5/24.
//
#include <stdio.h>

int main(int argc, char* argv[])
{
    int a = 16;
    int *p = &a; // p is a pointer to an integer, it stores the address of 'a'
    // if we put p* we are dereferencing the pointer, so we are accessing the value of 'a'
    //p =  17; // this also dereferences the pointer (probably invalid address)
    printf("p: %d\n", p); // this is the address inside our memory of variable 'a'
    //if we want the value of 'a' we need to dereference the pointer
    printf("*p: %d\n", *p); // this is the value of a
    //now lets use some arrays...
    int arr[10] = {5,13,22};
    printf("arr[1]:  %d\n", arr[1]); //13, this usually "decays" into a pointer to the first element
    //of the array
    // we can use pointers to access the elements of the array by adding an offset


    printf("*(arr+1): %d\n", *(arr+1)); //13 (arr+1) is the address of the second element of the array
    //we dereference the pointer to get the value of the second element
    //arr+1->**address** of the second element
    //*(arr+1)->**value** of the second element

    //but we still get 13...so what is the difference between arr[1] and *(arr+1)?
    //arr[1] is the same as *(arr+1) because the array decays into a pointer to the first element
    printf("1[arr]: %d\n", 1[arr]);// it is equivalent to 1+arr, so it is the same as *(arr+1)

    return 0;

}