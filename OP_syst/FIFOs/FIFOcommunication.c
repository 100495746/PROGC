//
// Created by Raúl Armas Seriñá on 13/3/24.
//
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <errno.h>
#include <fcntl.h>

// we will generate two programs one which generates numbers and another one that
// reads them and prints a sum


int main(int argc, char* argv[]){
    int elems = 5;
    int arr[elems];
    srand(time(NULL));
    int i;
    for (i = 0; i < 5; i++) {
        arr[i] = rand() % 10;
        printf("Generated %d\n", arr[i]);
    }
    // We open the FIFO file
    int fd = open("sum", O_WRONLY);
    if (fd == -1){
        printf("open failed");
        return 1;
        // we do this to check for errors (it saves a lot of debugging time)
    }

    // If we get here in the execution this means that we have also opened the
    // fifo file for reading from another process

    /*
    for (i = 0; i < 5; i ++){
        if (write(fd, &arr[i], sizeof(int)) == -1){
            printf("failed write");
            return 2;
        }
        // we print this as we go on writing values of the array into the FIFO
        printf("Wrote %d\n", arr[i]);
    }
    A for loop is inefficient, and we could try to print the full array at once*/
    if (write(fd, arr, sizeof(int) * elems) == -1){
        return 2;
    }
    close(fd);

    fd = open("sum", O_RDONLY);
    if (fd == -1){
        printf("open failed");
        return 1;
        // we do this to check for errors (it saves a lot of debugging time)
    }
    int sum;
    // in read arguments (x, y, z)
    if (read(fd, &sum, sizeof(int))==-1){
        printf("Error reading sum");
        return 2;
    } else{
        printf("read, result of sum: %d\n", sum);
    }
    close(fd);


    return 0;
}
