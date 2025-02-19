
//
// Created by Raúl Armas Seriñá on 11/3/24.
//
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <sys/wait.h>
#include <errno.h>
int main(int argc, char* argv[]){
    int fd[2]; //array of two ints;
    //  A pipe has two ends, fd[0]-read; fd[1]-write
    //  We can only write to one end and read from the other
    if (pipe(fd) == -1){
        printf("An error ocurred opening the pipe\n");
        return 1;

    }; //pipe takes two int arguments, which are "keys" to access a determined file
    //If we want something to be sent to a process after forking we can use pipe
    // Pipe is basically an "in memory file", a file which only has a buffer in memory
    //where you can read or write
    int id = fork();
    if (id == -1){
        printf("An error occurred when forking\n");
        return 2;
    }
    if (id == 0){
        close(fd[0]); // this is standard, usually when we open a pipe (read/write) we close one end,
        // we process the other end (write/read) and then we close it too, we close them once we have read/written
        // x->fd[0]; y->fd[1] (x is the parent, y is the child)(x is the read end, y is the write end)
        int x;
        printf("Input a number: ");
        scanf("%d", &x);
        if (write(fd[1], &x, sizeof(int)) == -1){
            printf("An error ocurred writing to the pipe\n");
            return 2;
        } //&x is the address where we want to write (we reserve a size)
        close(fd[1]); // This "tells" that the file is closed and there is nothing more to read-write from it
    } else{
        close(fd[1]);
        int y;
        if(read(fd[0], &y, sizeof(int))==-1){
            printf("An error occurred reading from the pipe\n");
            return 3;
        } //&y is the address where we want to read
        y = y *3;
        close(fd[0]);
        printf("Got from child process: %d\n", y);
    }
    // when we fork, the file descriptors (fd) get copied over and also, these fd are assigned
    // to the newly created process (they are inherited); This means if we close a fd in a process, that
    // same fd is still opened in the other process (they are independent of each other)
    return 0;
}
