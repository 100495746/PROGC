//
// Created by Raúl Armas Seriñá on 6/5/24.
//
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char** argv)
// char** means a pointer to a pointer to a char

// memcopy does not use a buffer and memmove does use a buffer

{
    char str[] = "Start stop";
    // Destination is the same as the source [--]
    // Source is copied to a new location [] (same location)
    printf("%s\n", str);
    //memcpy(str, str+2, 3*sizeof(char));

    memmove(str, str+2, 3 * sizeof(char)); // the destination is different from the source,
    // so str is copied to a new location
    //we are moving the string 2 positions to the right
    // the destination is the same as the source, so str is converted to a pointer
    printf("%s\n", str);
    return 0;

}

