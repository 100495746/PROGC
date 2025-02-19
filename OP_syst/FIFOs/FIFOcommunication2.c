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
    int arr[5];
    int i;
    int fd = open("sum", O_RDONLY);
    if (fd == -1){
        return 1;
    }
    /*We can make it faster (reading the full array at once
    int i;
    for (i=0; i < 5; i++){
        if (read(fd,&arr[i], sizeof(int)) == -1){
            // if some value gives error
            printf("Error reading value in position %d of the array", i);
            return 2;
        }
        //We print this as we go on reading the fifo file (when the other program writesa new value,
        //we are able to read it)
        printf("Received %d\n", arr[i]);
    }
    // we can leave it like this as if we do 5 reads of 1 int or 1 read of 5 int,
    // technically is the same
    */
    if (read(fd,arr, sizeof(int) * 5) == -1){
        printf("Error in reading");
        return 2;
    }
    close(fd);
    // we close the file once everything has been read/written
    // build the program before you run it
    int sum = 0;
    for (i = 0; i < 5; i++){
        sum += arr[i];
    }
    printf("Sum is %d\n", sum);
    // Now try to send the sum back to FIFO program1
    fd = open("sum", O_WRONLY);
    if (fd == -1){
        printf("Write failed");
        return 2;
    }

    if (write(fd, &sum, sizeof(int)) == -1){
        printf("Error writing");
        return 2;
    } else{
        printf("written");
    }

    close(fd);

    return 0;
}